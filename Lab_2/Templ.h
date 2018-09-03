#ifndef  _TEMPL__T__
#define _TEMPL__T__

#include <string>
#include <iostream>
#include "Header.h"
using namespace std;



//------------------------------------------------------------------------------------------------//
class List
{
	int typeMode;
	int amount;
	Node *head;
	Node *tail;

public:
	List();
	~List();
	void SetList(); //���� ������
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
	void sort(Node* &theHead); //������������ ������ ��� �������
	Node* sortedMerge(Node* a, Node* b); //������� ���� ��������������� ������� � ���� ���������������
	void frontBackSplit(Node* theHead, Node* &frontRef, Node* &backRef); //��������� �� ���������
	bool IfInt_List(char *p); //�������� �� ��� ��������� ������
};

#include "Templ_impl.h"
#endif  // !_TEMPL__T__