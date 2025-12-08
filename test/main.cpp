#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main() {
	//system("chcp 65001");
	setlocale(LC_ALL, "Russian");
	ifstream fin("text1.txt");
	ofstream fout("out1.txt");
	vector<string> words;
	string word;

	while (fin >> word) {
		words.push_back(word);
		//cout << word << endl;
	}
	string mask = ".,'\"\' -—«»!&()";
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].length(); j++)
		{
			words[i][j] = tolower(words[i][j]);
			if (mask.find((words[i][j]) != string::npos)) words[i].erase(j, 1);
		}
		fout << words[i] << "\n";
	}

	return 0;
}
