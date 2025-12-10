#include "logic.h"

string char32_to_utf8(char32_t c) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.to_bytes(std::u32string(1, c));
}

string utf32_to_utf8(const u32string& s) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.to_bytes(s);
}


u32string utf8_to_u32(const string& s) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.from_bytes(s);
}
