#include <iostream>
using namespace std;


int main()
{
	int arr[] = { 2, 6, 2, 2, 4, 2, 1, 3, 2, 2, 7, 4, 6, 2, };
	int arrlen = sizeof(arr) / sizeof(arr[0]);
	int hash[10] = {0};
	int hashlen = sizeof(hash) / sizeof(hash[0]);
	for (int i = 0; i < arrlen; i++)
		hash[arr[i]]++;
	for (int i = 0; i < hashlen; i++)
	{
		if (hash[i] >= (arrlen>>1))
			printf("%d", i);
	}
	return 0;
}