#include <iostream>
using namespace std;

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
		_CreateBinaryTree(arr, _pRoot, size, index, invalue);
	}
	size_t GetLeefCount()
	{
		return _GetLeefCount(_pRoot);
	}
	size_t GetKLeefCount(int K)
	{
		return _GetKLeefCount(_pRoot, K);
	}
private:

	size_t _GetLeefCount(Node* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
			return 1;
		return _GetLeefCount(pRoot->_pLeft) + _GetLeefCount(pRoot->_pRight);
	}

	size_t _GetKLeefCount(Node* pRoot, int K)
	{
		if (pRoot == NULL)
			return 0;
		if (K == 1)
			return 1;
		return _GetKLeefCount(pRoot->_pLeft, K - 1) + _GetKLeefCount(pRoot->_pRight, K - 1);
	}

	void _CreateBinaryTree(T arr[], Node*& pRoot, int size, int& index, const T& invalue)
	{
		if (size > index && arr[index] != invalue)
		{
			pRoot = new Node(arr[index]);
			_CreateBinaryTree(arr, pRoot->_pLeft, size, ++index, invalue);
			_CreateBinaryTree(arr, pRoot->_pRight, size, ++index, invalue);
		}
	}
private:
	Node* _pRoot;
};



int main()
{
	char* pStr = "124###35##6";
	BinaryTree<char> b1(pStr, strlen(pStr), '#');
	cout << b1.GetLeefCount() << endl;
	cout << b1.GetKLeefCount(2) << endl;
	return 0;
}