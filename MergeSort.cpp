#include <iostream>
using namespace std;

template<class T>
void Merge(T arr[], int left,int mid, int right, T* temp)
{
	int index1 = left;
	int right1 = mid;

	int index2 = mid + 1;
	int right2 = right;

	int index = left;
	while (index1 <= right1 && index2 <= right2)
	{
		if (arr[index1] <= arr[index2])
			temp[index++] = arr[index1++];
		else
			temp[index++] = arr[index2++];
	}
	while (index1 <= right1)
		temp[index++] = arr[index1++];
	while (index2 <= right2)
		temp[index++] = arr[index2++];
}

template<class T>
void _MergeSort(T arr[], int left, int right, T* temp)
{
	if (left < right)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid + 1, right, temp);
		Merge(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, (right - left + 1)*sizeof(temp[0]));
	}
}


template<class T>
void MergeSort(T arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;
	T* temp = new T[size];
	_MergeSort(arr, 0, size-1, temp);
	delete[] temp;
}


int main()
{
	int array[] = { 2, 1, 4, 9, 3, 6, 8, 7, 0, 5 };
	MergeSort<int>(array, sizeof(array) / sizeof(array[0]));
	return 0;
}