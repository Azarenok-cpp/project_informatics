#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {
	system("chcp 65001");

	string* texts = new string[4]{};
	
	ifstream file1("text1.txt"); //fix filepaths, only text1 works properly
	ifstream file2("text2.txt");
	ifstream file3("text3.txt");
	ifstream file4("text4.txt");

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




	//cout << texts[0];

	return 0; 
}