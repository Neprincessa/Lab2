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
	this->debts = debts;
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

	cout << "Fill in the amount of debts" << endl;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	this->debts = atoi(s);

	if (debts < 0) {
		while (debts < 0) {
			cout << "Fill in the mositive integer" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
			this->debts = atoi(s);
		}
		this->debts = debts;
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

	cout << "Amount of debts" << " ";
	cout << this->debts << endl;

}


//------------------------------------------------------------*Lecturer*---------------------------------------//
Lecturer::Lecturer()
{
	this->Name = Name;
	this->SecondName = SecondName;
	this->Surname = Surname;
	this->experiense = experiense;
	this->AmountOfPublications = AmountOfPublications;
}

void Lecturer::BuildLecturer()
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

	cout << "Fill in the experience of lecturer" << endl;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	this->experiense = atoi(s);

	if (experiense < 0) {
		while (experiense < 0)
		{
			cout << "Fill in the positive integer" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
		}
		this->experiense = atoi(s);
	}
	cout << "\n";

	cout << "Fill in the amount of publications" << endl;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	this->AmountOfPublications = atoi(s);

	if (AmountOfPublications < 0) {
		while (AmountOfPublications < 0) {
			cout << "Fill in the positive integer" << endl;
			cin >> s;
			while (!checkDataType(p))
				cin >> s;
		}
		this->AmountOfPublications = atoi(s);
	}
}


void Lecturer::PrintLecturer()
{
	cout << "Surname:" << " ";
	cout << this->Surname << endl;
	cout << "Name:" << " ";
	cout << this->Name << endl;
	cout << "Second name:" << " ";
	cout << this->SecondName << endl;
	cout << "Experience:" << " ";
	cout << this->experiense << endl;
	cout << "Publications:" << " ";
	cout << this->AmountOfPublications << endl;
}
//-------------------------*other*-----------------------------//

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
