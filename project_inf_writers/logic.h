#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <map>
using namespace std;
void letters_stat(string s);
string most_popular_word();

string char32_to_utf8(char32_t cp);
string utf32_to_utf8(const u32string& s);
u32string utf8_to_u32(const string& s);

void letter_stat(u32string s);
void vowels_and_consonants_stat(u32string s);
