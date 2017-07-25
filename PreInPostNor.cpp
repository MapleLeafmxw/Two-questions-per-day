#include <iostream>
using namespace std;
#include <stack>


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
		CreateBinaryTree(arr, _pRoot, size, index, invalue);
	}

	void PreOrderNor()
	{
		_PreOrderNor(_pRoot);
	}
	void InorderNor()
	{
		_InorderNor(_pRoot);
	}
	void PostOrderNor()
	{
		_PostOrderNor(_pRoot);
	}
private:

	void CreateBinaryTree(T arr[], Node*& pRoot, int size, int& index, T& invalue)
	{
		if (index < size && arr[index] != invalue)
		{
			pRoot = new Node(arr[index]);
			CreateBinaryTree(arr, pRoot->_pLeft, size, ++index, invalue);
			CreateBinaryTree(arr, pRoot->_pRight, size, ++index, invalue);
		}
	}

	void _PreOrderNor(Node* pRoot)
	{
		if (pRoot == NULL)
			return;
		stack<Node*> s;
		Node* pCur = NULL;
		s.push(pRoot);
		while (!s.empty())
		{
			pCur = s.top();
			s.pop();
			while (pCur)
			{
				cout << pCur->_value << " ";
				if (pCur->_pRight)
					s.push(pCur->_pRight);
				pCur = pCur->_pLeft;
			}
		}
	}
	void _InorderNor(Node* pRoot)
	{
		if (pRoot == NULL)
			return;
		stack<Node*> s;
		Node* pCur = pRoot;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->_pLeft;
			}
			pCur = s.top();
			cout << pCur->_value << " ";
			s.pop();
			pCur = pCur->_pRight;
		}
	}
	
	void _PostOrderNor(Node* pRoot)
	{
		if (pRoot == NULL)
			return;
		Node* pCur = pRoot;
		Node* pTop = NULL;
		Node* pPre = NULL;
		stack<Node*> s;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->_pLeft;
			}
			pTop = s.top();
			if (pTop->_pRight == NULL || pTop->_pRight == pPre)
			{
				cout << pTop->_value << " ";
				pPre = pTop;
				s.pop();
			}
			else
				pCur = pTop->_pRight;
		}
	}

private:
	Node* _pRoot;
};

int main()
{
	char* pStr = "124###35##6";
	BinaryTree<char> b1(pStr, strlen(pStr), '#');
	//b1.PreOrderNor();
	//b1.InorderNor();
	b1.PostOrderNor();
	return 0;
}