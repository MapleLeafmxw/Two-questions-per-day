#include <stdio.h>

typedef void(*FUN)();

struct A
{
	FUN _fun;
	int _a;
};

struct B
{
	A _a_;
	int _b;
};

void _fa()
{
	printf("A::_fa()\n");
}
void _fb()
{
	printf("B::_fb()\n");
}


int main()
{
	A a;
	a._fun = _fa;
	B b;
	b._a_._fun = _fb;
	a._fun();
	b._a_._fun();
	A *pa = &a;
	pa->_fun();
	pa = (A*)&b;
	pa->_fun();
	return 0;
}