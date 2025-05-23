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
