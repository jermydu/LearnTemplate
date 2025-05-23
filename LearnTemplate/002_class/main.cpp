#include "stack.h"
#include <string>

int main(int argc,char* argv[])
{
	Stack<string> stringStack;
	stringStack.push("hello");
	std::cout << "stringStack:" << stringStack.top() << std::endl;
	return 0;
}
