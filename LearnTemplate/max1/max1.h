#pragma once
#include <type_traits>

//一个简单的函数模板
template <typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

//推导返回类型
template <typename T1,typename T2>
auto max2(T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
{
	return b < a ? a : b;
}

//返回类型为公共类型
template <typename T1, typename T2>
typename std::common_type<T1,T2> max3(T1 a, T2 b)
{
	return b < a ? a : b;
}

template <typename T1,typename T2, typename RT>
RT max4(T1 a, T2)
{

}
