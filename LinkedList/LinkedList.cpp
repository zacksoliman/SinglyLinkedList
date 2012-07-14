/*
#include "LinkedList.h"


template<typename T>
LinkedList<T>::LinkedList(void)
{
	
}

template<typename T>
LinkedList<T>::~LinkedList(void)
{
}

template<typename T>
bool LinkedList<T>::AddInFront(const T& data)
	{
		try { node* newNode = new node; }

		catch(std::bad_alloc& exc) {return false; }

		tail = head;
		newNode->data = data;
		newNode->next = head;
		head = newNode;

		++size;

		return true;
	}
	*/