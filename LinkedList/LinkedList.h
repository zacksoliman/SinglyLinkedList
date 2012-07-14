#pragma once
//steve.morse@magma.ca

struct node;

template <typename T>
class LinkedList
{
public:
	LinkedList(void) {head = NULL; tail = NULL; size = 0;};
	virtual ~LinkedList(void);

	//modify the list
	void remove(node* n)
	{

	};
	void insert(node* n);
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

