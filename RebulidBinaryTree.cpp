#include <iostream>
using namespace std;

typedef struct BinaryTreeNode
{
	BinaryTreeNode(int value)
	:_value(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	{}

	int _value;
	BinaryTreeNode* _pLeft;
	BinaryTreeNode* _pRight;
}Node;

Node* _TreeRebuild(int* startpre, int* endpre, int* startin, int* endin)
{
	Node* pRoot = new Node(startpre[0]);
	if (startpre == endpre)
	{
		if (startin == endin)
			return pRoot;
	}
	int* inorder = startin;
	while (inorder <= endin && *inorder != startpre[0])
	{
		inorder++;
	}
	int inorderlen = inorder - startin;
	if (inorderlen > 0)
	{
		pRoot->_pLeft = _TreeRebuild(startpre + 1, startpre + inorderlen, startin, endin + inorderlen - 1);
	}
	if (inorderlen < endpre - startpre)
	{
		pRoot->_pRight = _TreeRebuild(startpre + inorderlen + 1, endpre, startin + inorderlen + 1, endin);
	}
	return pRoot;
}


Node* TreeRebuild(int* Preorder, int* Inorder, int Prelength, int Inlength)
{
	if (Preorder == NULL || Inorder == NULL || Prelength != Inlength || Prelength <= 0)
		return NULL;
	_TreeRebuild(Preorder, Preorder + Prelength - 1, Inorder, Inorder + Inlength - 1);
}

int main()
{
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int Inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int Inlength = sizeof(Inorder) / sizeof(Inorder[0]);
	int Prelength = sizeof(Preorder) / sizeof(Preorder[0]);
	Node* pRoot = TreeRebuild(Preorder, Inorder, Prelength, Inlength);
	return 0;
}