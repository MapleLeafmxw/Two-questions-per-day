#include <iostream>
using namespace std;


typedef struct ListNode
{
	ListNode(int value)
	:_value(value)
	, _next(NULL)
	{}

	int _value;
	ListNode* _next;
}Node;


Node* JudgeBand(Node* pHead)
{
	if (pHead == NULL)
		return NULL;
	Node* pFast = pHead;
	Node* pSlow = pHead;
	while (pFast && pFast->_next)
	{
		pFast = pFast->_next->_next;
		pSlow = pSlow->_next;
		if (pFast == pSlow)
			return pFast;
	}
	return NULL;
}

size_t SizeOfBand(Node* pHead)
{
	if (pHead == NULL)
		return 0;
	Node* pMeet = JudgeBand(pHead);
	if (pMeet == NULL)
		return 0;
	size_t count = 1;
	Node* pCur = pMeet;
	while (pCur->_next != pMeet)
	{
		count++;
		pCur = pCur->_next;
	}
	return count;
}

Node* EntranceNode(Node* pHead)
{
	if (pHead == NULL)
		return NULL;
	Node* pCur = JudgeBand(pHead);
	if (pCur == NULL)
		return NULL;
	while (pCur != pHead)
	{
		pCur = pCur->_next;
		pHead = pHead->_next;
	}
	return pCur;
}

void test1()
{
	Node* pHead;
	Node* a1 = new Node(1);
	Node* a2 = new Node(2);
	Node* a3 = new Node(3);
	Node* a4 = new Node(4);
	Node* a5 = new Node(5);
	Node* a6 = new Node(6);
	pHead = a1;
	a1->_next = a2;
	a2->_next = a3;
	a3->_next = a4;
	a4->_next = a5;
	a5->_next = a6;
	a6->_next = a3;
	Node* pCur = JudgeBand(pHead);
	if (pCur == NULL)
	{
		printf("²»´ø»·\n");
	}
	size_t count = SizeOfBand(pHead);
	pCur = EntranceNode(pHead);
}


int main()
{
	test1();
	return 0;
}