#pragma once
#include <string>
#include <stdexcept>
#include "stack.h"

enum TypeOfTerm
{
	bin_operator, un_operator, operand, open_parenthesis, close_parenthesis, begin_of_expression, end_of_expression
};
struct Term
{
	std::string symbol;
	TypeOfTerm type;
	int prioryty;
	double value;
};
struct pair
{
	char symb;
	int degree;
};
class PolishConvertor {
private:
	std::string expression;
	TList<Term> terms;
	TList<Term> polish_expression;
	int num_of_var = 0;
public:
	PolishConvertor(const std::string& str);
	PolishConvertor();
	void AddVar(std::string str_var, double var_value);
	double Calculate();
	std::string ConvertToPolish(std::string _expression);
private:
	bool IsCharCorrect(const char& symb);
	bool AreParenthesisCorrect();
	bool IsExpressionCorrect();
	void DelSpaces();
	void CreateListOfTerms();
	bool IsSpecialSymb(const char& symb);
	void SetUnOperators();
	void PrintTerms();
	void CheckSequenceOfTerms();
	void SetValues();
	void SetValue(Term& term);
	bool CanSetValue(Term& term)const;
	bool IsDoubleOrPoint(const char ch)const;
};