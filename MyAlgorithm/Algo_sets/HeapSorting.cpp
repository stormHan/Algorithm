
#include "HeapSorting.h"

Heap::Heap(vector<int> v)
{
	A.resize(v.size() + 1, 0);
	heap_size = v.size();
	arraysize = v.size();

	for (int i = 0; i < v.size(); ++i)
	{
		A[i + 1] = v[i];
	}
}

void Heap::max_heapify(int i)
{
	if (i < 1)
	{
		printf("cannot heapify as the index is not in the heap");
		exit(0);
	}

	int l = left(i);
	int r = right(i);

	int largest = i;
	if (l <= heap_size && A[l] > A[i])
		largest = l;
	if (r <= heap_size && A[r] > A[largest])
		largest = r;

	if (largest != i)
	{
		swap(A[largest], A[i]);
		max_heapify(largest);
	}
}

void Heap::build_max_heap()
{
	for (int i = heap_size / 2; i >= 1; --i)
	{
		max_heapify(i);
	}
}

vector<int> Heap::sort()
{
	build_max_heap();

	for (int i = arraysize; i >= 2; --i)
	{
		swap(A[1], A[i]);
		heap_size--;
		max_heapify(1);
	}
	return vector<int>(A.begin()+1, A.end());
}

