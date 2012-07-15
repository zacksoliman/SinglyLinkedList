#include <iostream>
#include<ctime>
#include "LinkedList.h"

using namespace std;

void sortList(LinkedList<int>& list);

int main ()
{
	srand(time(NULL));

	LinkedList<int> list;
	LinkedList<int>::ListIterator it;

	cout<<"Input length of list: ";
	int n;
	cin >> n;

	for(int i=0; i < n ; ++i){

		list.PushFront(rand() % 100 +1);
	}

	for (it = list.begin(); it!=list.end(); ++it){
		cout<<*it<<" ";
	};

	cout<<endl;

	list.DeleteList();

	if (list.IsEmpty())
		cout<<"yeah";

	system("PAUSE");
	

	return 0;
}