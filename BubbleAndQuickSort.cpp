#include <iostream>
using namespace std;

template<class T>
void BubbleSort(T arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		bool flag = true;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = false;
			}
		}
		if (flag)

			break;
	}
}

template<class T>
void QuickSort(T arr[], int first, int last)
{
	if (arr == NULL || first > last)
		return;
	int begin = first;
	int end = last;
	int key = arr[end];
	while (begin < end)
	{
		while(begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			std::swap(arr[begin], arr[end]);
	}
	if (begin != last)
		std::swap(arr[begin], arr[last]);
	QuickSort(arr, first, begin - 1);
	QuickSort(arr, begin + 1, last);
}



template<class T>
int _QuickSort(int arr[], int first, int last)
{
	int begin = first;
	int end = last;
	int key = arr[end];
	if (first < last)
	{
		while (begin < end)
		{
			while (begin < end && arr[begin] <= key)
				begin++;
			while (begin < end && arr[end] >= key)
				end--;
			if (begin < end)
				std::swap(arr[begin], arr[end]);
		}
		if (begin != last)
			std::swap(arr[begin], arr[last]);
	}
	return begin;
}

#include <stack>
template<class T>
void QuickSortNor(T arr[], int first, int last)
{
	if (arr == NULL || first > last)
		return;
	stack<T> s;
	s.push(first);
	s.push(last);
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();
		if (begin < end)
		{
			int mid = _QuickSort<T>(arr, begin, end);
			s.push(begin);
			s.push(mid - 1);

			s.push(mid + 1);
			s.push(last);
		}
	}

}


int main()
{
	int arr[] = { 2, 6, 4, 7, 3, 11, 5, 9, 13 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort<int>(arr, len);
	//QuickSort<int>(arr, 0, len - 1);
	QuickSortNor<int>(arr, 0, len - 1);
	return 0;
}