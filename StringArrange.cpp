#include <iostream>
using namespace std;


void _permutation(char* pStr, char* begin)
{
	if (*begin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCur = begin; *pCur != '\0'; ++pCur)
		{
			char temp = *pCur;			
			*pCur = *begin;
			*begin = temp;

			_permutation(pStr, begin + 1);

			temp = *pCur;
			*pCur = *begin;
			*begin = temp;
		}
	}
}

void permutation(char* pStr)
{
	if (pStr == NULL)
		return;
	_permutation(pStr, pStr);
}

int main()
{
	char pStr[] =  "ABCD";
	permutation(pStr);
	return 0;
}