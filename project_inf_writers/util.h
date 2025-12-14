#pragma once
#include <string>
#include <vector>
using namespace std;

#define ACCURACY 10'000 //округление результатов до дес€титыс€чных
double round_(double val);

bool is_letter(char32_t c);
bool isConsonant(char32_t c);
bool is_vowel(char32_t c);
bool is_voiced(char32_t c);
bool is_dull(char32_t c);
bool is_rare(char32_t c);
bool is_punct_sign(char32_t c);
bool is_wordpart(char32_t c);
bool isWord(u32string s);
u32string rework(u32string s);
char32_t tolower32(char32_t ch);

string char32_to_utf8(char32_t cp);
string utf32_to_utf8(const u32string& s);
u32string utf8_to_u32(const string& s);


bool isVowel(char c);
char firstLetterType(const string& word);
char lastLetterType(const string& word);

int get_char_type(char c);