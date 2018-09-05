#include "Header.h"
#include "Templ.h"
#include <iostream>
#include <string>
using namespace std;

//add for functions

int main() {

	setlocale(LC_ALL, "rus");

	char s[256];
	char *p = s;

	int currentMode; //select the type of work
	currentMode = selectMode();

	if (currentMode != 1) {
		if (currentMode == 2) {
			List<Student> people;
			people.SetList();
			
			int number;
			cout << "Fill in the number of a person, whose data you want to know" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			number = atoi(s);
			
			while (number < 0 || number > people.GetAmount()) {
				cout << "Fill in the number from 0 to ";
				cout << people.GetAmount();
				cout << "\n";
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				number = atoi(s);
			}

			people.SelectCurrentOrder(number);

			cout << "Insert sort" << endl;
			people.InsertSort();
			cout << "\n";
			people.Show();

			//merge sort
			cout << "Merge sort" << endl;
			people.sort();
			people.Show();
		}

		if (currentMode == 3) {
			List<Lecturer> people;
			people.SetList();

			int number;
			cout << "Fill in the number of a person, whose data you want to know" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			number = atoi(s);

			while (number < 0 || number > people.GetAmount()) {
				cout << "Fill in the number from 0 to ";
				cout << people.GetAmount();
				cout << "\n";
				cin >> s;
				while (!checkDataType(p))
					cin >> s;
				number = atoi(s);
			}

			people.SelectCurrentOrder(number);

			cout << "Insert sort" << endl;
			people.InsertSort();
			cout << "\n";
			
			cout << "Merge sort" << endl;
			people.sort();
			people.Show();
		}
	}

	system("pause");
	return 0;
}
