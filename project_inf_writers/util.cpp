#include "util.h"

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
