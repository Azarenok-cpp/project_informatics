#include "util.h"
vector <u32string> banned_words{ U"è", U"à",U"â", U"ó", U"î" };//banned words
double round_(double val) {
    return round(val * ACCURACY) / ACCURACY;
}

bool is_letter(char32_t c) {
    u32string mask = U"éöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş¸";
    return mask.find(c) != string::npos;
}

bool isConsonant(char32_t c) {
    u32string mask = U"éöêíãøùçõúôâïğëäæ÷ñìòüá";
    return mask.find(c) != string::npos;
}

bool is_vowel(char32_t c) {
    u32string mask = U"¸óåûàîıÿèş";
    return mask.find(c) != string::npos;
}
bool is_voiced(char32_t c) {
    u32string voiced_ = U"áâãäæç";
    return voiced_.find(c) != string::npos;
}

bool is_dull(char32_t c) {
    u32string dull_ = U"ïôêòøñõö÷ù";
    return dull_.find(c) != string::npos;
}
bool is_rare(char32_t c) {
    u32string mask = U"ô÷õöùøæüúûé";
    return mask.find(c) != string::npos;
}
bool is_punct_sign(char32_t c) {
    u32string mask = U".?!,-—«»\"“„:;''()";
    return mask.find(c) != string::npos;
}

bool is_wordpart(char32_t c) {
    u32string mask = U"éöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş¸ÉÖÓÊÅÍÃØÙÇÇÕÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞ- ";
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
    if (ch >= U'À' && ch <= U'ß') {
        return ch + 32; //ğàçíèöà ìåæäó çàãëàâíûìè è ñòğî÷íûìè â unicode
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

//Bogdan
bool isVowel(char c) {
    string vowels = "ÀÅ¨ÈÎÓÛİŞßàå¸èîóûışÿ";
    for (int i = 0; i < vowels.size(); i++)
        if (c == vowels[i]) return true;
    return false;
}

char firstLetterType(const string& word) {
    return isVowel(word[0]) ? 'Ã' : 'Ñ';
}

char lastLetterType(const string& word) {
    return isVowel(word[word.size() - 1]) ? 'Ã' : 'Ñ';
}


//Maksim
const string GL_CHARS = "àå¸èîóûışÿÀÅ¨ÈÎÓÛİŞß";
const string SG_CHARS = "áâãäæçéêëìíïğñòôõö÷øùúüÁÂÃÄÆÇÉÊËÌÍÏĞÑÒÔÕÖ×ØÙÚÜ";
int get_char_type(char c) {
    if (GL_CHARS.find(c) != string::npos) return 1; // Ãëàñíàÿ
    if (SG_CHARS.find(c) != string::npos) return 2; // Ñîãëàñíàÿ
    return 0; // Íå áóêâà
}

