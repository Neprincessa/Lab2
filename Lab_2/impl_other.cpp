#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

//start -> seelct the type of work
int selectMode()
{
	cout << "������� 1, ���� ������ �������� � �������� ������" << endl;
	cout << "������� 2, ���� ������ �������� �� ����������" << endl;
	cout << "������� 3, ���� ������ �������� � ���������������" << endl;

	
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
		cout << "������� ����� ������������� �����, � �� ������ ��� ������� �����" << endl;

	return isd;
}

