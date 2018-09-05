#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

//-------------------------*other*-----------------------------//

//start -> seelct the type of work
int selectMode() {
	cout << "Fill in 1, if you want to work in test mode" << endl;
	cout << "Fill in 2, if you want to work with students" << endl;
	cout << "Fill in 3, if you want to work with lecturers" << endl;
	cout << "Fill in 4, if you want to work with functions" << endl;

	char strMode[256];
	char *p = strMode;

	//check the type of data and the diapason
	int mode;
	cin >> strMode;

	while (!checkDataType(p))
		cin >> strMode;

	mode = atoi(strMode);
	return mode;
}

//check the correctness of data type 
bool checkDataType(char *ptr) {
	bool isd = true;
	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}
	if (!isd)
		cout << "Fill in the positive integer, not a string or a double number" << endl;
	return isd;
}

int setAmount()
{
	int currentAmount;

	char amount[256];
	char *p = amount;

	cout << "Fill in the amount of elements" << endl;
	cin >> amount;

	while (!checkDataType(p))
		cin >> amount;
	currentAmount = atoi(amount);

	while (currentAmount < 0) {
		cout << "Fill in the positove intetger" << endl;
		cin >> amount;
		while (!checkDataType(p))
			cin >> amount;
		currentAmount = atoi(amount);
	}
	
	return currentAmount;
}

void IncreaseDebts() {
	int a = 5;
}
void AddAmountOfPublications() {
	int a = 5;
}
void ChangeName() {
	int a = 5;
}
void ChangeSurname() {
	int a = 5;
}

int chooseFunction(int mode) {
	char s[256];
	char *p = s;

	if (mode == 4) {//with functions
		cout << "Push 1, if you want to use insert sort" << endl;
		cout << "Push 2, if you want to use merge sort" << endl;
	}
	else {
		cout << "Push 1, if you want to use insert sort" << endl;
		cout << "Push 2, if you want to use merge sort" << endl;
		cout << "Push 3, if you want to select the current string" << endl;
	}

	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	int currentType = atoi(s);

	while (currentType < 0 || currentType > 3) {
		cout << "Fill in the posotive integer from the 1 to 3" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		currentType = atoi(s);
	}

	return currentType;
}

int chooseFieldForStudent() {
	
	cout << "If you want to get a surname of a student, push 1" << endl;
	cout << "If you want to get a name of a student, push 2" << endl;
	cout << "If you want to get a second name, push 3" << endl;
	cout << "If you want to get an average score of a student, push 4" << endl;
	cout << "If you want to get an amount of debts, push 5" << endl;

	int currentField = chooseField_WithChecks();
	return currentField;
}

int chooseFieldForLecturer() {
	
	cout << "If you want to get a surname of a lecturer, push 1" << endl;
	cout << "If you want to get a name of a lecturer, push 2" << endl;
	cout << "If you want to get a second name, push 3" << endl;
	cout << "If you want to get an amount of publicastions of a lecturer, push 4" << endl;
	cout << "If you want to get an experience, push 5" << endl;

	int currentField = chooseField_WithChecks();
	return currentField;
}

int chooseField_WithChecks() {
	char s[256];
	char *p = s;

	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	int currentfield = atoi(s);

	while (currentfield < 0 || currentfield > 5) {
		cout << "Fill in the integer from 1 to 5" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		currentfield = atoi(s);
	}
	return currentfield;
}

int chooseOperationWithObject(int currentMode) {

	int numberOfFunction;
	char s[256];
	char *p = s;

	if (currentMode != 4) {

		//it'd be great to add an opportunity for user to choose the parameter to sort and the sign <>
		cout << "Do you want to end work? Push 0!" << endl;
		cout << "Do you want to get a information about special person? Push 1!" << endl;
		cout << "Do you want to try insert sort? Push 2!" << endl;
		cout << "Do you want to use merge sort? Push 3!" << endl;
		cout << "Do you want to see the list? Push 4!" << endl;

		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		numberOfFunction = atoi(s);
		while (numberOfFunction < 0 || numberOfFunction > 5) {
			cout << "Fill in the number from 0 to 5" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			numberOfFunction = atoi(s);
		}
	}

	if (currentMode == 4) {
		//it'd be great to add an opportunity for user to choose the parameter to sort and the sign <>
		cout << "Do you want to end work? Push 0!" << endl;
		cout << "Do you want to try insert sort? Push 1!" << endl;
		cout << "Do you want to use merge sort? Push 2!" << endl;
		cout << "Do you want to see the list? Push 3!" << endl;

		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		numberOfFunction = atoi(s);
		while (numberOfFunction < 0 || numberOfFunction > 3) {
			cout << "Fill in the number from 0 to 3" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			numberOfFunction = atoi(s);
		}
	}

	return numberOfFunction;
}