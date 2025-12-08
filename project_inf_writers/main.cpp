#include "logic.h"
string char32_to_utf8(char32_t cp) {
    std::string out;

    if (cp > 0x10FFFF)
        throw std::runtime_error("Codepoint out of Unicode range");
    if (cp >= 0xD800 && cp <= 0xDFFF)
        throw std::runtime_error("Invalid UTF-32 surrogate");

    if (cp <= 0x7F) {
        out.push_back(static_cast<char>(cp));
    }
    else if (cp <= 0x7FF) {
        out.push_back(static_cast<char>(0xC0 | ((cp >> 6) & 0x1F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
    else if (cp <= 0xFFFF) {
        out.push_back(static_cast<char>(0xE0 | ((cp >> 12) & 0x0F)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
    else {
        out.push_back(static_cast<char>(0xF0 | ((cp >> 18) & 0x07)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }

    return out;
}

string utf32_to_utf8(const u32string& s) {
    std::string out;
    out.reserve(s.size()); // грубая оценка; реальный размер может быть больше

    for (char32_t cp : s) {
        if (cp > 0x10FFFF)
            throw std::runtime_error("Codepoint out of Unicode range");
        if (cp >= 0xD800 && cp <= 0xDFFF)
            throw std::runtime_error("UTF-16 surrogate is invalid in UTF-32");

        if (cp <= 0x7F) {
            // 1 байт: 0xxxxxxx
            out.push_back(static_cast<char>(cp));
        }
        else if (cp <= 0x7FF) {
            // 2 байта: 110xxxxx 10xxxxxx
            out.push_back(static_cast<char>(0xC0 | ((cp >> 6) & 0x1F)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else if (cp <= 0xFFFF) {
            // 3 байта: 1110xxxx 10xxxxxx 10xxxxxx
            out.push_back(static_cast<char>(0xE0 | ((cp >> 12) & 0x0F)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
        else {
            // 4 байта: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            out.push_back(static_cast<char>(0xF0 | ((cp >> 18) & 0x07)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
        }
    }

    return out;
}


u32string utf8_to_u32(const string& s) {
    std::u32string out;
    out.reserve(s.size());

    size_t i = 0;
    while (i < s.size()) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        char32_t codepoint = 0;
        size_t extra = 0;

        if (c <= 0x7F) { // 1 байт
            codepoint = c;
            extra = 0;
        }
        else if ((c & 0xE0) == 0xC0) { // 2 байта
            codepoint = c & 0x1F;
            extra = 1;
            if (codepoint < 0x02) // overlong (минимум 0x80)
                throw std::runtime_error("Overlong UTF-8 sequence");
        }
        else if ((c & 0xF0) == 0xE0) { // 3 байта
            codepoint = c & 0x0F;
            extra = 2;
        }
        else if ((c & 0xF8) == 0xF0) { // 4 байта
            codepoint = c & 0x07;
            extra = 3;
            if (codepoint > 0x04) // максимум U+10FFFF
                throw std::runtime_error("Invalid UTF-8 leading byte");
        }
        else {
            throw std::runtime_error("Invalid UTF-8 leading byte");
        }

        if (i + extra >= s.size())
            throw std::runtime_error("Truncated UTF-8 sequence");

        for (size_t j = 1; j <= extra; ++j) {
            unsigned char cc = static_cast<unsigned char>(s[i + j]);
            if ((cc & 0xC0) != 0x80)
                throw std::runtime_error("Invalid UTF-8 continuation byte");
            codepoint = (codepoint << 6) | (cc & 0x3F);
        }

        // Проверки на overlong и диапазоны
        if (extra == 1 && codepoint < 0x80)
            throw std::runtime_error("Overlong 2-byte sequence");
        if (extra == 2 && codepoint < 0x800)
            throw std::runtime_error("Overlong 3-byte sequence");
        if (extra == 3 && codepoint < 0x10000)
            throw std::runtime_error("Overlong 4-byte sequence");

        if (codepoint > 0x10FFFF)
            throw std::runtime_error("Codepoint out of range");
        if (codepoint >= 0xD800 && codepoint <= 0xDFFF)
            throw std::runtime_error("UTF-16 surrogate in UTF-8");

        out.push_back(codepoint);
        i += 1 + extra;
    }

    return out;
}


int main() {
    system("chcp 65001");
    string path = "..\\V2\\";

    u32string text1{ U"" };
    ifstream file1(path + "text1.txt");

    string line;
    while (getline(file1, line)) {
        u32string convted = utf8_to_u32(line);
        text1 += convted + U"\n";
    }


    letter_stat(text1);
    vowels_and_consonants_stat(text1);
    return 0;
}


