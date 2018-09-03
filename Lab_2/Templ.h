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
	void SetList(); //ввод данных
	void Show();//печать списка
	string SelectCurrentOrder(int index); //выделение подстроки
	int GetAmount();//получение количества элементов в списке
	int GetMode();//получение режима
	void InsertSort();//сортировка вставками
	void MergeSort();//сортировка слиянием
	void TestInserSort();//тест сортировки вставками
	void TestMergeSort();//тест сортировки слиянием
	void TestSelection(string s); //тест выделения подстроки
private:
	void sort(Node* &theHead); //формирование списка для слияния
	Node* sortedMerge(Node* a, Node* b); //слияние двух остортированных списков в один отсортированный
	void frontBackSplit(Node* theHead, Node* &frontRef, Node* &backRef); //разбиение на подсписки
	bool IfInt_List(char *p); //проверка на тип введенных данных
};

#include "Templ_impl.h"
#endif  // !_TEMPL__T__