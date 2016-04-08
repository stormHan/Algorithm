#include <stdio.h>   

#include <stdlib.h>   

int a[] = { 15, 56, 2, 51, 1, 59, 3 };  // ���������� a   



void Swap(int *a, int *b) {    // ���� Swap ʵ�������ĶԵ�����   

	int temp;

	temp = *a; *a = *b; *b = temp;

}



int Random(int p, int r) {        // ���� p �� r ֮���һ���������   

	int result = p + rand() % (r - p + 1);

	return result;

}



int Partition(int a[], int p, int r) {

	int i = p, j = r + 1; int x = a[p];

	// �� <x ��Ԫ�ؽ������������   

	// �� >x ��Ԫ�ؽ������ұ�����   

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