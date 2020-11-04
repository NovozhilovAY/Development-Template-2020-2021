#pragma once
#include "multistackroot.h"

class TMultistack : public TMultiRoot
{
protected:
	TStack* pStack[StackNum + 1];
	int FreeMemSize;
protected:
	TElem* pStackMem[StackNum + 1];
	int RelocationCount;
	int StackRelocation(int nst);
	int GetFreeMemSize();
	virtual void SetStackRelocation(TElem* pStackMem[]);
public:
	TMultistack();
	~TMultistack();
	bool IsEmpty(int ns)const;
	bool IsFull(int ns)const;
	virtual void Put(int ns, const TData& Val);
	virtual TData Get(int ns);
	int GetRelocationCount() { return RelocationCount; }
	void print();
};