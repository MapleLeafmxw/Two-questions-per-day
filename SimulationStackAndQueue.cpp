#include <iostream>
using namespace std;
#include <stack>
#include <queue>


template<class T>
class Myqueue
{
public:
	Myqueue()
	{}
	~Myqueue()
	{}

	void Add(const T& node)
	{
		s1.push(node);
	}
	T Delhead()
	{
		if (s2.empty())
		{
			while (s1.size() > 0)
			{
				T temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
		}
		T headnode = s2.top();
		s2.pop();
		return headnode;
	}

private:
	stack<T> s1;
	stack<T> s2;
};

template<class T>
class Mystack
{
public:
	Mystack()
	{}
	~Mystack()
	{}
	void Add(const T& node)
	{
		if (q1.empty() && q2.empty())
			q1.push(node);
		else if (!q1.empty())
			q1.push(node);
		else if (!q2.empty())
			q2.push(node);
	}
	T Delqueuehead()
	{
		T rec;
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				T temp = q2.front();
				q1.push(temp);
				q2.pop();
			}
			rec = q2.front();
			q2.pop();
		}
		else
		{
			while (q1.size() > 1)
			{
				T temp = q1.front();
				q2.push(temp);
				q1.pop();
			}
			rec = q1.front();
			q1.pop();
		}
		return rec;
	}
private:
	queue<int> q1;
	queue<int> q2;
};

void test1()
{
	Myqueue<int> q;
	q.Add(11);
	q.Add(12);
	q.Add(13);
	q.Add(14);
	q.Add(15);
	int rec = q.Delhead();
	rec = q.Delhead();
	q.Add(16);
	rec = q.Delhead();
	rec = q.Delhead();
	rec = q.Delhead();
	rec = q.Delhead();
}

void test2()
{
	Mystack<int> s;
	s.Add(11);
	s.Add(12);
	s.Add(13);
	s.Add(14);
	s.Add(15);
	s.Add(16);
	int rec = s.Delqueuehead();
	rec = s.Delqueuehead();
	rec = s.Delqueuehead();
	s.Add(17);
	rec = s.Delqueuehead();
	rec = s.Delqueuehead();
	rec = s.Delqueuehead();
	rec = s.Delqueuehead();
}

int main()
{
	//test1();
	test2();
	return 0;
}