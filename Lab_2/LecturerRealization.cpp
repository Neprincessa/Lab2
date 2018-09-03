#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------*Lecturer*---------------------------------------//
Lecturer::Lecturer() {
	this->Name = Name;
	this->SecondName = SecondName;
	this->Surname = Surname;
	this->experiense = experiense;
	this->AmountOfPublications = AmountOfPublications;
}

void Lecturer::BuildLecturer() {
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


void Lecturer::PrintLecturer() {
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

string Lecturer::GetLecturerSurname() {
	return Surname;
}

string Lecturer::GetLecturerName() {
	return Name;
}

string Lecturer::GetLecturerSecondName() {
	return SecondName;
}

int Lecturer::GetCurrentExperience() {
	return experiense;
}

int Lecturer::GetCurrentPublications() {
	return AmountOfPublications;
}