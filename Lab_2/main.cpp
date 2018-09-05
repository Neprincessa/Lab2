#include "Header.h"
#include "Templ.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	char s[256];
	char *p = s;

	int currentMode; //select the type of work
	currentMode = selectMode();
	int currentTypeOfFunction = -1;

	if (currentMode != 1) {

		if (currentMode == 2) {
			
			List<Student> people;
			people.SetList();
			
			while (currentTypeOfFunction != 0) {
				
				currentTypeOfFunction = chooseOperationWithObject(currentMode);
				
				switch (currentTypeOfFunction)
				{
				case 0: {
					break;
				}
				case 1: {
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
					break;
				}
				case 2: {
					cout << "Insert sort" << endl;
					people.InsertSort();
					cout << "\n";
					people.Show();
					break;
				}
				case 3: {
					//merge sort
					cout << "Merge sort" << endl;
					people.sort();
					people.Show();
					break;
				}
				case 4: {
					people.Show();
					break;
				}
				default:
					break;
				}
			}			
		}

		if (currentMode == 3) {
			List<Lecturer> people;
			people.SetList();

			while (currentTypeOfFunction != 0) {
				
				currentTypeOfFunction = chooseOperationWithObject(currentMode);

				switch (currentTypeOfFunction)
				{
				case 0: {
					break;
				}
				case 1: {
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
					break;
				}
				case 2: {
					cout << "Insert sort" << endl;
					people.InsertSort();
					cout << "\n";
					break;
				}
				case 3: {
					cout << "Merge sort" << endl;
					people.sort();
					people.Show();
					break;
				}
				case 4: {
					people.Show();
					break;
				}
				default:
					break;
				}
			}
		}

		if (currentMode == 4) {
			List<void*> func;
			func.SetList();
			
			cout << "Start list" << endl;
			func.Show();
			cout << "\n";

			while (currentTypeOfFunction != 0) {
				
				currentTypeOfFunction = chooseOperationWithObject(currentMode);

				switch (currentTypeOfFunction)
				{
				case 0: {
					break;
				}
				case 1: {
					func.InsertSort();
					cout << "Insert sort" << endl;
					func.Show();
					break;
				}
				case 2: {
					cout << "Merge sort" << endl;
					func.sort();
					func.Show();
					break;
				}
				case 3: {
					func.Show();
					break;
				}
				default:
					break;
				}
			}		
		}
	}

	system("pause");
	return 0;
}
