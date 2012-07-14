#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include<iostream>
#include<iterator>

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
	LinkedList(void): length(0), head(new ListNode<T>), tail(head){};
	~LinkedList(void)
	{
		///****TO DO***///
	};


	//*** List Manipulation Methods ***//

	void Remove(ListIterator& it)
	{
		ListNode<T>* temp = NULL;
		temp = it.currPos->next;
		it.curPos->next = it.curPos->next->next;
		delete temp;
	};

//	void InsertAfter(ListNode<T>* n);
//	void InsertBefore(ListNode<T>* n);


	//Add an element to the fornt of the list, returns false if it fails
	bool AddInFront(const T& data)
	{
		try {
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = data;
			newNode->next = head->next;

			if ( tail == head ){
				tail = newNode;
				newNode->next = NULL;
			}
			head->next = newNode;
			++length;
			return true;
		}
			catch(bad_alloc& exc){
				return false;
			}
	};

	bool AddToBack(const T& data)
	{
		ListNode<T>* newNode = new ListNode<T>;
		newNode->next = NULL;
		newNode->data = data;
		tail = newNode;

		return true;
	};

	//removes first element of the list
	void RemoveFront(void)
	{
		if (!IsEmpty()){
			ListNode<T>* temp = NULL;
			temp = head;
			head = temp->next;
			delete temp;
			--length;
		}else
			return;
	};


	//********Accessors********//

	unsigned int GetLength(void) {return length;};
	bool IsEmpty(void) { return (length == 0); };
	T FirstElement() {return head->data;};
	T LastElement() {return tail->data;};

	//** Get relevant positions **//
	ListIterator begin(void) {return ListIterator(head); };
	ListIterator end(void) {return ListIterator(tail); };

private:

	ListNode<T>* head;		//keeps track of the first element of the list
	ListNode<T>* tail;		//keeps traks of the last element in the list
	unsigned int length;	//length of the list

};

#endif