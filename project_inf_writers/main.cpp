#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {
	system("chcp 65001");
	string path = "..\\V2\\";
	string* texts = new string[4]{};
	
	ifstream file1(path + "text1.txt");
	ifstream file2(path + "text2.txt");
	ifstream file3(path + "text3.txt");
	ifstream file4(path + "text4.txt");

	string line;
	while (getline(file1, line)) {
		texts[0] += line + "\n";
	}
	while (getline(file2, line)) {
		texts[1] += line + "\n";
	}
	while (getline(file3, line)) {
		texts[2] += line + "\n";
	}
	while (getline(file4, line)) {
		texts[3] += line + "\n";
	}




	cout << texts[0];

	return 0; 
}