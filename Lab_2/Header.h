#ifndef _LAB__1__
#define  _LAB__1__

#include <string>
using namespace std;



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
	string PrintName();
	string PrintSurname();
	string PrintSecondName();
	Student GetStudent(Student);
	int PrintScores();
	int PrintDebts();
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
	string PrintName();
	string PrintSecondName();
	string PrintSurname();
	int PrintExperience();
	int PrintPublications();
	int GetCurrentExperience();
	int GetCurrentPublications();
	bool IfInt_Lecturer(char *);
};


//-------------------------------------------*Other*----------------------------------------------------------//
void IncreaseDebts();
void AddAmountOfPublications();
void ChangeName();
void ChangeSurname();
int chooseFunction(int);
int chooseFieldForStudent();
int chooseFieldForLecturer();
int chooseField_WithChecks();

//void(*functions[])(void) =
//{
//	IncreaseDebts, AddAmountOfPublications, ChangeName, ChangeSurname
//};


int selectMode();
bool checkDataType(char*);
int setAmount();
#endif // !_LAB__1__
