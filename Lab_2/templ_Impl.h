#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void List<Student>::SetList() {

	typeMode = 2;

	int currentAmount;
	currentAmount = setAmount();

	int i = 0;
	while (i < currentAmount) {
		cout << i + 1 << ")" << endl;
		Student a;
		a.BuildStudent();
		AddNode(a);
		i++;
	}
}

void List<Lecturer>::SetList() {
	typeMode = 3;

	int currentAmount;
	currentAmount = setAmount();

	int i = 0;
	while (i < currentAmount) {
		cout << i + 1 << ")" << endl;
		Lecturer a;
		a.BuildLecturer();
		AddNode(a);
		i++;
	}
}

template <class T>
void List<T>::AddNode(T x) {
	Node<T> *temp = new Node<T>;               
	temp->Next = NULL;                  
	temp->data = x;                       

	if (head != NULL)   //���� ������ �� ����
	{
		temp->Prev = tail;              
		tail->Next = temp;             
		tail = temp;                   
	}
	else //���� ������ ������
	{
		temp->Prev = NULL;              
		head = tail = temp;             
	}
}


void List<Student>::Show() {
	//������� ������ � �����
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

	//������� ������ � ������
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
	//������� ������ � �����
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

	//������� ������ � ������
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