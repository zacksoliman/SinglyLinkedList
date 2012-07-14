#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include<iostream>
#include<iterator>

struct node;
/////////////////****** TO DO ******////////////////////
//													  //
// - I need to add some kind of iterator			  //		
// - I need to define a copy constructor              //
// - Also overload the '=' operator					  //
////////////////////////////////////////////////////////
template <typename T>
class LinkedList
{
public:
	LinkedList(void): length(0)
	{
		try { head = new node;}
		catch(bad_alloc& exc) 
		{
			std::cout<<"Memory allocation failed"; 
			return;
		}

		tail = head;
	};

	LinkedList(int size): length(size)
	{
		try { head = new node[size];}
		catch(bad_alloc& exc) 
		{
			std::cout<<"Memory allocation failed"; 
			return;
		}

		tail = head;
	};

	~LinkedList(void)
	{
		node* temp = NULL;

		for (size>0; --size)
		{
			temp->next = head->next;
			delete head;
			head = temp ->next;
		}

	};

	//*** List Modification ***//

	void Remove(node* n);

	void InsertAfter(node* n);
	void InsertBefore(node* n);

	void DeleteAll(void);

	//Add an element to the fornt of the list
	//returns false if it fails
	bool AddInFront(const T& data)
	{
		try { node* newNode = new node;}
		catch(std::bad_alloc& exc) {return false;}

		newNode->data = data;
		newNode->next = head;

		if ( tail == head )
			tail = head;

		head = newNode;
		++length;
		return true;
	};

	bool AddToBack(const T& data)
	{
		try { node* newNode = new node;}
		catch(std::bad_alloc& exc) {return false;}

		newNode->next = NULL;
		newNode->data = data;
		tail = newNode;

		return true;
	};

	//Delete first element of the list
	void DeleteFront(void)
	{
		if (!IsEmpty()){
			node* temp = NULL;
			temp->next = head->next;
			head->next = head->next->next;
			delete temp;
			--size;
		}else
			return;
	};


	//**Important information***//

	unsigned int GetLength(void);
	bool IsEmpty(void) { return (size == 0); };

	//** Access elements **//
	T FirstElement();
	T LastElement();

	//** Get relevant positions **//
	T* GetEndPosition(void){return tail;};
	T* GetStartPosition(void) {return head;};

private:

	node* head;
	node* tail;
	node* current;
	unsigned int length;	//length of the list

	struct node 
	{
		T data;
		node* next;
	};
	
};

#endif