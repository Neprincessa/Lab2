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

	if (head != NULL)   //Если список не пуст
	{
		temp->Prev = tail;              
		tail->Next = temp;             
		tail = temp;                   
	}
	else //Если список пустой
	{
		temp->Prev = NULL;              
		head = tail = temp;             
	}
}
