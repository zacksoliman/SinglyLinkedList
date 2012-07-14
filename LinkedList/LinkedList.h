#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_
struct node;

//I need to add some kind of iterator

template <typename T>
class LinkedList
{
public:
	LinkedList(void) {head = tail = new node; size = 0;};
	LinkedList(int size): size(size){};

	~LinkedList(void);

	//modify the list
	void Remove(node* n);

	void InsertAfter(node* n);
	void InsertBefore(node* n);

	void DeleteAll(void);

	bool AddInFront(const T& data)
	{
		try { node* newNode = new node; }
		catch(std::bad_alloc& exc) {return false; }

		tail = head;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		++size;
		return true;
	};

	void DeleteFront(void)
	{
		if (size != 0){
			node* temp = NULL;
			temp->next = head->next;
			head->next = head->next->next;
			delete temp;
			--size;
		}else
			return;
	};

	//Access elements
	T GetFirstElement();
	T GetLastElement();

private:

	node* head;
	node* tail;
	node* current;

	unsigned int size;

		struct node 
	{
		T data;
		T* next;
	};
	
};

#include "LinkedList.cpp"

#endif