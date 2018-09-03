#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

//-------------------------------Student---------------------------------------//

Student::Student() {
	this->Name = Name;
	this->SecondName = SecondName;
	this->Surname = Surname;
	this->scores = scores;
	this->debts = debts;
}

void Student::BuildStudent() {
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

	cout << "Fill in the amount of debts" << endl;
	cin >> s;
	while (!checkDataType(p))
		cin >> s;
	this->debts = atoi(s);

	while (debts < 0) {
		cout << "Fill in the positive integer" << endl;
		cin >> s;
		while (!checkDataType(p))
			cin >> s;
		this->debts = atoi(s);
	}

	cout << "\n";
}

void Student::PrintStudent() {
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

int Student::GetCurrentDebts() {
	return debts;
}

int Student::GetCurrentScores() {
	return scores;
}

string Student::GetStudentName() {
	return Name;
}

string Student::GetStudenSecondName() {
	return SecondName;
}

string Student::GetStudentSurname() {
	return Surname;
}

void Student::PrintSurname() {
	cout << Surname << endl;
}

void Student::PrintName() {
	cout << Name << endl;
}

void Student::PrintSecondName() {
	cout << SecondName << endl;
}

void Student::PrintScores() {
	cout << scores << endl;
}

void Student::PrintDebts() {
	cout << debts << endl;
}