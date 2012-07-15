#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include<iostream>
#include<iterator>

//I need a forward declaration or do I ???
template<typename T> class LinkedList;

///*******Node class*******///
///*********START*********///

template<typename T>
class ListNode
{
private:
	ListNode():next(NULL) {};
	friend class LinkedList<T>;
	T data;
	ListNode<T>* next;
};

///*******Node class*******///
///**********END**********///


///***Linked List Implementation ***///
template <typename T>
class LinkedList
{
public:
	////*********Iterator Class*********////
	////*************START*************////
	class ListIterator : public std::iterator<std::forward_iterator_tag, T>
	{
	public:
		friend class LinkedList<T>;
		ListIterator(ListNode<T>* value):currPos(value) {};
		ListIterator():currPos(NULL) {};

		//operators
		void operator++() {currPos = currPos->next;};
		void operator++(int) {currPos = currPos->next;};
		bool operator!=(ListIterator rval){ return (currPos != rval.currPos); }
		bool operator==(ListIterator rval){ return (currPos == rval.currPos); }

		T operator*() {return currPos->next->data;};
		T* operator->() {return &(currPos->next->data);};

	private:
		ListNode<T>* currPos;
	};

	////*********Iterator Class*********////
	////**************END***************////

	//Destructor & constructor... pretty basic stuff
	LinkedList(void): length(0)
	{
		try{
			head = new ListNode<T>;
			tail = head;
			head->next = NULL;
		}catch(bad_alloc& exc){
			cout<<"Memory allocation failed";
		}
	};
	~LinkedList(void) {ClearList(); delete head;};


	//*** List Manipulation Methods ***//

	//Removes an element... this comment was pointless
	void Remove(const ListIterator& it)
	{
		if (!IsEmpty()){
			ListNode<T>* temp = NULL;
			temp = it.currPos->next;
			it.currPos->next = it.currPos->next->next;
			delete temp;
			--length;
		}
	};

	//inserts an element after our position, returns false if it fails
	bool InsertAfter(const ListIterator& it, const T& data)
	{
		if (!IsEmpty()){
			try {
				ListNode<T>* newNode = new ListNode<T>;
				newNode->data = data;
				newNode->next = it.currPos->next->next;
				it.currPos->next->next = newNode;
				++length;
				return true;
				}
			catch(bad_alloc& exc){
					return false;
			}
		}else
			return;
	};

	//inserts an element before our current position, returns false if it fails
	void InsertBefore(const ListIterator& it, const T& data)
	{
		if (!IsEmpty()){
			try {
				ListNode<T>* newNode = new ListNode<T>;
				newNode->data = data;
				newNode->next = it.currPos->next;
				it.currPos->next = newNode;
				++length;
				return true;
			}catch(bad_alloc& exc){
					return false;
			}else
				return;
		}
	};

	void ClearList(void)
	{
		ListNode<T>* temp;
		while(head->next != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	};


	//Add an element to the front of the list, returns false if it fails
	bool PushFront(const T& data)
	{
		try {
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = data;
			newNode->next = head->next;

			if ( tail == head )	tail = newNode;	

			head->next = newNode;
			
			++length;
			return true;

		}catch(bad_alloc& exc){
				return false;
			}
	};

	//Add an element to the back of the list, returns false if it fails
	bool PushBack(const T& data)
	{
		try {
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = data;
			newNode->next = NULL;

			if ( tail == head ){ 
				tail = newNode;
				head->next = newNode;
			}else{
				tail->next = newNode;
				tail = newNode;
			}

			++length;
			return true;
		}catch(bad_alloc& exc){
				return false;
			}
	};

	//********Accessors********//

	unsigned int GetLength(void) {return length;};
	bool IsEmpty(void) { return (length == 0); };
	T FirstElement() {return head->next->data;};

	//** Get relevant positions **//
	ListIterator begin(void) {return ListIterator(head); };
	ListIterator end(void) {return ListIterator(tail); };

private:

	ListNode<T>* head;		//keeps track of the first element of the list
	ListNode<T>* tail;		//keeps traks of the last element in the list
	unsigned int length;	//length of the list

};
#endif