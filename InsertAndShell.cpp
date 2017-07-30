#include <iostream>
using namespace std;
#include <assert.h>


template<class T>
void InsertSort(T arr[], int len)
{
	assert(arr && len != 0);
	int end = 0;
	int i = 1;
	while (i < len )
	{
		end = i - 1;
		T key = arr[i];
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
		i++;
	}
}

template<class T>
void ShellSort(T arr[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int i = gap;
		while (i < size)
		{
			
			int end = i - gap;
			int key = arr[i];
			while ( end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
			i++;
		}
	}
}

int main()
{
	int arr[] = { 2, 1, 4, 9, 3, 6, 8, 7, 0, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//InsertSort<int>(arr, len);
	ShellSort<int>(arr, len);
	return 0;
}