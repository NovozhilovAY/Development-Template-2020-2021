#pragma once
#include <exception>
#include "TNode.h"
#include <iostream>
template<typename T>
class TList
{
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	int ListLen;
public:
	TList();
	~TList();
	int GetListLenght();
	bool IsEmpty();
	void InsFirst(T Val);
	void InsLast(T Val);
	void DelFirst();
	void DelLast();
	void DelList();
	void InsValue(T Val, int pos);
	void DelValue(int pos);
	void print();
	void sorted_push(T Val);

	bool search(T data);
	void Reverse();
	T& get(int pos);
	void Merge(TList<T> &list1, TList<T> &list2);
	bool IsSorted();
	void ExchangeOfValues(int pos1,int pos2);
};

template<typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	ListLen = 0;
}

template<typename T>
TList<T>::~TList<T>()
{
	DelList();
}

template<typename T>
inline int TList<T>::GetListLenght()
{
	return ListLen;
}

template<typename T>
bool TList<T>::IsEmpty()
{
	if (ListLen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void TList<T>::InsFirst(T Val)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<T>(Val);
		pLast = pFirst;
	}
	else
	{
		TNode<T>* newNode = new TNode<T>(Val, pFirst);
		pFirst = newNode;
	}
	ListLen++;
}

template<typename T>
void TList<T>::InsLast(T Val)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<T>(Val);
		pLast = pFirst;
	}
	else
	{
		TNode<T> *tmp = new TNode<T>(Val);
		pLast->Next = tmp;
		pLast = tmp;
	}
	ListLen++;
}

template<typename T>
void TList<T>::DelFirst()
{
	if (pFirst == nullptr)
	{
		return;
	}
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = nullptr;
		pLast = nullptr;
		ListLen--;
		return;
	}
	TNode<T>* tmp = pFirst;
	pFirst = pFirst->Next;
	delete tmp;
	ListLen--;
}

template<typename T>
void TList<T>::DelLast()
{
	if (pFirst == nullptr)
	{
		return;
	}
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = nullptr;
		pLast = nullptr;
		ListLen--;
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->Next->Next != nullptr)
	{
		tmp = tmp->Next;
	}
	delete tmp->Next;
	tmp->Next = nullptr;
	pLast = tmp;
	ListLen--;
}

template<typename T>
void TList<T>::DelList()
{
	while (ListLen != 0)
	{
		DelLast();
	}
}

template<typename T>
void TList<T>::InsValue(T Val, int pos)
{
	if (pos < 0)
	{
		return;
	}
	if (pos == 0)
	{
		InsFirst(Val);
		return;
	}
	if (pos >= ListLen)
	{
		InsLast(Val);
		return;
	}
	int count = 0;
	TNode<T>* tmp = pFirst;
	while (count != pos-1)
	{
		tmp = tmp->Next;
		count++;
	}
	TNode<T>* newNode = new TNode<T>(Val, tmp->Next);
	tmp->Next = newNode;
	ListLen++;
}

template<typename T>
void TList<T>::DelValue(int pos)
{
	if (pos < 0 || pos >= ListLen)
	{
		return;
	}
	if (pos == 0)
	{
		DelFirst();
		return;
	}
	if (pos == ListLen - 1)
	{
		DelLast();
		return;
	}
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count != pos - 1)
	{
		tmp = tmp->Next;
		count++;
	}
	TNode<T>* tmp2 = tmp->Next->Next;
	delete tmp->Next;
	tmp->Next = tmp2;
	ListLen--;
}

template<typename T>
void TList<T>::print()
{
	if (pFirst != nullptr)
	{
		TNode<T>* tmp = pFirst;
		while (tmp->Next != nullptr)
		{
			
			std::cout << tmp->data << "->";
			tmp = tmp->Next;
		}
		std::cout << tmp->data << "->";
	}
	std::cout << "NULL     len = " <<GetListLenght()<<std::endl;
}

template<typename T>
void TList<T>::sorted_push(T Val)
{
	if (pFirst == nullptr)
	{
		InsFirst(Val);
		return;
	}
	int pos = 0;
	TNode<T>* curr = pFirst;
	while (curr != nullptr)
	{
		if (curr->data > Val)
		{
			InsValue(Val, pos);
			return;
		}
		if (curr->Next == nullptr)
		{
			InsValue(Val, pos + 1);
			return;
		}
		curr = curr->Next;
		pos++;
	}
	
}

template<typename T>
bool TList<T>::search(T data)
{
	if (ListLen == 0)
	{
		return false;
	}
	if (ListLen == 1)
	{
		if (pFirst->data == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	TNode<T>* tmp = pFirst;
	while (tmp->Next != nullptr)
	{
		if (tmp->data == data)
		{
			return true;
		}
		tmp = tmp->Next;
	}
	if (tmp->data == data)
	{
		return true;
	}
	return false;
}

template<typename T>
void TList<T>::Reverse()
{
	for (int i = 0; i < ListLen / 2; i++)
	{
		ExchangeOfValues(i, ListLen - i - 1);
	}

}

template<typename T>
T& TList<T>::get(int pos)
{
	if (pos < 0 || pos >= ListLen)
	{
		throw std::exception("error");
	}
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count != pos)
	{
		tmp = tmp->Next;
		count++;
	}
	return tmp->data;

}

template<typename T>
inline void TList<T>::Merge(TList<T> &list1, TList<T> &list2)
{
	if (!list1.IsSorted() || !list2.IsSorted())
	{
		throw std::exception("Lists should be sorted!");
	}
	DelList();
	while (!list1.IsEmpty() && !list2.IsEmpty())
	{
		if (list1.get(0) < list2.get(0))
		{
			InsLast(list1.get(0));
			list1.DelFirst();
		}
		else
		{
			InsLast(list2.get(0));
			list2.DelFirst();
		}
	}
	while(!list1.IsEmpty())
	{
		InsLast(list1.get(0));
		list1.DelFirst();
	}
	while (!list2.IsEmpty())
	{
		InsLast(list2.get(0));
		list2.DelFirst();
	}

}

template<typename T>
inline bool TList<T>::IsSorted()
{
	for (int i = 0; i < ListLen - 1; i++)
	{
		if (get(i) > get(i + 1))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
void TList<T>::ExchangeOfValues(int pos1, int pos2)
{
	if (pos1 < 0 || pos1 >= ListLen || pos2 < 0 || pos2 >= ListLen)
	{
		throw std::exception("error");
	}
	T T1 = get(pos1);
	T T2 = get(pos2);
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count < pos1)
	{
		tmp = tmp->Next;
		count++;
	}
	tmp->data = T2;
	count = 0;
	tmp = pFirst;
	while (count < pos2)
	{
		tmp = tmp->Next;
		count++;
	}
	tmp->data = T1;
}
