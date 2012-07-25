#pragma once
#include "LinkedList.h"

//Merge function that the merge sort algorithm will use to merge two linked lists
template<typename T>
LinkedList<T> Merge(LinkedList<T> left, LinkedList<T> right )
{
	LinkedList<T>::ListIterator leftIt = left.begin();
	LinkedList<T>::ListIterator rightIt = right.begin();
	LinkedList<T> sortedList;

	while (!left.IsEmpty() && !right.IsEmpty()){
		
		if(*leftIt >= *rightIt){

			sortedList.PushBack(*rightIt);
			right.DeleteHead();
			rightIt = right.begin();

		}else if (*leftIt <= *rightIt){

			sortedList.PushBack(*leftIt);
			left.DeleteHead();
			leftIt = left.begin();
		}
	}

	if(left.IsEmpty()){

		while(!right.IsEmpty()){

			sortedList.PushBack(*rightIt);
			right.DeleteHead();
			rightIt = right.begin();
		}

	}else if(right.IsEmpty()){

		while(!left.IsEmpty()){

			sortedList.PushBack(*leftIt);
			left.DeleteHead();
			leftIt = left.begin();
		}
	}

	
	return sortedList;
}

//The MergeSort function recusivly partitions the linked lists and then merges them by calling the merge() function
template<typename T>
LinkedList<T> MergeSort (LinkedList<T> list)
{
	if (list.GetLength() <= 1)
		return list;
	
	LinkedList<T> left, right, sorted;
	LinkedList<T>::ListIterator it = list.begin();

	unsigned int midPoint = list.GetLength()/2;	//if length is odd, midPoint will be the floor of the division

	for(unsigned int i=0; i < midPoint; ++i){
	
		left.PushBack(*it);
		list.DeleteHead();
		it = list.begin();
	}


	while (list.GetLength() != 0){

		right.PushBack(*it);
		list.DeleteHead();
		it = list.begin();

	}

	left = MergeSort(left);
    right = MergeSort(right);
	
	return Merge(left, right);

}