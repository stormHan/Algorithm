/*
	Heap Sorting
	time : 2016.11.07
*/

#ifndef H_HEAPSORTING
#define H_HEAPSORTING

#include "main.h"

#define parent(i) i >> 1 
#define left(i) i << 1
#define right(i) (i << 1) + 1

class Heap
{
public:
	Heap(vector<int> v);

	void max_heapify(int i);

	//build the max heap
	void build_max_heap();

	vector<int> sort();

	void inline swap(int& a, int& b){
		int t = a; a = b; b = t;
	}


private:
	vector<int> A;
	int heap_size, arraysize;
};


#endif /* H_HEAPSORTING */