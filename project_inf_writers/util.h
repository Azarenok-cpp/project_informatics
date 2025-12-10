#pragma once
#include <string>
#include <vector>
using namespace std;

#define ACCURACY 10'000 //округление результатов до дес€титыс€чных
double round_(double val);

bool is_letter(char32_t c);
bool isConsonant(char32_t c);
bool isVowel(char32_t c);
bool is_voiced(char32_t c);
bool is_dull(char32_t c);
bool is_rare(char32_t c);
bool is_punct_sign(char32_t c);
bool is_wordpart(char32_t c);
bool isWord(u32string s);
u32string rework(u32string s);

string char32_to_utf8(char32_t cp);
string utf32_to_utf8(const u32string& s);
u32string utf8_to_u32(const string& s);
