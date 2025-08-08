#include "stack.h"
#include <string>

int main(int argc,char* argv[])
{
	Stack<string> stringStack;
	stringStack.push("hello");
	std::cout << "stringStack:" << stringStack.top() << std::endl;


	TestClass<int, int, int> tc1;
	tc1.func(100,100,100);
	TestClass<int, double, double> tc2;
	tc2.func(100,100.2,20.2);
	TestClass<string, int, double> tc3;
	tc3.func("hello", 100, 20.2);
	int* pI = new int(1000);
	TestClass<int*, int*, int*> tc4;
	tc4.func(pI, pI, pI);
	delete pI;
	pI = nullptr;
	return 0;
}
