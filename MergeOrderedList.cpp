#include <iostream>
using namespace std;
#include <assert.h>

typedef struct ListNode
{
	ListNode(int value)
	:_value(value)
	, _next(NULL)
	{}

	int _value;
	ListNode* _next;
}Node;


Node* MergeList(Node* pa, Node* pb)
{
	if (pa == NULL)
		return pb;
	if (pb == NULL)
		return pa;
	Node* pHead = NULL;
	Node* pCur = NULL;
	if (pa->_value < pb->_value)
	{
		pCur = pa;
		pa = pa->_next;
	}
	else
	{
		pCur = pb;
		pb = pb->_next;
	}
	pHead = pCur;
	while (pa != NULL && pb != NULL)
	{
		if (pa->_value < pb->_value)
		{
			pCur->_next = pa;
			pa = pa->_next;
		}
		else
		{
			pCur->_next = pb;
			pb = pb->_next;
		}
		pCur = pCur->_next;
	}
	if(pa == NULL)
	{
		pCur->_next = pb;
	}
	if(pb == NULL)
	{
		pCur->_next = pa;
	}
	return pHead;
}


void test1()
{
	Node* pHead1;
	Node* a1 = new Node(1);
	Node* a2 = new Node(4);
	Node* a3 = new Node(6);
	Node* a4 = new Node(7);
	Node* a5 = new Node(10);
	pHead1 = a1;
	a1->_next = a2;
	a2->_next = a3;
	a3->_next = a4;
	a4->_next = a5;

	Node* pHead2;
	Node* a6 = new Node(2);
	Node* a7 = new Node(3);
	Node* a8 = new Node(9);
	Node* a9 = new Node(11);
	Node* a10 = new Node(19);
	pHead2 = a6;
	a6->_next = a7;
	a7->_next = a8;
	a8->_next = a9;
	a9->_next = a10;
	Node* pCur = MergeList(pHead1, pHead2);
}



int main()
{
	test1();
	return 0; 
}