#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <codecvt>
using namespace std;

//Unicode32
string char32_to_utf8(char32_t cp);
string utf32_to_utf8(const u32string& s);
u32string utf8_to_u32(const string& s);

//1
void letter_stat(u32string s);
void vowels_and_consonants_stat(u32string s);
void dulls_and_voiced_sounds_stat(u32string s);
void rare_letters_stat(u32string s);
void punctuation_stat(u32string s);
//char32_t tolower32(char32_t ch);

//2
void stat_words_len(string st);

//3
void conjuctions(string st);

//4

//5
void stat_chered(string st);

//6
void task6();

//7
void task7();
//8

//9
u32string most_popular_word(u32string st);

