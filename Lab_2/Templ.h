#ifndef  _TEMPL__T__
#define _TEMPL__T__

#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

template <class T>
struct Node
{
	T data;
	Node *Next, *Prev;
};

//------------------------------------------------------------------------------------------------//
template <typename T>
class List
{
	int typeMode;
	int amount;
	Node<T> *head;
	Node<T> *tail;

public:
	List() {
		head = nullptr;
		tail = nullptr;
		head->Next = nullptr;
		head->Prev = nullptr;
		typeMode = -2;
	};
	~List();
	void SetList(); //���� ������
	void AddNode(T);
	void Show();//������ ������
	string SelectCurrentOrder(int index); //��������� ���������
	int GetAmount();//��������� ���������� ��������� � ������
	int GetMode();//��������� ������
	void InsertSort();//���������� ���������
	void MergeSort();//���������� ��������
	void TestInserSort();//���� ���������� ���������
	void TestMergeSort();//���� ���������� ��������
	void TestSelection(string s); //���� ��������� ���������
private:
	void sort(Node<T>* &theHead); //������������ ������ ��� �������
	Node<T>* sortedMerge(Node<T>* a, Node<T>* b); //������� ���� ��������������� ������� � ���� ���������������
	void frontBackSplit(Node<T>* theHead, Node<T>* &frontRef, Node<T>* &backRef); //��������� �� ���������
	bool IfInt_List(char *p); //�������� �� ��� ��������� ������
};

#include "Templ_impl.h"
#endif  // !_TEMPL__T__