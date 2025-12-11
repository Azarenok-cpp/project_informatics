#include "logic.h"

void conjuctions(string st){
	int i = 0, k = 0;
	string  x;
	vector<string> a = {
		"ст", "но", "ен", "то", "на", "ов", "ни", "ра", "во","ко"
	};
	vector<string> b = {
		"сто", "ено", "нов", "тов", "ово", "ова"
	};
	vector<int> lb(6);//массив с записью 3 букв
	vector<int> la(10);//массив с записью 2 букв
	while (i < 6) { lb[i] == 0; i++; }
	i = 0;
	while (i < 10) { la[i] == 0; i++; }
	i = 0;
	cout << "строка" << endl;

	while (st.length() != 0)
	{
		while (st.length() != 0 && st[0] == ' ')
			st.erase(0, 1);
		x = st.substr(0, st.find(' '));
		//x=x.tolower();
		st.erase(0, st.find(' '));
		while (i < 6) {
			if (x.find(b[i]) == 0)
				lb[i]++;

			i++;
		}
		i = 0;
		while (i < 10) {
			if (x.find(a[i]) == 0 && x.find(b[1]) != 0 && x.find(b[2]) != 0 && x.find(b[3]) != 0 && x.find(b[4]) != 0 && x.find(b[5]) != 0 && x.find(b[0]) != 0)
				la[i]++;
			i++;
		}
		i = 0;
	}
	while (i < 6) { cout << lb[i] << " "; i++; }
	i = 0;
	cout << "\n";
	while (i < 10) { cout << la[i] << " "; i++; }
}

