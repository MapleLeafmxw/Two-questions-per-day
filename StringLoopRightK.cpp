#include <iostream>
using namespace std;

void ExchangeChar(char arr[], int left, int right)
{
	if (arr == NULL || left < 0 || right < left)
		return;
	while (left < right)
	{
		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcdefg";
	int k = 0;
	cin >> k;
	int len = strlen(arr);
	ExchangeChar(arr, 0, k);
	ExchangeChar(arr, k + 1, len - 1);
	ExchangeChar(arr, 0, len - 1);
	return 0;
}