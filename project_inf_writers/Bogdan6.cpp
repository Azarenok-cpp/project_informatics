#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Проверка: является ли символ русской гласной (в любом регистре)
bool isVowel(char c) {
    string vowels = "АЕЁИОУЫЭЮЯаеёиоуыэюя";
    for (int i = 0; i < vowels.size(); i++)
        if (c == vowels[i]) return true;
    return false;
}

// Определяем тип первой буквы слова
char firstLetterType(const string& word) {
    return isVowel(word[0]) ? 'Г' : 'С';
}

// Определяем тип последней буквы слова
char lastLetterType(const string& word) {
    return isVowel(word[word.size() - 1]) ? 'Г' : 'С';
}

void task6(){
    ifstream fin("..\\V2\\text1.txt");

    int countGG = 0, countGS = 0, countSG = 0, countSS = 0;
    string wordBefore, wordNow;

    fin >> wordBefore; // читаем первое слово, чтобы было с чем сравнивать
    while (fin >> wordNow) { // цикл по всем остальным словам
        //Поиск первой и последней буковы
        char endBefore = lastLetterType(wordBefore);
        char startNow = firstLetterType(wordNow);

        // Ну счетчики просто увеличиваем в зависимости от пары
        if (endBefore == 'Г' && startNow == 'Г') countGG++;
        else if (endBefore == 'Г' && startNow == 'С') countGS++;
        else if (endBefore == 'С' && startNow == 'Г') countSG++;
        else if (endBefore == 'С' && startNow == 'С') countSS++;

        wordBefore = wordNow; //Следующее слово меняется с текущим
    }

    cout << "ГГ: " << countGG << endl;
    cout << "ГС: " << countGS << endl;
    cout << "СГ: " << countSG << endl;
    cout << "СС: " << countSS << endl;
}
