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
	void SetList(); //ввод данных
	void AddNode(T);
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
	void sort(Node<T>* &theHead); //формирование списка для слияния
	Node<T>* sortedMerge(Node<T>* a, Node<T>* b); //слияние двух остортированных списков в один отсортированный
	void frontBackSplit(Node<T>* theHead, Node<T>* &frontRef, Node<T>* &backRef); //разбиение на подсписки
	bool IfInt_List(char *p); //проверка на тип введенных данных
};

#include "Templ_impl.h"
#endif  // !_TEMPL__T__