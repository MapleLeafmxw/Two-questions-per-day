#include <iostream>
using namespace std;

void PrintMatrixInCircle(int arr[][4], int row, int col, int start)
{
	int endx = row - 1 - start;
	int endy = col - 1 - start;
	for (int i = start; i <= endx; i++)
	{
		cout << arr[start][i] << " ";
	}
	if (start < endy)
	{
		for (int i = start + 1; i <= endy; i++)
		{
			cout << arr[i][endx] << " ";
		}
	}
	if (start < endx)
	{
		for (int i = endx - 1; i >= start; i--)
		{
			cout << arr[endy][i] << " ";
		}
	}
	if (start < endy)
	{
		for (int i = endx - 1; i >= start + 1; --i)
		{
			cout << arr[i][start] << " ";
		}
	}
}

void PrintMatrixClockwisely(int arr[][4], int row, int col)
{
	if (arr == NULL || row <= 0 || col <= 0)
	{
		return;
	}
	int start = 0;
	while (row > start * 2 && col > start * 2)
	{
		PrintMatrixInCircle(arr, row, col, start);
		start++;
	}
}

int main()
{
	int arr[][4] = { 1, 2, 3, 4,
					5, 6, 7, 8,
					9, 10, 11, 12,
					13, 14, 15, 16 };
	PrintMatrixClockwisely(arr, 4, 4);
	return 0;
}