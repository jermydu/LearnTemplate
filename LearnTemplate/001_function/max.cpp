#include "max.h"
using namespace std;

int main()
{
	std::cout << "max(100, 200)=" << ::max(100, 200) << std::endl;
	std::cout << "max(55.2, 10.5)=" << ::max(55.2, 10.5) << std::endl;
	std::cout << "max(55, 10.5)=" << ::max<double>(55, 10.5) << std::endl;    //显示指定参数类型
	std::cout << "max2(55, 10.5)=" << ::max2(55, 10.5) << std::endl;
	std::cout << "max2(55, 60.5)=" << ::max2(55, 60.5) << std::endl;
	std::cout << "max3(55, 60.5)=" << ::max3<int>(55, 60.5) << std::endl;
	std::cout << "max4(55, 10.5)=" << ::max4(55, 10.5) << std::endl;
	std::cout << "max5(55, 10.5)=" << ::max5(55, 10.5) << std::endl;
	std::cout << "max6(55, 10.5)=" << ::max6(55, 10.5) << std::endl;
	std::cout << "max7(55.5, 10)=" << ::max7(55.5, 10) << std::endl;
	std::cout << "max8(55.5, 10)=" << ::max8(55.5, 10) << std::endl;
	std::cout << "max8(10,55.5)=" << ::max8(10,55.5) << std::endl;
	std::cout << "max9(10,55.5)=" << ::max9(10,55.5) << std::endl;
	std::cout << "max10(10,55.5)=" << ::max10(10,55.5) << std::endl;

	std::cout << "myMax(40,50)=" << ::myMax(40, 50) << std::endl;				//两个int值完全匹配非模板函数
	std::cout << "myMax(40.1,50.1)=" << ::myMax(40.1, 50.1) << std::endl;		//调用myMax<double>(通过参数推导)

	//注意：重载函数模板时，应该确保只有一个函数模板与调用匹配
	auto a = ::myMax2(4, 7.2); //使用第一个函数模板
	auto b = ::myMax2<long double>(7.2, 4); //使用第二个函数模板
	//auto c = ::myMax2<int>(4, 7.2); // ERROR:两个函数模板都可以匹配
	return 0;
}
