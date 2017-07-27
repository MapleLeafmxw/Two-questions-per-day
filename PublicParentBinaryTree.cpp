#include <iostream>
using namespace std;
#include<assert.h>

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(T value)
	:_value(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	{}

	T _value;
	BinaryTreeNode* _pLeft;
	BinaryTreeNode* _pRight;
};

template<class T>
class BinaryTree
{
public:
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree(T arr[], int size, T invalue)
	{
		int index = 0;
		CreatBinaryTree(arr, _pRoot, size, index, invalue);
	}

	T GetCommonAncestor(T p, T q)
	{
		Node* temp;
		if (temp = _GetCommonAncestor(_pRoot, q, p))
		{
			return temp->_value;
		}
		return -1;
	}

	bool Find(T invalue)
	{
		return _Find(_pRoot, invalue);
	}
private:
	void CreatBinaryTree(T arr[], Node*& pRoot, int size, int& index, T invalue)
	{
		if (size > index && arr[index] != invalue)
		{
			pRoot = new Node(arr[index]);
			CreatBinaryTree(arr, pRoot->_pLeft, size, ++index, invalue);
			CreatBinaryTree(arr, pRoot->_pRight, size, ++index, invalue);
		}
	}

	Node* _GetCommonAncestor(Node* pRoot, T& q, T& p)
	{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->_value == q || pRoot->_value == p)
		return pRoot;
	bool qLeft;
	bool qRight;
	bool pLeft;
	bool pRight;

	qLeft = _Find(pRoot->_pLeft, q);
	qRight = _Find(pRoot->_pRight, q);
	pLeft = _Find(pRoot->_pLeft, p);
	pRight = _Find(pRoot->_pRight, p);
	if (qLeft && pLeft)
		return _GetCommonAncestor(pRoot->_pLeft, q, p);
	else if (qRight && pRight)
		return _GetCommonAncestor(pRoot->_pRight, q, p);
	else if (qLeft && pRight || qRight && pLeft)
		return pRoot;
	else
		assert(false);//两个节点中至少一个不在树里
	}

	bool _Find(Node* pRoot, const T& value)
	{
		if (pRoot == NULL)
			return false;
		if (pRoot->_value == value)
			return true;
		if (true == _Find(pRoot->_pLeft, value))
			return true;
		if (true == _Find(pRoot->_pRight, value))
			return true;
		return false;
	}

private:
	Node* _pRoot;
};

int main()
{
	//char* pStr = "124#78##9###35##6";
	char* pStr = "124###35##6";
	BinaryTree<char> b1(pStr, strlen(pStr), '#');
	//cout << b1.Find('9') << endl;
	cout << b1.GetCommonAncestor('3', '6') << endl;
	return 0;
}

