#include <stdio.h>

#include <vector>

using namespace std;
void Merge(vector<int>& nums, int begin, int half, int end)
{
	int n1, n2;
	int *left = NULL, *right = NULL;

	n1 = half - begin + 1;
	n2 = end - half;

	left = (int *)malloc(sizeof(int) * n1);
	right = (int *)malloc(sizeof(int) * n2);

	for (int i = 0; i < n1; i++)
	{
		left[i] = nums[begin + i];

	}
	for (int j = 0; j < n2; j++)
	{
		right[j] = nums[half + 1 + j];
	}

	int k = begin;
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (left[i] > right[j])
		{
			nums[k++] = right[j++];
		}
		else
		{
			nums[k++] = left[i++];
		}
	}
	for (; i < n1; i++)
	{
		nums[k++] = left[i];
	}
	for (; j < n2; j++)
	{
		nums[k++] = right[j];
	}
}

void MergeSort(vector<int>& nums, int begin, int end)
{
	int half = (end - begin) / 2;
	if (begin < end){
		MergeSort(nums, begin , begin + half);
		MergeSort(nums, begin + half + 1, end);
		Merge(nums, begin, begin + half, end);
	}
}

void InsertionSort(vector<int>& nums, int n)
{
	int key;
	//插入排序
	//每一个pass，在有序数列0 - i-1 中插入第i个元素
	for (int i = 1; i < n; ++i)
	{
		key = nums[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[j] >= key)
			{
				//比key大的向前挪一位
				nums[j + 1] = nums[j];
				if (j == 0) nums[j] = key;
			}
			else
			{
				nums[j + 1] = key;
				break;
			}

			
		}
	}
}

int main(){

	vector<int> a = { 4, 2, 8, 33, 14, 11, 24, 55, 1, 34 };
	MergeSort(a, 0,a.size() - 1);
	return 0;
} 