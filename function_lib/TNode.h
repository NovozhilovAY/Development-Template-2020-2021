#pragma once

template<typename T>
class TNode
{
public:
	T data;
	TNode* Next;

	TNode(T _data = T(),TNode* pNext = nullptr);
};


template<typename T>
TNode<T>::TNode(T _data, TNode* pNext)
{
	this->data = _data;
	this->Next = pNext;
}



