#include <iostream>
using namespace std;

int main()
{
	int a = -999;
	int count = 0;
	while (a)
	{
		count++;
		a = a&(a - 1);
	}
	cout << count << endl;
	return 0;
}