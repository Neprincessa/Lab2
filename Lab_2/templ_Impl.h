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

template <class T>
Node<T> *List<T>::returnHead() {
	return head;
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


void List<void*>::SetList() {

	amount = 4;

	//massive of functions
	void(*functions[])(void) =
	{
		IncreaseDebts, AddAmountOfPublications, ChangeName, ChangeSurname
	};

	for (int i = 0; i < amount; i++) {
		AddNode(functions[i]);
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

void List<void*>::Show() {
	//Show from thw tail
	cout << "The list from the end:" << endl;
	Node<void*> *temp = tail;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		cout << i << ")" << endl;
		cout<<temp->data;
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
		cout << temp->data;
		temp = temp->Next;
		cout << "\n";
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
		x =t->data.GetCurrentScores();
		curStudent.data = t->data;
		Node<Student> *b = t->Prev;
		while (b != NULL && x < b->data.GetCurrentScores())
		{
			b->Next->data = b->data;
			b = b->Prev;
		}
		if (b == NULL)
			head->data = curStudent.data;
		else
			b->Next->data = curStudent.data;
		t = t->Next;
	}
}

//amount of bublications
void List<Lecturer>::InsertSort()
{
	Node<Lecturer> *t;
	int x;
	Node <Lecturer> curLecturer;
	t = head->Next;
	while (t)
	{
		x =t->data.GetCurrentPublications();
		curLecturer.data = t->data;
		Node<Lecturer> *b = t->Prev;
		while (b != NULL && x < b->data.GetCurrentPublications())
		{
			b->Next->data = b->data;
			b = b->Prev;
		}
		if (b == NULL)
			head->data = curLecturer.data;
		else
			b->Next->data = curLecturer.data;
		t = t->Next;
	}
}

void List<void*>::InsertSort() {

	Node<void*> *t;
	void* x;
	Node <void*> curLecturer;
	t = head->Next;
	while (t)
	{
		x = t->data;
		curLecturer.data = t->data;
		Node<void*> *b = t->Prev;
		while (b != NULL && x /*<*/ > b->data)
		{
			b->Next->data = b->data;
			b = b->Prev;
		}
		if (b == NULL)
			head->data = curLecturer.data;
		else
			b->Next->data = curLecturer.data;
		t = t->Next;
	}
}
//-----------------------------------------//
//merge sort

/**
*  Perform merge sort on the this list.
*  @param theHead Node* Reference to the head
*/

template <class T>
void List<T>::sort(Node<T>* &theHead) {
	Node<T>* a = nullptr;
	Node<T>* b = nullptr;

	// Base case
	if (theHead == nullptr || theHead->Next == nullptr) {
		return;
	}

	// Split the list in half
	// For odd number of nodes, the extra node will be in the first half.
	frontBackSplit(theHead, a, b);

	// Recursively break the list down until the sublist contains 1 element (Sorted)
	sort(a);
	sort(b);

	// Merge the two sorted lists
	theHead = sortedMerge(a, b);
}

template <class T>
void List<T>::sort(){

	sort(head);

	// After the merge sort, tail pointer will be pointing to incorrect node
	// Update the tail (*** Need a better way to update tail ***)
	Node<T>* findTail = head;
	while (findTail != nullptr) {
		if (findTail->Next == nullptr) {
			tail = findTail;
		}

		findTail = findTail->Next;
	}
}



/**
*  Take 2 Node Pointers, each pointing at the head of sorted sublist,
*      merge them, and return the Node pointer to the head node of the merged list.
*  @param a Node* Pointer to the head of the first sorted list
*  @param b Node* Pointer to the head of the second sorted list
*  @return Node* head of the merged list (nullptr if both given nodes are empty)
*/

Node<Student>* List<Student>::sortedMerge(Node<Student>* a, Node<Student>* b)
{
	Node<Student>* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->data.GetCurrentDebts() <= b->data.GetCurrentDebts()) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->data.GetCurrentDebts() <= b->data.GetCurrentDebts()) {
				if (a->Next == nullptr) {
					a->Next = b;
					b->Prev = a;
					break;
				}
				a = a->Next;
			}
			else {
				Node<Student>* toAdd = b;
				b = b->Next;
				toAdd->Prev = a->Prev;
				a->Prev->Next = toAdd;
				toAdd->Next = a;
				a->Prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->data.GetCurrentDebts() <= a->data.GetCurrentDebts()) {
				if (b->Next == nullptr) {
					b->Next = a;
					a->Prev = b;
					break;
				}
				b = b->Next;
			}
			else {
				Node<Student>* toAdd = a;
				a = a->Next;
				toAdd->Prev = b->Prev;
				b->Prev->Next = toAdd;
				toAdd->Next = b;
				b->Prev = toAdd;
			}
		}
	}

	return headOfMerged;
}

Node<Lecturer>* List<Lecturer>::sortedMerge(Node<Lecturer>* a, Node<Lecturer>* b)
{
	Node<Lecturer>* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->data.GetCurrentExperience() <= b->data.GetCurrentExperience()) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->data.GetCurrentExperience() <= b->data.GetCurrentExperience()) {
				if (a->Next == nullptr) {
					a->Next = b;
					b->Prev = a;
					break;
				}
				a = a->Next;
			}
			else {
				Node<Lecturer>* toAdd = b;
				b = b->Next;
				toAdd->Prev = a->Prev;
				a->Prev->Next = toAdd;
				toAdd->Next = a;
				a->Prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->data.GetCurrentExperience() <= a->data.GetCurrentExperience()) {
				if (b->Next == nullptr) {
					b->Next = a;
					a->Prev = b;
					break;
				}
				b = b->Next;
			}
			else {
				Node<Lecturer>* toAdd = a;
				a = a->Next;
				toAdd->Prev = b->Prev;
				b->Prev->Next = toAdd;
				toAdd->Next = b;
				b->Prev = toAdd;
			}
		}
	}

	return headOfMerged;
}

Node<void*>* List<void*>::sortedMerge(Node<void*>* a, Node<void*>* b)
{
	Node<void*>* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->data <= b->data) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->data <= b->data) {
				if (a->Next == nullptr) {
					a->Next = b;
					b->Prev = a;
					break;
				}
				a = a->Next;
			}
			else {
				Node<void*>* toAdd = b;
				b = b->Next;
				toAdd->Prev = a->Prev;
				a->Prev->Next = toAdd;
				toAdd->Next = a;
				a->Prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->data <= a->data) {
				if (b->Next == nullptr) {
					b->Next = a;
					a->Prev = b;
					break;
				}
				b = b->Next;
			}
			else {
				Node<void*>* toAdd = a;
				a = a->Next;
				toAdd->Prev = b->Prev;
				b->Prev->Next = toAdd;
				toAdd->Next = b;
				b->Prev = toAdd;
			}
		}
	}

	return headOfMerged;
}
/**
*  Utility function for merge sort
*  @param frontRef Node* reference pointer that will point to the head of first sorted half
*  @param backRef Node* reference pointer that will point to the head of second sorted half
*/
template <class T>
void List<T>::frontBackSplit(Node<T>* theHead, Node<T>* &frontRef, Node<T>* &backRef)
{
	Node<T>* fast;
	Node<T>* slow;

	// If the list is empty, both front and back points to null
	// If there is only one element, front points to it and back points
	//  to null.
	if (theHead == nullptr || theHead->Next == nullptr) {
		frontRef = theHead;
		backRef = nullptr;
	}
	else {
		slow = theHead;
		fast = theHead->Next;

		// Fast advances 2 nodes while slow advances 1 node
		while (fast != nullptr) {
			fast = fast->Next;

			if (fast != nullptr) {
				slow = slow->Next;
				fast = fast->Next;
			}
		}

		// slow should be pointing right before midpoint. Split at this point
		frontRef = theHead;
		backRef = slow->Next;

		// Update the prev and next pointers
		backRef->Prev = nullptr;
		slow->Next = nullptr;
	}
}


