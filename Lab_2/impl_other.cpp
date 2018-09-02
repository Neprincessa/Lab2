#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

//start -> seelct the type of work
int selectMode()
{
	cout << "Введите 1, если хотите работать в тестовом режиме" << endl;
	cout << "Введите 2, если хотите работать со студентами" << endl;
	cout << "Введите 3, если хотите работать с преподавателями" << endl;

	
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
bool checkDataType(char *ptr)
{
	bool isd = true;
	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}
	if (!isd)
		cout << "Введите целое положительное число, а не строку или дробное число" << endl;

	return isd;
}

