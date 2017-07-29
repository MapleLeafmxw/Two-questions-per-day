#include <iostream>
using namespace std;

bool Find(int* arr, int row, int col, int number)
{
	bool found = false;
	int i = 0;
	int j = col - 1;
	while (i < row && j <= col)
	{
		if (arr[i*col + j] > number)
			j--;
		else if (arr[i*col + j] < number)
			i++;
		else
		{
			found = true;
			break;
		}
	}
	return found;
}

int main()
{
	int arr[][4] = {1, 2, 8, 9,
				 2, 4, 9, 12,
				 4, 7, 10, 13,
				 6, 8, 11, 15};
	cout << Find(*arr, 4, 4, 20) << endl;
	return 0;
}