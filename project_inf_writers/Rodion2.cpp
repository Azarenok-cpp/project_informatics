#include "logic.h"

string most_popular_word() {
    string path = "..\\V2\\";
    ifstream file1(path + "text1.txt");
    ifstream file2(path + "text2.txt");
    ifstream file3(path + "text3.txt");
    ifstream file4(path + "text4.txt");

	map<string, int> freq;
    string word, resWord = "";

    while (file1 >> word) {
        for (int i = 0; i < word.size(); i++) {
             if(isalpha(word[i])) resWord += tolower((unsigned char)word[i]);
        }
        cout << (resWord) << "\n";
        freq[resWord]++;
    }

   return freq.rbegin()->first;
}