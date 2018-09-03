#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void List<Student>::SetList() {

	typeMode = 2;

	int currentAmount;
	currentAmount = setAmount();
	amount = currentAmount;

	int i = 0;
	while (i < currentAmount) {
		cout << i + 1 << ")" << endl;
		Student a;
		a.BuildStudent();
		AddNode(a);
		i++;
		cout << "\n";
	}
}

void List<Lecturer>::SetList() {
	typeMode = 3;

	int currentAmount;
	currentAmount = setAmount();
	amount = currentAmount;

	int i = 0;
	while (i < currentAmount) {
		cout << i + 1 << ")" << endl;
		Lecturer a;
		a.BuildLecturer();
		AddNode(a);
		i++;
		cout << "\n";
	}
}

template <class T>
void List<T>::AddNode(T x) {
	Node<T> *temp = new Node<T>;               
	temp->Next = NULL;                  
	temp->data = x;                       

	if (head != NULL)   //if list is not empty
	{
		temp->Prev = tail;              
		tail->Next = temp;             
		tail = temp;                   
	}
	else  //if list is empty
	{
		temp->Prev = NULL;              
		head = tail = temp;             
	}
}


void List<Student>::Show() {
	//Show from thw tail
	cout << "The list from the end:" << endl;
	Node<Student> *temp = tail;  
	int i = 0;
	while (temp != NULL)              
	{
		i++;
		cout << i << ")" << endl;
		temp->data.PrintStudent();
		temp = temp->Prev;   
		cout << "\n";
	}
	cout << "\n";

	//Show from the begining
	cout << "The list from the begining:" << endl;
	temp = head;   
	i = 0;
	while (temp != NULL)              
	{
		i++;
		cout << i << ")" << endl;
		temp->data.PrintStudent();
		temp = temp->Next;         
	}
	cout << "\n";
}

void List<Lecturer>::Show() {
	//Show from thw tail
	cout << "The list from the end:" << endl;
	Node<Lecturer> *temp = tail;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		cout << i << ")" << endl;
		temp->data.PrintLecturer();
		temp = temp->Prev;
		cout << "\n";
	}
	cout << "\n";

	//Show from the begining
	cout << "The list from the begining:" << endl;
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		cout << i << ")" << endl;
		temp->data.PrintLecturer();
		temp = temp->Next;
	}
	cout << "\n";
}

template <class T>
List<T>::~List() {
	while (head)                      
	{
		tail = head->Next;            
		delete head;                   
		head = tail;                   
	}
}

template <class T>
int List<T>::GetAmount() {
	return amount;
}

void List<Student>::SelectCurrentOrder(int index) {
	int i = 0;

	Node<Student> *temp = head;
	Node<Student> currentPerson;

	while (( temp != nullptr) && ((i+1) != index)) {
		if (i == index)
			currentPerson.data = temp->data;
		i++;
		temp = temp->Next;
	}

	int field = chooseFieldForStudent();
	
	switch (field)
	{
	case 1: {
		temp->data.PrintSurname();
		break;
	}
	case 2: {
		temp->data.PrintName();
		break;
	}
	case 3: {
		temp->data.PrintSecondName();
		break;
	}
	case 4: {
		temp->data.PrintScores();
		break;
	}
	case 5: {
		temp->data.PrintDebts();
		break;
	}
	default:
		break;
	}
	cout << "\n";
}

void List<Lecturer>::SelectCurrentOrder(int index) {
	int i = 0;

	Node<Lecturer> *temp = head;
	Node<Lecturer> currentPerson;
	while ((temp != nullptr) && ((i + 1) != index)) {
		if (i == index)
			currentPerson.data = temp->data;
		i++;
		temp = temp->Next;
	}

	int field = chooseFieldForLecturer();

	switch (field)
	{
	case 1: {
		temp->data.PrintSurname();
		break;
	}
	case 2: {
		temp->data.PrintName();
		break;
	}
	case 3: {
		temp->data.PrintSecondName();
		break;
	}
	case 4: {
		temp->data.PrintPublications();
		break;
	}
	case 5: {
		temp->data.PrintExperience();
		break;
	}
	default:
		break;
	}
	cout << "\n";
}

//scores
void List<Student>::InsertSort()
{
	Node<Student> *t;
	int x;
	Node <Student> curStudent;
	t = head->Next;
	while (t)
	{
		x = /**(int *)*/t->data.GetCurrentScores();
		curStudent.data = t->data;
		Node<Student> *b = t->Prev;
		while (b != NULL && x < /**(int *)*/b->data.GetCurrentScores())
		{
			/**(int *)*/b->Next->data = /**(int *)*/b->data;
			b = b->Prev;
		}
		if (b == NULL)
			head->data = curStudent.data;
		///**(int *)*/head->data.GetCurrentScores() = x;
		else
			b->Next->data = curStudent.data;
			///**(int *)*/b->Next->data.GetCurrentScores() = x;
		t = t->Next;
	}

}