
#pragma once
#include <iostream>
#include <type_traits>   //std::decay std::common_type

//简单函数模板
template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

//多模版参数函数模版 返回类型与第一个参数类型一样
template <typename T1, typename T2>
T1 max2(T1 a, T2 b)
{
	return a > b ? a : b;
}

//多模版参数函数模版 指定返回类型
template <typename RT ,typename T1, typename T2>
RT max3(T1 a, T2 b)
{
	return a > b ? a : b;
}

/************************************推导返回值类型************************************/
//C++14 自动推导返回值类型
template <typename T1, typename T2>
auto max4(T1 a, T2 b)
{
	return a > b ? a : b;
}

//C++11 自动推导返回值类型
template <typename T1, typename T2>
auto max5(T1 a, T2 b) -> decltype(a > b ? a : b)
{
	return a > b ? a : b;
}

//C++11 自动推导返回值类型 std::decay
//通用性: 这种写法适用于各种类型组合的参数，无论它们是基本类型、自定义类型、数组类型还是函数类型等。
//类型简化: 通过 std::decay，可以确保返回值类型是一个简单的、非修饰的类型，这在某些情况下（如作为模板参数或存储到容器中）非常有用。
//兼容性 : 即使参数类型比较复杂（如带修饰符的引用类型），经过 std::decay 处理后，返回值类型变得更通用和兼容。
template <typename T1, typename T2>
auto max6(T1 a, T2 b) -> typename std::decay<decltype(a > b ? a : b)>::type   //std::decay_t<decltype(a > b ? a : b)
{
	return a > b ? a : b;
}

/************************************返回值类型为公共类型************************************/
//typename std::common_type<T1, T2>::type // since C++11
template <typename T1, typename T2>
typename std::common_type<T1,T2>::type max7(T1 a, T2 b)     
{
	return a > b ? a : b;
}

// C++14 起，可以通过在特性名称后面添加_t跳过typename和::type来简化trait的使用
template <typename T1, typename T2>
std::common_type_t<T1, T2> max8(T1 a, T2 b)
{
	return a > b ? a : b;
}

/************************************默认模版参数************************************/
template <typename T1, typename T2, typename RT = typename std::decay<decltype(true ? T1() : T2())>::type>
std::common_type_t<T1, T2> max9(T1 a, T2 b)
{
	return a > b ? a : b;
}

template <typename T1, typename T2, typename RT = typename std::common_type<T1, T2>::type>
std::common_type_t<T1, T2> max10(T1 a, T2 b)
{
	return a > b ? a : b;
}


/************************************重载函数模版************************************/
int myMax(int a, int b)
{
	return a > b ? a : b;
}

template <typename T>
auto myMax(T a, T b)
{
	return a > b ? a : b;
}

template <typename T1, typename T2>
auto myMax2(T1 a, T2 b)
{
	return a > b ? a : b;
}

template <typename RT,typename T1, typename T2>
RT myMax2(T1 a, T2 b)
{
	return a > b ? a : b;
}