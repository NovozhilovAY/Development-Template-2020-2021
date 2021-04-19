#include "Text.h"
#include <stdexcept>
#include <iostream>

TextLink* Text::GetFirstAtom(TextLink* pl)
{
	TextLink* tmp = pl;
	while (!tmp->IsAtom())
	{
		St.push(tmp);
		tmp = tmp->GetDown();
	}
	return tmp;
}

int Text::Reset()
{
	while (!St.empty())
		St.pop();
	pCurrent = pFirst;
	if (pCurrent != nullptr)
	{
		St.push(pCurrent);
		if (pCurrent->GetNext() != nullptr)
			St.push(pCurrent->GetNext());
		if (pCurrent->GetDown() != nullptr)
			St.push(pCurrent->GetDown());
	}
	return IsTextEnded();
}

int Text::IsTextEnded() const
{
	return !St.size();
}

int Text::GoNext()
{
	if (!IsTextEnded())
	{
		pCurrent = St.top();
		St.pop();
		if (pCurrent->GetNext() != nullptr)
			St.push(pCurrent->GetNext());
		if (pCurrent->GetDown() != nullptr)
			St.push(pCurrent->GetDown());
	}
	return IsTextEnded();
}

Text::Text(std::string str)
{
	TextLevel = 0;
	pFirst = new TextLink(str, nullptr, nullptr);
	pCurrent = pFirst;
}

Text::Text(TextLink* tl)
{
	if (tl == nullptr)
		tl = new TextLink();
	pCurrent = pFirst = tl;
}

Text* Text::GetCopy()
{
	TextLink* pl1 = pFirst;
	TextLink* pl2 = pFirst;
	TextLink* pl = pFirst;
	TextLink* cpl = nullptr;
	if (pFirst != nullptr)
	{
		while (!St.empty())
			St.pop();
		while (1)
		{
			if (pl != nullptr)
			{
				pl = GetFirstAtom(pl);
				St.push(pl);
				pl = pl->GetDown();
			}
			else if (St.empty())
				break;
			else
			{
				pl1 = St.top(); St.pop();
				if (pl1->GetLine() != "Copy")
				{
					pl2 = new TextLink("Copy", pl1, cpl);
					St.push(pl2);
					pl = pl1->GetNext();
					cpl = nullptr;
				}
				else
				{
					pl2 = pl1->GetNext();
					pl1->SetLine(pl2->GetLine());
					pl1->SetNext(cpl);
					cpl = pl1;
				}
			}
		}
	}
	return new Text(cpl);
}

void Text::GoFirstLink()
{
	while (!Path.empty())
	{
		Path.pop();
	}
	pCurrent = pFirst;
	if (pCurrent == NULL)
	{
		throw std::logic_error("Error in GoFirstLink method!");
	}
}

void Text::GoDownLink()
{
	if (pCurrent != nullptr)
	{
		if (pCurrent->GetDown() != nullptr)
		{
			Path.push(pCurrent);
			pCurrent = pCurrent->GetDown();
		}
	}
}

void Text::GoNextLink()
{
	if (pCurrent != nullptr)
	{
		if (pCurrent->GetNext() != nullptr)
		{
			Path.push(pCurrent);
			pCurrent = pCurrent->GetNext();
		}
	}
}

void Text::GoPrevLink()
{
	if (Path.empty())
	{
		return;
	}
	pCurrent = Path.top();
	Path.pop();
}

std::string Text::GetLine() const
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	return pCurrent->GetLine();
}

void Text::SetLine(const std::string& s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	pCurrent->SetLine(s);
}

void Text::InsDownLine(const std::string& s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	TextLink* pd = pCurrent->GetDown();
	TextLink* pl = new TextLink(s, pd, nullptr);
	pCurrent->SetDown(pl);
}

void Text::DelDownLine()
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	if (pCurrent->GetDown() != nullptr)
	{
		TextLink* pl1 = pCurrent->GetDown();
		TextLink* pl2 = pl1->GetNext();
		if (pl1->GetDown() == nullptr)
		{
			pCurrent->SetDown(pl1);
		}
	}
}

void Text::InsDownSection(const std::string& s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	TextLink* pd = pCurrent->GetDown();
	TextLink* pl = new TextLink(s, nullptr, pd);
	pCurrent->SetDown(pl);
}

void Text::DelDownSection()
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	if (pCurrent->GetDown() != nullptr)
	{
		TextLink* pl1 = pCurrent->GetDown();
		TextLink* pl2 = pl1->GetNext();
		pCurrent->SetDown(pl2);
	}
}

void Text::InsNextLine(const std::string& s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	TextLink* pd = pCurrent->GetNext();
	TextLink* pl = new TextLink(s, pd, nullptr);
	pCurrent->SetNext(pl);
}

void Text::DelNextLine()
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	if (pCurrent->GetNext() != nullptr)
	{
		TextLink* pl1 = pCurrent->GetNext();
		TextLink* pl2 = pl1->GetNext();
		if (pl1->GetNext() == nullptr)
		{
			pCurrent->SetNext(pl2);
		}
	}
}

void Text::InsNextSection(const std::string& s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	TextLink* pd = pCurrent->GetNext();
	TextLink* pl = new TextLink(s, nullptr, pd);
	pCurrent->SetNext(pl);
}

void Text::DelNextSection()
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("pCurrent is nullptr!");
	}
	if (pCurrent->GetNext() != nullptr) {
		TextLink* pl1 = pCurrent->GetNext();
		TextLink* pl2 = pl1->GetNext();
		pCurrent->SetNext(pl2);
	}
}

void Text::Print()
{
	TextLevel = 0;
	PrintText(pFirst);
}

void Text::PrintText(TextLink* pLink)
{
	if (pLink != nullptr)
	{
		for (int i = 0; i < TextLevel; i++)
			std::cout << "  ";
		std::cout << " " << pLink->GetLine() << std::endl;
		++TextLevel; PrintText(pLink->GetDown());
		--TextLevel; PrintText(pLink->GetNext());
	}
}

void Text::Read(const char* pFileName)
{
	std::ifstream TxtFile(pFileName);
	TextLevel = 0;
	if (!TxtFile.is_open())
		throw std::logic_error("file wasn't open!");
	pFirst = ReadText(TxtFile);
	pCurrent = pFirst;
}

void Text::Write(const char* pFileName)
{
	std::ofstream TxtFile;
	TxtFile.open(pFileName);
	TextLevel = 0;
	wr(TxtFile, pFirst);
}

void Text::wr(std::ofstream& txt, TextLink* ptl)
{
	if (ptl != nullptr)
	{
		for (int i = 0; i < TextLevel; i++)
		{
			txt << " ";
		}
		txt << ptl->GetLine() << std::endl;
		TextLevel++;
		wr(txt, ptl->GetDown());
		TextLevel--;
		wr(txt, ptl->GetNext());
	}
}

TextLink* Text::ReadText(std::ifstream& TxtFile)
{
	TextLink* pHead = new TextLink();
	TextLink* cur = pHead;
	std::string StrBuf = "";
	while (TxtFile.eof() == 0) {
		getline(TxtFile, StrBuf, '\n');
		if (pHead->GetLine() == "")
		{
			pHead->SetLine(StrBuf);
			continue;
		}
		if (StrBuf[0] == '}') {
			TextLevel--;
			break;
		} 
		else if (StrBuf[0] == '{') {
			cur->SetDown(ReadText(TxtFile));
			cur->SetNext(cur->GetNext());
		}
		else
		{
			cur->SetNext(new TextLink());
			cur = cur->GetNext();
			cur->SetLine(StrBuf);
		}
	}
	if (cur->GetLine() == "")
	{
		delete cur;
	}
	return pHead;
}
