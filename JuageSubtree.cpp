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
		CreatBinaryTree(arr, _pRoot, size, index, invalue);
	}
public:
	void CreatBinaryTree(T arr[], Node*& pRoot, int size, int& index, T invalue)
	{
		if (size > index && arr[index] != invalue)
		{
			pRoot = new Node(arr[index]);
			CreatBinaryTree(arr, pRoot->_pLeft, size, ++index, invalue);
			CreatBinaryTree(arr, pRoot->_pRight, size, ++index, invalue);
		}
	}

	bool IsSubTree(Node* pRoot1, Node* pRoot2)
	{
		bool result = false;
		if (pRoot1 && pRoot2)
		{
			if (pRoot1->_value == pRoot2->_value)
				result =  _IsSubTree(pRoot1, pRoot2);
			if (!result)
				result = IsSubTree(pRoot1->_pLeft, pRoot2);
			if (!result)
				result = IsSubTree(pRoot1->_pRight, pRoot2);
		}
		return result;
	}

	bool _IsSubTree(Node* pRoot1, Node* pRoot2)
	{
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		if (!(pRoot1->_value == pRoot2->_value))
			return false;

		return _IsSubTree(pRoot1->_pLeft, pRoot2->_pLeft)
			&& _IsSubTree(pRoot1->_pRight, pRoot2->_pRight);
	}

	Node* _pRoot;
};

int main()
{
	char* pStr1 = "124#78##9###35##6";
	char* pStr2 = "4#78";
	BinaryTree<char> b1(pStr1, strlen(pStr1), '#');
	BinaryTree<char> b2(pStr2, strlen(pStr2), '#');
	cout<<b1.IsSubTree(b1._pRoot, b2._pRoot);
	return 0;
}