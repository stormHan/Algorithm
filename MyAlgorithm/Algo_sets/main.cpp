#include"main.h"
#include "HeapSorting.h"

int main()
{
	vector<int> a = { 1, 4, 6, 3, 2, 1, 12, 33, 51, 2 };
	Heap h(a);
	a = h.sort();
}