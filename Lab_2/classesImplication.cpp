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
	cout << "¬ведите фамилию" << endl;
	cin >> s;
	this->Surname = s;
	cout << "¬ведите им€" << endl;
	cin >> s;
	this->Name = s;
	cout << "¬ведите отчество" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "¬ведите средний балл студента" << endl;
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

	cout << "‘амили€:" << " ";
	cout << this->Surname << endl;

	cout << "»м€:" << " ";
	cout << this->Name << endl;

	cout << "ќтчество:" << " ";
	cout << this->SecondName << endl;

	cout << "—редний балл" << " ";
	cout << this->scores << endl;

}




//start -> seelct the type of work
int selectMode()
{
	cout << "¬ведите 1, если хотите работать в тестовом режиме" << endl;
	cout << "¬ведите 2, если хотите работать со студентами" << endl;
	cout << "¬ведите 3, если хотите работать с преподавател€ми" << endl;


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
		cout << "¬ведите целое положительное число, а не строку или дробное число" << endl;

	return isd;
}
