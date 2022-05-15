#pragma once
#ifndef LinkedList_H
#include<iostream>
//#include"RBtree.h"
template <class T>
class List
{
private:
	class ElemList
	{
	public:
		ElemList(const T& value=0, ElemList* next=NULL, ElemList* prev = NULL) :data(value), next(next), prev(prev)
		{}
		//ElemList(T value):
		~ElemList() {};
		ElemList* prev;
		ElemList* next;
		T data;
	};
public:
	T& operator[](const int index);
	ElemList* head;
	ElemList* tail;
	ElemList* gethead() { return head; }
	ElemList* gettail() { return tail; }
	ElemList* getnext(ElemList* elem) { return elem->next; }
	ElemList* getprev(ElemList* elem) { return elem; }
	ElemList* getdata(ElemList* elem) { return elem->data; }
	
	List() {
		head = NULL;
		tail = NULL;
	};
	~List() {
		ElemList* cur = head;
		while (cur != NULL)
		{
			cur = cur->next;
			delete head;
			head = cur;
		}
	};
	//size_t getSize();
	void pushBack(const T& elem)
	{
		ElemList* newElem = new ElemList(elem, NULL, tail);
		if (head == NULL) { head = newElem; }
		else { tail->next = newElem; }
		tail = newElem;
	}
	void pushFront(T elem)
	{
		/*
		ElemList* hd = head;
		ElemList* newElem = new ElemList(elem, head, NULL);
		if (head == NULL) { tail = newElem; }
		else { head->next = newElem; }
		head = newElem;
		*/
	
		ElemList* newElem = new ElemList(elem, head, NULL);
		if (head == NULL) { head = newElem; tail = newElem; }
		else
		{
			ElemList* hd = head;
			newElem->next = hd;
			hd->prev = newElem;
			head = newElem;
		}
	}
	void popBack()
	{
		if (head != NULL)
		{
			ElemList* cur = tail->prev;
			delete tail;
			tail = cur;

			cur->next = NULL;
		}
		else
		{
			//throw _out_of_range("no elements");
		}
	}
	void popFront()
	{
		if (head != NULL)
		{
			ElemList* cur = head->next;
			delete head;
			head = cur;
			cur->prev = NULL;
		}
		else
		{
			//	throw out_of_range("no elements");
		}
	}
	void sort(List <T>* list, int size)
	{
		bool flag;
		auto i = list->gethead();
		auto j = list->gethead();
		for (i; i != list->gettail(); i = i->next)
		{
			j = list->gethead();
			flag = 0;
			for (j; j != list->gettail()->prev; j = j->next)
			{
				auto temp = j->next;
				if (j->data.data > temp->data.data)
				{
					//auto tmp = j->data;
					//swap(j->data, j->next->data);
					//j->data = j->next->data;
					//j->next->data = tmp;
					if (j->next == temp) { // right next to each other
						j->next = temp->next;
						temp->prev = j->prev;
						if (j->next != NULL)
							j->next->prev = j;
						else tail = j;
						if (temp->prev != NULL)
							temp->prev->next = temp;
						else  head = temp;
						temp->next = j;
						j->prev = temp;
					}
					flag = 1;
					for (int g = 0; g < size; g++) {
						std::cout << (*list)[g].data << " " << (*list)[g].key[0]; std::cout << std::endl;
					}
					std::cout << std::endl;
					j = j->prev;
				}
			}
			if (flag == 0) break;
		}

	}
	int getSize()
	{
		ElemList* cur = head; 
		int count = 0;
		while (cur != NULL) {
			count++;
			cur = cur->next;
		}
		return count;

	}
	void remove(int index)
	{
		if (index == 0) { // delete head element
			popFront();
		}
		else if (index == getSize() - 1) { // delete last element
			popBack();
		}
		else
		{
			int count = 0;
			ElemList*  cur = head;
			while (cur != NULL)
			{
				if(count+1==index)
				{
					ElemList* tmpPrev = cur;
					cur = cur->next;
					ElemList* tmp = cur;
					cur = cur->next;
					tmpPrev->next = cur;
					cur->prev = tmpPrev;
					delete tmp;
				}
				count++;
				cur = cur->next;
			}
		}
		if (index > getSize())
		{
			throw std::invalid_argument("failed to execute func remove");
		}
	}
	void clear()
	{
		~List();
	}


};

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	
	ElemList* elem = this->gethead();
	
	
	//ElemList* current = this->head;
	/*while (elem->next != NULL)
	{
		if (counter == index)
		{
			return elem->data;
		}
	//	current = current->next;
		elem=elem->next;
		counter++;t
	}*/
	int count = 0;
	while (elem != NULL) {
		if (index == count) {
			return elem->data;
		}
		count++;
		elem = elem->next;
	}
	/*
	for (int i = 0; i < getSize(); i++) {
		if (i == index)return elem->data;
		else { elem->data = NULL; return elem->data; }
		elem = elem->next; 
	}
	*/
	
}

#endif // !LinkedList_H