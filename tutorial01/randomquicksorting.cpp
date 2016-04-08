#include <stdio.h>   

#include <stdlib.h>   

int a[] = { 15, 56, 2, 51, 1, 59, 3 };  // 待排序数组 a   



void Swap(int *a, int *b) {    // 函数 Swap 实现两数的对调操作   

	int temp;

	temp = *a; *a = *b; *b = temp;

}



int Random(int p, int r) {        // 产生 p 和 r 之间的一个随机整数   

	int result = p + rand() % (r - p + 1);

	return result;

}



int Partition(int a[], int p, int r) {

	int i = p, j = r + 1; int x = a[p];

	// 将 <x 的元素交换到左边区域   

	// 将 >x 的元素交换到右边区域   

	while (true) {

		while (a[++i]<x&&i <= r); while (a[--j]>x&&j >= p);

		if (i >= j) break;

		Swap(&a[i], &a[j]);

	}

	a[p] = a[j]; a[j] = x; return j;

}



int RandomizedPartition(int a[], int p, int r) {

	int i = Random(p, r);

	Swap(&a[i], &a[p]);

	return Partition(a, p, r);

}



void RandomizedQuickSort(int a[], int p, int r) {

	if (p<r) {

		int q = RandomizedPartition(a, p, r);

		RandomizedQuickSort(a, p, q - 1); RandomizedQuickSort(a, q + 1, r);

	}

}