#include "Header.h"
#include "Templ.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	int currentMode; //select the type of work
	currentMode = selectMode();

	if (currentMode != 1) {
		if (currentMode == 2) {
			List<Student> people;
			people.SetList();
			people.Show();
		}
		if (currentMode == 3) {
			List<Lecturer> people;
			people.SetList();
			people.Show();
		}
	}

	system("pause");
	return 0;
}
