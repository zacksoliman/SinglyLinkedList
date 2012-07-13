#pragma once
//steve.morse@magma.ca

template <typename T>
class LinkedList
{
public:
	LinkedList(void);
	virtual ~LinkedList(void);

	//modify the list
	void remove();
	void insert();

	void AddFront(void);
	void AddBack(void);

	void DeleteFront();

	//Access elements
	T GetFirst();
	T GetLast();

private:

	struct node 
	{
		T data;
		T* next;
	}
};

