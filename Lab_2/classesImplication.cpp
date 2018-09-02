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
	cout << "Введите фамилию" << endl;
	cin >> s;
	this->Surname = s;
	cout << "Введите имя" << endl;
	cin >> s;
	this->Name = s;
	cout << "Введите отчество" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "Введите средний балл студента" << endl;
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

	cout << "Фамилия:" << " ";
	cout << this->Surname << endl;

	cout << "Имя:" << " ";
	cout << this->Name << endl;

	cout << "Отчество:" << " ";
	cout << this->SecondName << endl;

	cout << "Средний балл" << " ";
	cout << this->scores << endl;

}