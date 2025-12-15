#include "logic.h"
#include "util.h"
void task6(){
    ifstream fin("..\\V2\\text1.txt");

    int countGG = 0, countGS = 0, countSG = 0, countSS = 0;
    string wordBefore, wordNow;

    fin >> wordBefore;
    while (fin >> wordNow) {
        char endBefore = lastLetterType(wordBefore);
        char startNow = firstLetterType(wordNow);

        if (endBefore == 'Ã' && startNow == 'Ã') countGG++;
        else if (endBefore == 'Ã' && startNow == 'Ñ') countGS++;
        else if (endBefore == 'Ñ' && startNow == 'Ã') countSG++;
        else if (endBefore == 'Ñ' && startNow == 'Ñ') countSS++;

        wordBefore = wordNow;
    }

    cout << "ÃÃ: " << countGG << endl;
    cout << "ÃÑ: " << countGS << endl;
    cout << "ÑÃ: " << countSG << endl;
    cout << "ÑÑ: " << countSS << endl;
}
