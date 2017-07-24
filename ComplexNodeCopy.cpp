#include <iostream>
using namespace std;


typedef struct ComplexNode{

	ComplexNode(int data)
	:_data(data)
	, _next(NULL)
	, _random(NULL)
	{}

	int _data; // 数据 

	struct ComplexNode * _next; // 指向下一个节点的指针 

	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 

}ComplexNode;


ComplexNode* ComplexNodeCopy(ComplexNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ComplexNode* pCur = pHead;
	while (pCur)
	{
		ComplexNode* pNew = new ComplexNode(pCur->_data);
		pNew->_next = pCur->_next;
		pCur->_next = pNew;
		pCur = pNew->_next;
	}
	pCur = pHead;
	while (pCur->_next)
	{
		ComplexNode* temp = NULL;
		if (pCur->_next->_random == NULL)
		{
			temp = pCur->_next;
			temp->_random = pCur->_random->_next;
		}
		pCur = pCur->_next;
	}
	pCur = pHead->_next;
	ComplexNode* pNode = pCur;
	while (pHead)
	{
		pHead->_next = pCur->_next;
		if (pCur->_next == NULL)
			break;
		pCur->_next = pHead->_next->_next;
		pHead = pHead->_next;
		pCur = pCur->_next;
	}
	return pNode;
}

void test1()
{
	ComplexNode* pHead;
	ComplexNode* a1 = new ComplexNode(1);
	ComplexNode* a2 = new ComplexNode(2);
	ComplexNode* a3 = new ComplexNode(3);
	ComplexNode* a4 = new ComplexNode(4);
	ComplexNode* a5 = new ComplexNode(5);
	pHead = a1;
	a1->_next = a2;
	a1->_random = a3;
	a2->_next = a3;
	a2->_random = a2;
	a3->_next = a4;
	a3->_random = a1;
	a4->_next = a5;
	a4->_random = a2;
	a5->_random = a4;
	ComplexNode* pCur = ComplexNodeCopy(pHead);
}

int main()
{
	test1();
	return 0;
}