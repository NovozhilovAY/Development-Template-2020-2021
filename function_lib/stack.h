#pragma once
#include <exception>
#include <iostream>
typedef int TElem;
typedef TElem* PTElem;
typedef int TData;

#define DefMemSize 25

enum TMemType {MEM_HOLDER, MEM_RENTER};

class TStack
{
protected:
	PTElem pMem;
	int MemSize;
	int DataCount;
	TMemType MemType;
	int Hi;
protected:
	void SetMem(TElem* _pMem, int Size);
	int GetNextIndex(int index);
public:
	~TStack();
	TStack(int Size = DefMemSize);
	int IsEmpty()const;
	int IsFull()const;
	void Put(const TData& Val);
	TData Get();
	void print();
	friend class TMultistack;
	friend class TMultiRoot;
};