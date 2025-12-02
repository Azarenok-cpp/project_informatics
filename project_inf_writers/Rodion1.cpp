#include "logic.h"

bool isLetter(char c) {
	string mask = "йцукенгшщзхъфывапролджэячсмитьбю";
	return mask.find(c) != string::npos;
}

void letters_stat(string s) {
	map<string, int> freq;

	int len = s.length();
	int k = 0;

	for (int i = 0; i < len; i++)
	{
		if (isLetter(s[i])) {
			k++;
			freq[to_string(s[i])]++;
		}
	}

	for (pair<const string, int>& p : freq) {
		cout << (p.first) << " => " << p.second << " ("
			<< (p.second / freq.size() * 100.0) << "% )" << endl;
	}
}
