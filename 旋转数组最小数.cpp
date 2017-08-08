#include <iostream>
using namespace std;
#include <assert.h>

int MinInOrder(int arr[], int index1, int index2)
{
	int rec = arr[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (arr[i] < rec)
			rec = arr[i];
	}
	return rec;
}

int Min(int arr[], int len)
{
	assert(arr && len > 0);
	int index1 = 0;
	int index2 = len - 1;
	int indexMid = index1;
	while (arr[index1] >= arr[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = ((index2 - index1) >> 1) + index1;
		if (arr[index1] == arr[index2] && arr[index1] == arr[indexMid])
			return MinInOrder(arr, index1, index2);
		if (arr[indexMid] >= arr[index1])
		{
			index1 = indexMid;
		}
		else if (arr[indexMid] <= arr[index2])
		{
			index2 = indexMid;
		}
	}
	return arr[indexMid];
}



int main()
{
	//int arr[] = { 3, 4, 5, 1, 2 };
	//int arr[] = { 1, 2, 3, 4, 5 };
	int arr[] = { 1, 1, 1, 1, 0, 1 };
	int rec = Min(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "旋转数组的最小数为：" << rec << endl;
	return 0;
}