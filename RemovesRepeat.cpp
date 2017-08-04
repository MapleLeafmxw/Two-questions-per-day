#include <iostream>
using namespace std;

int main()
{
	char arr[] = "bbcacdww";
	char newarr[26];
	int i = 0;
	for (; i < strlen(arr); i++)
	{
		newarr[arr[i]]++;
	}
	int countchar = 0;
	int count = 0;
	for (i = 0; i < strlen(arr); i++)
	{
		if (newarr[arr[i]] > 1)
		{
			newarr[arr[i]]--;
		}
		else if (newarr[arr[i]] == 1)
		{
			arr[count] = arr[i];
			count++;
		}
	}
	arr[count] = 0;
	return 0;
}