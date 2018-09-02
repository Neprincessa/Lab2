#include "Header.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	int currentMode; //select the type of work
	currentMode = selectMode();

	Student a;
	cout << "fdfd" << endl;
	a.BuildStudent();
	a.PrintStudent();
	system("pause");
	return 0;
}
