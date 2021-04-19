#pragma once
#include "Header.h"
#include "TextLink.h"
#include <stack>
#include <fstream>
class Text
{
private:
	TextLink* pFirst;
	TextLink* pCurrent;
	std::stack<TextLink*> Path;
	int TextLevel;

	std::stack<TextLink*> St;
	TextLink* GetFirstAtom(TextLink* pl);

	
public:
	Text(std::string str);
	Text(TextLink* tl);
	Text* GetCopy();
	void GoFirstLink();
	void GoDownLink();
	void GoNextLink();
	void GoPrevLink();

	std::string GetLine()const;
	void SetLine(const std::string& s);

	void InsDownLine(const std::string& s);
	void DelDownLine();

	void InsDownSection(const std::string& s);
	void DelDownSection();

	void InsNextLine(const std::string& s);
	void DelNextLine();

	void InsNextSection(const std::string& s);
	void DelNextSection();

	void Print();
	void PrintText(TextLink* pLink);

	void Read(const char* pFileName);
	void Write(char* pFileName);

	TextLink* ReadText(std::ifstream& TxtFile);

	void Write(const char* pFileName);
	void wr(std::ofstream& txt, TextLink* ptl);

	int Reset();
	int IsTextEnded()const;
	int GoNext();
};