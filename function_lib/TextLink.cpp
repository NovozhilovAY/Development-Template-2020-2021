#include "TextLink.h"
#include "Text.h"
#include <iostream>
TextMem* TextLink::MemHeader = new TextMem();
void TextLink::InitMemSystem(int size) // инициализация памяти
{
	MemHeader->pFirst = (TextLink*) new std::string[sizeof(TextLink*) * size];
	MemHeader->pFree = MemHeader->pFirst;
	MemHeader->pLast = MemHeader->pFirst + (size - 1);
	TextLink* pLink = MemHeader->pFirst;
	for (int i = 0; i < size - 1; ++i, pLink++)
		pLink->pNext = pLink + 1;
	pLink->pNext = nullptr;
}

void TextLink::PrintFreeLink()
{
	TextLink* pLink = MemHeader->pFree;
	std::cout << "List of free links" << std::endl;
	while (pLink != nullptr)
	{
		std::cout << pLink << std::endl;
		pLink = pLink->pNext;
	}
}

void* TextLink::operator new(size_t size)
{
	TextLink* pLink = MemHeader->pFree;
	if (MemHeader->pFree != nullptr)
		MemHeader->pFree = pLink->pNext;
	return pLink;
}

void TextLink:: operator delete(void* pM)
{
	TextLink* pLink = (TextLink*)pM;
	pLink->pNext = MemHeader->pFree;
	MemHeader->pFree = pLink;
}

void TextLink::MemCleaner(Text& txt)
{
	std::string st;

	for (txt.Reset(); !txt.IsTextEnded(); txt.GoNext())
		if (st.find("&&&") != -1) txt.SetLine("&&&" + txt.GetLine());

	TextLink* pLink = MemHeader->pFree;
	while (pLink != nullptr)
	{
		pLink->SetLine("&&&");
		pLink = pLink->pNext;
	}
	pLink = MemHeader->pFirst;
	for (; pLink <= MemHeader->pLast; pLink++)
		if (pLink->GetLine().find("&&&") != -1)
			pLink->SetLine(pLink->GetLine().substr(2));
		else
			delete pLink;
}

TextLink::TextLink(std::string s, TextLink* pn, TextLink* pd)
{
	str = s;
	pNext = pn;
	pDown = pd;
}

std::string TextLink::GetLine()const
{
	return str;
}

void TextLink::SetLine(const std::string& s)
{
	str = s;
}

TextLink* TextLink::GetNext()
{
	return pNext;
}

TextLink* TextLink::GetDown()
{
	return pDown;
}

void TextLink::SetNext(TextLink* next)
{
	pNext = next;
}

void TextLink::SetDown(TextLink* down)
{
	pDown = down;
}
