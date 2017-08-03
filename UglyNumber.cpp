#include <iostream>
using namespace std;

bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
	if (index < 0)
		return 0;
	int number = 0;
	int count = 0;
	while (count < index)
	{
		number++;
		if (IsUgly(number))
		{
			count++;
		}
	}
	return number;
}

int Min(int a, int b, int c)
{
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}

int GetUglyNumber2(int index)
{
	if (index < 0)
		return 0;
	int* pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int nextpUglyindex = 1;

	int* pMultip2 = pUglyNumber;
	int* pMultip3 = pUglyNumber;
	int* pMultip5 = pUglyNumber;
	
	while (nextpUglyindex < index)
	{
		int min = Min(*pMultip2 * 2, *pMultip3 * 3, *pMultip5 * 5);
		pUglyNumber[nextpUglyindex] = min;
		while (*pMultip2 * 2 <= pUglyNumber[nextpUglyindex])
			pMultip2++;
		while (*pMultip3 * 3 <= pUglyNumber[nextpUglyindex])
			pMultip3++;
		while (*pMultip5 * 5 <= pUglyNumber[nextpUglyindex])
			pMultip5++;

		nextpUglyindex++;
	}
	int ugly = pUglyNumber[index - 1];
	delete[] pUglyNumber;
	return ugly;
}


int main()
{
	cout << GetUglyNumber(150) << endl;
	cout << GetUglyNumber2(150) << endl;
	return 0;
}