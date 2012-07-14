#include <iostream>
#include "LinkedList.h"


using namespace std;


int main ()
{
	
	LinkedList<int> list;

	list.PushFront(34);



	unsigned int size = list.GetLength();
	cout<<*(list.begin());

	for (LinkedList<int>::ListIterator it = list.begin(); it!=list.end(); ++it)
		cout<<*it<<" ";

	system("PAUSE");
	
	return 0;
}