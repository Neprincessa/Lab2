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
template <class T>
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
		typeMode = -2;
	};
	~List();
	void SetList(); //���� ������
	void AddNode(T);
	void Show();//������ ������
	void SelectCurrentOrder(int index); //��������� ���������
	int GetAmount();//��������� ���������� ��������� � ������
	int GetMode();//��������� ������
	void InsertSort();//���������� ���������
	void mergeSort();//���������� ��������
	void TestInserSort();//���� ���������� ���������
	void TestMergeSort();//���� ���������� ��������
	void TestSelection(string s); //���� ��������� ���������
	Node<T>*  returnHead();
	void sort();
private:
	void sort(Node<T>* &theHead);//������������ ������ ��� ������� 
	Node<T>* sortedMerge(Node<T>* a, Node<T>* b); //������� ���� ��������������� ������� � ���� ���������������
	void frontBackSplit(Node<T>* theHead, Node<T>* &frontRef, Node<T>* &backRef); //��������� �� ���������
	
	bool IfInt_List(char *p); //�������� �� ��� ��������� ������
};


#include "Templ_impl.h"
#endif  // !_TEMPL__T__