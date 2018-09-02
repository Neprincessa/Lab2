#include "Header.h"
#include "impl_other.cpp"
#include <iostream>
#include <string>

using namespace std;

//-------------------------------Student---------------------------------------//

Student::Student()
{
	this->Name = Name;
	this->SecondName = SecondName;
	this->Surname = Surname;
	this->debts = debts;
}

void Student::BuildStudent()
{
	char s[256];
	char *p = s;
	cout << "������� �������" << endl;
	cin >> s;
	this->Surname = s;
	cout << "������� ���" << endl;
	cin >> s;
	this->Name = s;
	cout << "������� ��������" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "������� ������� ���� ��������" << endl;
	cin >> s;

	while (!checkDataType(p))
		cin >> s;
	this->scores = atoi(s);

	while (scores < 0)
	{
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		this->scores = atoi(s);
	}
	cout << "\n";
}

void Student::PrintStudent()
{
	char s[256];
	char *p = s;

	cout << "�������:" << " ";
	cout << this->Surname << endl;

	cout << "���:" << " ";
	cout << this->Name << endl;

	cout << "��������:" << " ";
	cout << this->SecondName << endl;

	cout << "������� ����" << " ";
	cout << this->scores << endl;

}




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
