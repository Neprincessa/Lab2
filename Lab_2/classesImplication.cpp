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
	this->scores = scores;
}

void Student::BuildStudent()
{
	char s[256];
	char *p = s;
	cout << "Fill in the surname" << endl;
	cin >> s;
	this->Surname = s;
	cout << "Fill in the name" << endl;
	cin >> s;
	this->Name = s;
	cout << "Fill in the second name" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "Fill in the average scores of student" << endl;
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

	cout << "Surname:" << " ";
	cout << this->Surname << endl;

	cout << "Name:" << " ";
	cout << this->Name << endl;

	cout << "Second:" << " ";
	cout << this->SecondName << endl;

	cout << "Average scores" << " ";
	cout << this->scores << endl;

}




//start -> seelct the type of work
int selectMode()
{
	cout << "Fill in 1, if you want to work in test mode" << endl;
	cout << "Fill in 2, if you want to work with students" << endl;
	cout << "Fill in 3, if you want to work with lecturers" << endl;


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
		cout << "Fill in the positive integer, not a string or a double number" << endl;
	return isd;
}
