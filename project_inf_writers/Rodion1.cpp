#include "logic.h"
#include "util.h"

double total = 0;

void letter_stat(u32string s) {
    map <char32_t, int> freq;

    for (int i = 0; i < s.length(); i++) { //fill map
        if (is_letter(tolower(s[i]))) freq[s[i]]++;
    }

    for (const auto& pair : freq) {//count all values
        total += pair.second;
    }

    for (const auto& pair : freq) {//output
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / total) << endl;
    }
}

void vowels_and_consonants_stat(u32string s) {
    map <char32_t, int> vow;
    map <char32_t, int> cons;

    double vow_c = 0, cons_c = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (isConsonant(tolower(s[i]))) cons[s[i]]++;
        else if (is_vowel(tolower(s[i]))) vow[s[i]]++;
    }

    for (const auto& pair : vow) {
        vow_c += pair.second;
    }
    for (const auto& pair : cons) {
        cons_c += pair.second;
    }

    for (const auto& pair : vow) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / vow_c) << endl;
    }

    cout << "\n";

    for (const auto& pair : cons) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / cons_c) << endl;
    }

    cout << "Vowels to consonants relation: " << round_(vow_c / cons_c) << endl;
}


void dulls_and_voiced_sounds_stat(u32string s) {
    map <char32_t, int> dulls;
    map <char32_t, int> voiceds;

    double dull_c = 0, voiced_c = 0;

    for (int i = 0; i < s.length(); i++) {
        if (is_voiced(tolower(s[i]))) dulls[s[i]]++;
        else if (is_dull(tolower(s[i]))) voiceds[s[i]]++;
    }

    for (const auto& pair : dulls) {
        dull_c += pair.second;
    }
    for (const auto& pair : voiceds) {
        voiced_c += pair.second;
    }

    for (const auto& pair : dulls) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / dull_c) << endl;
    }

    cout << "\n";

    for (const auto& pair : voiceds) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / voiced_c) << endl;
    }

    cout << "Dull to voiced consonants relation: " << round_(dull_c / voiced_c) << endl;
}


void rare_letters_stat(u32string s) {
    map <char32_t, int> freq;

    for (int i = 0; i < s.length(); i++) {
        if (is_rare(tolower(s[i]))) freq[s[i]]++;
    }

    total = 0;
    for (const auto& pair : freq) {
        total += pair.second;
    }

    for (const auto& pair : freq) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / total) << endl;
    }
}


void punctuation_stat(u32string s) {
    map <char32_t, int> freq;
    for (int i = 0; i < s.length(); i++) {
        if (is_punct_sign(tolower(s[i]))) freq[s[i]]++;
    }

    total = 0;
    for (const auto& pair : freq) {
        total += pair.second;
    }

    for (const auto& pair : freq) {
        cout << char32_to_utf8(pair.first) << " : " << round_(pair.second / total) << endl;
    }
}
