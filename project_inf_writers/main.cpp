#include "logic.h"

void breakl() {
    for (int i = 0; i < 50; i++)
    {
        cout << '-';
    }
    cout << "\n";
}
int main() {
    system("chcp 65001");
    string path = "..\\V2\\";

    u32string text{ U"" };
    ifstream file1(path + "text4.txt");

    string line;
    while (getline(file1, line)) {
        u32string convted = utf8_to_u32(line);
        text += convted + U"\n";
    }

    cout << utf32_to_utf8(most_popular_word(text));
        

    return 0;
}


