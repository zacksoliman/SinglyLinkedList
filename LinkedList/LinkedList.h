#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include<iostream>
#include<iterator>


template<typename T> class LinkedList;

///*******Node class*******///
template<typename T>
class ListNode
{
private:
	ListNode():next(NULL) {};
	friend class LinkedList<T>;
	T data;
	ListNode<T>* next;
};


template <typename T>
class LinkedList
{
public:
	
	////*********Iterator Class*********////
	class ListIterator : public std::iterator<std::forward_iterator_tag, T>
	{
	public:
		ListIterator():currPos(NULL) {};
		//operators
		void operator++() {currPos = currPos->next;};
		void operator++(int) {currPos = currPos->next;};
		bool operator!=(ListIterator rval){ return (currPos != rval.currPos); }
		bool operator==(ListIterator rval){ return (currPos == rval.currPos); }
		T operator*() {return currPos->next->data;};
		T* operator->() {return &(currPos->next->data);};
		ListIterator& operator=(ListIterator& rval)
		{
			if (this->currPos == rval.currPos)
				return *this;
			this->currPos = rval.currPos;
			return *this;
		};

	private:
		ListNode<T>* currPos;
		friend class LinkedList<T>;
		ListIterator(ListNode<T>* value):currPos(value) {};
	};


	//Constructor
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

	//Destructor
	~LinkedList(void) {DeleteList(); delete head;};


	//*** List Manipulation Methods ***//
	//Removes the element that is pointed to by the iterator
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

	//remove first element of the list
	void DeleteFirst(void)
	{
		ListNode<T>* temp;
		temp = head->next;
		head->next = head->next->next;
		delete temp;
	};

	//deletes the entire list
	void DeleteList(void)
	{
		ListNode<T>* temp;
		while(head->next != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
			--length;
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