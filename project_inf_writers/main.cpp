#include "logic.h"

void breakl() {
    for (int i = 0; i < 50; i++)
    {
        cout << '-';
    }
    cout << "\n";
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
    breakl();
    vowels_and_consonants_stat(text1);
    breakl();
    dulls_and_voiced_sounds_stat(text1);
    breakl();
    rare_letters_stat(text1);
    breakl();
    punctuation_stat(text1);
    
    cout << utf32_to_utf8(most_popular_word(text1));
    return 0;
}


