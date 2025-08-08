#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
public:
	void push(T const& elem);   //添加一个元素
	void pop();					//弹出一个元素
	T const& top() const;		//获取第一个元素
	bool empty();

private:
	vector<T> m_stackContainer;

};

template <typename T>
void Stack<T>::push(T const& elem)
{
	m_stackContainer.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
	assert(!m_stackContainer.empty());
	m_stackContainer.pop_back();
}

template <typename T>
T const& Stack<T>::top()const
{
	assert(!m_stackContainer.empty());
	return m_stackContainer.back();
}

template <typename T>
bool Stack<T>::empty()
{
	return m_stackContainer.empty();
}

/************************************类模版特化偏特化************************************/
//泛化版本
template <typename T,typename U, typename V>
struct TestClass
{
	TestClass()
	{
		std::cout << "泛化版本构造函数" << std::endl;
	}
	void func(T a,U b,V c)
	{
		std::cout << "泛化版本" << std::endl;
	}
};

//全特化版本
template <>
struct TestClass<int, double, double>
{
	TestClass()
	{
		std::cout << "全特化版本构造函数" << std::endl;
	}
	void func(int a, double b, double c)
	{
		std::cout << "全特化版本" << std::endl;
	}
};

//偏特化版本(参数个数)
template <typename U, typename V>
struct TestClass<string, U, V>
{
	TestClass()
	{
		std::cout << "偏特化版本(参数个数)构造函数string, U, V" << std::endl;
	}
	void func(string a, U b, V c)
	{
		std::cout << "偏特化版本(参数个数)" << std::endl;
	}
};

//偏特化版本(参数范围)
template <typename T, typename U, typename V>
struct TestClass<T*, U*, V*>
{
	TestClass()
	{
		std::cout << "偏特化版本(参数范围)构造函数T*, U*, V*" << std::endl;
	}
	void func(T* a, U* b, V* c)
	{
		std::cout << "偏特化版本(参数范围)" << std::endl;
	}
};
