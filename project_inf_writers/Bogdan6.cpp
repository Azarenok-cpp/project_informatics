//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//bool v(char c) {
//    string vowels = "ÀÅ¨ÈÎÓÛİŞßàå¸èîóûışÿ";
//    for (int i = 0;i < vowels.size();i++)
//        if (c == vowels[i]) return true;
//    return false;
//}
//
//char st(string w) {
//    return v(w[0]) ? 'Ã' : 'Ñ';
//}
//
//char en(string w) {
//    return v(w[w.size() - 1]) ? 'Ã' : 'Ñ';
//}
//
//int main() {
//    ifstream f("input.txt");
//    if (!f) return 1;
//
//    int GG = 0, GS = 0, SG = 0, SS = 0;
//    string p, c;
//
//    if (f >> p)
//        while (f >> c) {
//            char a = en(p), b = st(c);
//            if (a == 'Ã' && b == 'Ã') GG++;
//            else if (a == 'Ã' && b == 'Ñ') GS++;
//            else if (a == 'Ñ' && b == 'Ã') SG++;
//            else SS++;
//            p = c;
//        }
//
//    cout << "ÃÃ:" << GG << "\n";
//    cout << "ÃÑ:" << GS << "\n";
//    cout << "ÑÃ:" << SG << "\n";
//    cout << "ÑÑ:" << SS << "\n";
//}