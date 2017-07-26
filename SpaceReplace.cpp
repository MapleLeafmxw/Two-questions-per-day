#include <iostream>
using namespace std;
#include <string.h>


void  BlakReplace(char* msg, int length)
{
	if (msg == NULL || length <= 0)
		return;
	int size = 0;
	int count = 0;
	char* pCur = msg;
	while (*pCur)
	{
		size++;
		if (*pCur == ' ')
			count++;
		pCur++;
	}
	int newlength = size + count * 2;
	int oldlength = size;
	if (newlength > length)
		return;
	while (oldlength >= 0 && oldlength < newlength)
	{
		if (msg[oldlength] == ' ')
		{
			msg[newlength--] = '$';
			msg[newlength--] = '$';
			msg[newlength--] = '$';
		}
		else
		{
			msg[newlength--] = msg[oldlength];
		}
		oldlength--;
	}
}


int main()
{
	char msg[100] = "My dream is you!";
	BlakReplace(msg, 100);
	return 0;
}