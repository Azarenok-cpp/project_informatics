#include "logic.h"

void print_map(const map<char32_t, int>& m) {
    for (const auto& pair : m) {
        cout << char32_to_utf8(pair.first) << " : " << pair.second << endl;
    }
}

bool isLetter(char32_t c) {
    u32string mask = U"йцукенгшщзхъфывапролджэячсмитьбю";
    return mask.find(c) != string::npos;
}

bool isConsonant(char32_t c) {
    u32string mask = U"йцкнгшщзхъфвпрлджчсмтьб";
    return mask.find(c) != string::npos;
}

bool isVowel(char32_t c) {
    u32string mask = U"уеыаоэяию";
    return mask.find(c) != string::npos;
}

void letter_stat(u32string s) {
    map <char32_t, int> freq;
    for (int i = 0; i < s.length(); i++) {
        if (isLetter(tolower(s[i]))) freq[s[i]]++;
    }

    double total = 0;
    for (const auto& pair : freq) {
        total += pair.second;
    }

    for (const auto& pair : freq) {
        cout << char32_to_utf8(pair.first) << " : " << (pair.second / total) << endl;
    }
}

void vowels_and_consonants_stat(u32string s) {
    map <char32_t, int> vow;
    map <char32_t, int> cons;
    double vow_c = 0, cons_c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isConsonant(tolower(s[i]))) cons[s[i]]++;
        else if (isVowel(tolower(s[i]))) vow[s[i]]++;
    }

    for (const auto& pair : vow) {
        vow_c += pair.second;
    }
    for (const auto& pair : cons) {
        cons_c += pair.second;
    }

    for (const auto& pair : vow) {
        cout << char32_to_utf8(pair.first) << " : of all: " << (pair.second / (cons_c + vow_c))
            << ", of vowels: " << (pair.second / vow_c) << endl;
    }

    for (const auto& pair : cons) {
        cout << char32_to_utf8(pair.first) << " : of all: " << (pair.second / (cons_c + vow_c))
            << ", of consonants: " << (pair.second / cons_c) << endl;
    }
}
