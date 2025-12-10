#include "logic.h"
#include "util.h"

u32string most_popular_word(u32string st) {
	u32string x;
	u32string res = U"";
	map <u32string, int> words;

	for (int i = 0; i < st.length(); i++)
	{
		if (is_wordpart(st[i])) res += tolower32(st[i]);
	}

	while (res.length() != 0)
	{
		while (res.length() != 0 && res[0] == ' ')
			res.erase(0, 1);

		x = res.substr(0, res.find(' '));

		if(isWord(x)) words[x]++;

		res.erase(0, (res.find(' ')));
	}

	u32string bestWord;
	int bestValue = -1;

	for (auto pair : words) { //каждая пара в words
		if (pair.second > bestValue) {
			bestValue = pair.second;
			bestWord = pair.first;
		}
	}

	return bestWord;
}