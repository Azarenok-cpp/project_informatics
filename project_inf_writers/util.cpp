#include "util.h"
vector <u32string> banned_words{ U"ט", U"א",U"ג", U"ף", U"מ", U"ÿ"};//banned words
double round_(double val) {
    return round(val * ACCURACY) / ACCURACY;
}

bool is_letter(char32_t c) {
    u32string mask = U"יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏¸";
    return mask.find(c) != string::npos;
}

bool isConsonant(char32_t c) {
    u32string mask = U"יצךםדרשחץתפגןנכהזקסלעüב";
    return mask.find(c) != string::npos;
}

bool isVowel(char32_t c) {
    u32string mask = U"¸ףוûאמ‎ÿט‏";
    return mask.find(c) != string::npos;
}
bool is_voiced(char32_t c) {
    u32string voiced_ = U"בגדהזח";
    return voiced_.find(c) != string::npos;
}

bool is_dull(char32_t c) {
    u32string dull_ = U"ןפךערסץצקש";
    return dull_.find(c) != string::npos;
}
bool is_rare(char32_t c) {
    u32string mask = U"פקץצשרזüתûי";
    return mask.find(c) != string::npos;
}
bool is_punct_sign(char32_t c) {
    u32string mask = U".?!,-—«»\"“„:;''()";
    return mask.find(c) != string::npos;
}

bool is_wordpart(char32_t c) {
    u32string mask = U"יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏¸ֹײ׃Êֳֵֽ״ÙַַױױÚװÛְֲֿ׀־ִֶֻÝß׳ָּׁׂÜֱÞ- ";
    return mask.find(c) != string::npos;
}

bool isWord(u32string s) {
    for (int i = 0; i < banned_words.size(); i++)
    {
        if (s == banned_words[i]) return false;
    }
    return true;
}
char32_t tolower32(char32_t ch) {
    if (ch >= U'ְ' && ch <= U'ß') {
        return ch + 32; //נאחםטצא לוזהף חאדכאגםûלט ט סענמקםûלט ג unicode
    }
    return ch;
}

u32string rework(u32string s) {
    u32string res = U"";
    for (int i = 0; i < s.length(); i++)
    {
        if (is_wordpart(s[i])) res += tolower32(s[i]);
    }

    return res;
}