#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <map>
using namespace std;

string char32_to_utf8(char32_t cp);
string utf32_to_utf8(const u32string& s);
u32string utf8_to_u32(const string& s);

void letter_stat(u32string s);
void vowels_and_consonants_stat(u32string s);
void dulls_and_voiced_sounds_stat(u32string s);
void rare_letters_stat(u32string s);
void punctuation_stat(u32string s);

