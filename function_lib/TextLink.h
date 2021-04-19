#pragma once
#include "Text.h"
#include <string>
#define MemSize 40

class TextMem
{
	TextLink* pFirst;
	TextLink* pLast;
	TextLink* pFree;
	friend class TextLink;
};

class TextLink {
private:
	std::string str;
	TextLink* pNext;
	TextLink* pDown;
	static TextMem* MemHeader;
public:
	static void InitMemSystem(int size = MemSize);		
	static void PrintFreeLink();						

	void* operator new (size_t size);
	void operator delete(void* pM);

	static void MemCleaner(Text& txt);		// —борка мусора

	TextLink(std::string s = "", TextLink* pn = nullptr, TextLink* pd = nullptr);
	std::string GetLine()const;
	void SetLine(const std::string& s);
	TextLink* GetNext();
	TextLink* GetDown();
	void SetNext(TextLink* next);
	void SetDown(TextLink* down);
	bool IsAtom() { return pDown == nullptr; }
};