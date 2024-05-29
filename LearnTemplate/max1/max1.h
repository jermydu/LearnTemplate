#pragma once
#include <type_traits>

//һ���򵥵ĺ���ģ��
template <typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

//�Ƶ���������
template <typename T1,typename T2>
auto max2(T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
{
	return b < a ? a : b;
}

//��������Ϊ��������
template <typename T1, typename T2>
typename std::common_type<T1,T2> max3(T1 a, T2 b)
{
	return b < a ? a : b;
}

template <typename T1,typename T2, typename RT>
RT max4(T1 a, T2)
{

}
