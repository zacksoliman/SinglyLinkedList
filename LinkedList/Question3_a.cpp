#include <iostream>
#include<ctime>
#include "LinkedList.h"
#include "timer.h"
#include "MergeSort.h"

using namespace std;

void sortList(LinkedList<int>& list);

int main ()
{
	srand(time(NULL));

	timer time;
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
	
	time.StartTimer();
	list = MergeSort(list);
	double timeElapsed = time.GetTime();

	cout<<"Sorted List:\n";

	for (it = list.begin(); it!=list.end(); ++it){
		cout<<*it<<" ";
	};
	
	cout<<endl<<"It took: "<< timeElapsed <<" miliseconds"<<endl;

	system("PAUSE");
	

	return 0;
}
