#include "logic.h"

int main() {
    system("chcp 65001");
    string path = "..\\V2\\";
    ifstream fin(path + "text1.txt");

    string v = "аеёиоуыэюяАЕЁИОУЫЭЮЯ", w1, w2;
    int r[4] = { 0 };

    if (fin >> w1) while (fin >> w2) {
        bool a = v.find(w1.back()) != -1, b = v.find(w2[0]) != -1;
        r[(a ? 0 : 2) + (b ? 0 : 1)]++;
        w1 = w2;
    }

    cout << "GG: " << r[0] << "\nGS: " << r[1] << "\nSG: " << r[2] << "\nSS: " << r[3];
}
