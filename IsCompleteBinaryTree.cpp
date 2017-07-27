#include <iostream>
using namespace std;
#include <queue>

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

	bool IsCompleteTree()
	{
		return _IsCompleteTree(_pRoot);
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

	bool _IsCompleteTree(Node* pRoot)
	{
		if (pRoot == NULL)
			return false;
		queue<Node*> q;
		bool flag = false;
		Node* pCur = NULL;
		q.push(pRoot);
		while (!q.empty())
		{
			pCur = q.front();
			q.pop();
			if (flag)
			{
				if (pCur->_pLeft || pCur->_pRight)
					flag = false;
			}
			else
			{
				if (pCur->_pLeft && pCur->_pRight)
				{
					q.push(pCur->_pLeft);
					q.push(pCur->_pRight);
				}
				else if (pCur->_pLeft)
				{
					flag = true;
				}
				else if (pCur->_pRight)
				{
					return false;
				}
				else if (pCur->_pLeft == NULL && pCur->_pRight == NULL)
				{
					flag = true;
				}
			}
		}
		return flag;
	}

private:
	Node* _pRoot;
};


int main()
{
	//char* pStr = "124#78##9###35##6";
	char* pStr = "124###35##6";
	BinaryTree<char> b1(pStr, strlen(pStr), '#');
	cout << b1.IsCompleteTree() << endl;
	return 0;
}
