#pragma once
#include "TList.h"
template<typename T>
class stack {
private:
	TList<T> list;
public:
	bool empty();
	void pop();
	void push(const T& val);
	T top();
	int size();
};

template<typename T>
inline bool stack<T>::empty()
{
	return list.IsEmpty();
}

template<typename T>
inline void stack<T>::pop()
{
	list.DelFirst();
}

template<typename T>
inline void stack<T>::push(const T& val)
{
	list.InsFirst(val);
}

template<typename T>
inline T stack<T>::top()
{
	return list.get(0);
}

template<typename T>
inline int stack<T>::size()
{
	return list.GetListLenght();
}
