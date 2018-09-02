#ifndef _LAB__1__
#define  _LAB__1__

#include <string>
using namespace std;

//struct Node
//{
//	void *data;
//	Node *Next, *Prev;
//};

//----------------------------------------------------*Data*-----------------------------------------------------//

//==================================*Student*=============================//
class Student
{
private:
	string Name;
	string Surname;
	string SecondName;
	int scores;
	int debts;
public:
	Student();
	void PrintStudent();
	void BuildStudent();
	string GetStudentName();
	string GetStudentSurname();
	string GetStudenSecondName();
	string GetStudentYear();
	string GetStudentGroup();
	string GetStudentScores();
	string GetStudentsDebts();
	int GetCurrentScores();
	int GetCurrentDebts();
	bool IfInt_Student(char *ptr);
};

//==================================*Lecturer*=============================//
class Lecturer
{
	string Name;
	string Surname;
	string SecondName;
	int AmountOfPublications;
	int experiense;
public:
	Lecturer();
	void BuildLecturer();
	void PrintLecturer();
	string GetLecturerName();
	string GetLecturerSurname();
	string GetLecturerSecondName();
	string GetLecturerDegree();
	string GetLecturerAmountOfPublications();
	string GetLecturerExperience();
	int GetCurrentExperience();
	int GetCurrentPublications();
	bool IfInt_Lecturer(char *);
};


//-------------------------------------------*Other*----------------------------------------------------------//
//void IncreaseDebts();
//void AddAmountOfPublications();
//void ChangeName();
//void ChangeSurname();

//void(*functions[])(void) =
//{
//	IncreaseDebts, AddAmountOfPublications, ChangeName, ChangeSurname
//};


int selectMode();
bool checkDataType(char*);
#endif // !_LAB__1__
