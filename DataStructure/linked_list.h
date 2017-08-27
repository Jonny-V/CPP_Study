#pragma once

#include<iostream>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//链表的节点
template<class T>
class node {
public:
	node()
	{
		element = T();
		next = nullptr;
	}

private:
	T element;
	node *next;
};

template<class T>
class Linked_List {
	friend class node<T>;
public:
	Linked_List()
	{
		length = 0;
		List = nullptr;
	}
	~Linked_List()
	{
		
	}
	bool isEmpty();
	bool isLast(Linked_List *);
	Linked_List *find(T);
	void deleteEle(T);
	Linked_List *findPre(T);
	void add(T);
	void insert(T, Linked_List *);
	void deleteList();
	void printList();

private:
	int length;
	node<T> *List;
};


template<class T>
bool Linked_List<T>::isEmpty()
{
	if (next == nullptr)
		return true;
	else
		return false;
}

template<class T>
bool Linked_List<T>::isLast(Linked_List *p)
{
	if (p->next == nullptr)
		return true;
	else
		return false;
}

template<class T>
Linked_List<T> *Linked_List<T>::find(T key)
{
	Linked_List *temp = new Linked_List();
	temp = next;
	while (temp != nullptr)
	{
		if (temp->element == key)
		{
			return temp;
			break;
		}
		else
			temp = temp->next;
	}
	if (temp == nullptr)
		return temp;
	delete temp;
}

template<class T>
void Linked_List<T>::deleteEle(T key)
{
	Linked_List *p = new Linked_List();
	p = findPre(key);
	p->next = p->next->next;
	delete p;
}

template<class T>
Linked_List<T> *Linked_List<T>::findPre(T)
{
	Linked_List *p = new Linked_List();
	p = next;
	while (p->next != nullptr)
	{
		if (p->next->element == key)
		{
			return p;
			break;
		}
		else
			p = p->next;
	}
	if (p->next==nullptr)
	{
		return nullptr;
	}
	delete p;
}
template<class T>
void Linked_List<T>::insert(T key, Linked_List *pos)
{
	Linked_List *p = new Linked_List();
	p->element = key;
	p->next = pos->next;
	pos->next = p;
}

template<class T>
void Linked_List<T>::add(T key) 
{
	Linked_List *p = new Linked_List();
	Linked_List *newnode = new Linked_List();
	newnode->element = key;
	if (!isEmpty())
	{
		p = next;
		while (p->next != nullptr)
			p = p->next;
		p->next = newnode;
	}
	else
	{
		next = newnode;
	}
	delete p;
}
template<class T>
void Linked_List<T>::deleteList()
{
	~Linked_List();
}

template<class T>
void Linked_List<T>::printList()
{
	Linked_List *p = new Linked_List();
	p = next;
	while (p!=nullptr)
	{
		std::cout << p->element << "  ";
		p = p->next;
	}
	std::cout << std::endl;
}





#endif