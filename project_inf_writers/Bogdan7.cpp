#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void task7(){
    ifstream fin("..\\V2\\text1.txt");

    int triGlasnye = 0;
    int triSoglasnye = 0;

    string glasnye = "àå¸èîóûýþÿÀÅ¨ÈÎÓÛÝÞß";
    string soglasnye = "áâãäæçéêëìíïðñòôõö÷øùúüÁÂÃÄÆÇÉÊËÌÍÎÏÐÑÒÔÕÖ×ØÙÚÜ";
    string slovo;
    while (fin >> slovo) {
        for (int i = 0; i + 2 < (int)slovo.size(); i++) {
            char a = slovo[i], b = slovo[i + 1], c = slovo[i + 2];

            bool aG = glasnye.find(a) != string::npos;
            bool bG = glasnye.find(b) != string::npos;
            bool cG = glasnye.find(c) != string::npos;

            bool aS = soglasnye.find(a) != string::npos;
            bool bS = soglasnye.find(b) != string::npos;
            bool cS = soglasnye.find(c) != string::npos;

            if (aG && bG && cG) triGlasnye++;
            if (aS && bS && cS) triSoglasnye++;
        }
    }

    cout << "Tri glasnye podryad: " << triGlasnye << endl;
    cout << "Tri soglasnye podryad: " << triSoglasnye << endl;

}
//Ïî ìîåìó êîä è òàê ïîíÿòíûé, 7 çàäàíèå ë¸ãêîå ñàì ðàçáåðåøüñÿ.
