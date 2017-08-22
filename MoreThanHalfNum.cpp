#include <iostream>
using namespace std;

int MoreThanHalfNum(int *arr, int length)
{
	if (arr == NULL || length < 0)
		return -1;
	int count = 1;
	int result = arr[0];
	for (int i = 1; i < length; ++i)
	{
		if (count == 1)
		{
			result = arr[i];
			count = 1;
		}
		else if (arr[i] == result)
			count++;
		else
			count--;
	}
	return result;
}


int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int rec = MoreThanHalfNum(arr, len);
	cout << rec << endl;
	return 0;
}