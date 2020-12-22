#include "PolishConvertor.h"

PolishConvertor::PolishConvertor(const std::string& str)
{
	expression = str;
}

PolishConvertor::PolishConvertor()
{

}

void PolishConvertor::AddVar(std::string str_var, double var_value)
{
	if (num_of_var == 0)
	{
		throw std::logic_error("Expression has no variables");
	}
	for (int i = 0; i < polish_expression.GetListLenght(); i++)
	{
		if (polish_expression.get(i).symbol == str_var)
		{
			polish_expression.get(i).value = var_value;
			num_of_var--;
		}
	}
}

double PolishConvertor::Calculate()
{
	if (num_of_var != 0)
	{
		throw std::logic_error("Variables are not defined");
	}
	stack<Term> stack;
	for (int i = 0; i < polish_expression.GetListLenght(); i++)
	{
		Term current = polish_expression.get(i);
		if (current.type == operand)
		{
			stack.push(current);
		}
		else if(current.type == bin_operator)
		{
			Term operand1 = stack.top();
			stack.pop();
			double val1 = operand1.value;
			Term operand2 = stack.top();
			stack.pop();
			double val2 = operand2.value;
			Term result;
			switch (current.symbol[0])
			{
			case '+':
				result.value = val2 + val1;
				stack.push(result);
				break;
			case '-':
				result.value = val2 - val1;
				stack.push(result);
				break;
			case '*':
				result.value = val2 * val1;
				stack.push(result);
				break;
			case '/':
				result.value = val2 / val1;
				stack.push(result);
				break;
			case '^':
				result.value = pow(val2, val1);
				stack.push(result);
				break;
			}
		}
		else {
			Term operand = stack.top();
			stack.pop();
			switch (current.symbol[0])
			{
				case '-':
					operand.value *= -1;
					stack.push(operand);
					break;
				case '|':
					if (operand.value < 0)
					{
						operand.value *= -1;
					}
					stack.push(operand);
					break;
			}
		}
		

	}
	return stack.top().value;
}

bool PolishConvertor::IsCharCorrect(const char& symb)
{
	std::string correctSymbols = "./+*()|-^";
	for (int i = 0; i < correctSymbols.size(); i++)
	{
		if (correctSymbols[i] == symb)
		{
			return true;
		}
	}
	if (symb >= '0' && symb <= '9' || symb >= 'A' && symb <= 'Z' || symb >= 'a' && symb <= 'z')
	{
		return true;
	}
	std::string err_str = "Incorrect symbol: '";
	err_str.append(1, symb);
	err_str.append(1, '\'');
	throw std::logic_error(err_str);// + symb);
}

bool PolishConvertor::AreParenthesisCorrect()
{
	stack<char> stack;
	for (int i = 0; i < expression.size(); i++)
	{
		switch (expression[i])
		{
		case '(':
			stack.push(expression[i]);
			break;
		case ')':
			if (!stack.empty() && stack.top() == '(')
			{
				stack.pop();
			}
			else
			{
				stack.push(expression[i]);
			}
			break;
		case '|':
			if (!stack.empty() && stack.top() == '|')
			{
				stack.pop();
			}
			else
			{
				stack.push(expression[i]);
			}
			break;
		default:
			break;
		}
	}
	if (stack.empty())
	{
		return true;
	}
	throw std::logic_error ("Parenthesis are incorrect");
}

bool PolishConvertor::IsExpressionCorrect()
{
	DelSpaces();
	for (int i = 0; i < expression.size(); i++)
	{
		IsCharCorrect(expression[i]);
	}
	AreParenthesisCorrect();
	CreateListOfTerms();
	SetUnOperators();
	CheckSequenceOfTerms();
	return true;
}

void PolishConvertor::DelSpaces()
{
	std::string expr;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] != ' ')
		{
			expr.append(1, expression[i]);
		}
	}
	expression = expr;
}

void PolishConvertor::CreateListOfTerms()
{
	int num_of_m = 0;
	Term term;
	std::string str_operand = "";
	for (int i = 0; i < expression.size(); i++)
	{
		while (!IsSpecialSymb(expression[i]) && i < expression.size())
		{
			str_operand.append(1,expression[i]);
			i++;
		}
		if (str_operand != "")
		{
			term.symbol = str_operand;
			term.type = operand;
			terms.InsLast(term);
			str_operand = "";
		}
		if (!(i < expression.size()))
		{
			break;
		}
		switch (expression[i])
		{
		case '-':
			term.symbol = "-";
			term.type = bin_operator;
			term.prioryty = 2;
			break;
		case '+':
			term.symbol = "+";
			term.type = bin_operator;
			term.prioryty = 2;
			break;
		case '*':
			term.symbol = "*";
			term.type = bin_operator;
			term.prioryty = 3;
			break;
		case '/':
			term.symbol = "/";
			term.type = bin_operator;
			term.prioryty = 3;
			break;
		case '^':
			term.symbol = "^";
			term.type = bin_operator;
			term.prioryty = 4;
			break;
		case ')':
			term.symbol = ")";
			term.type = close_parenthesis;
			term.prioryty = 1;
			break;
		case '(':
			term.symbol = "(";
			term.type = open_parenthesis;
			term.prioryty = 1;
			break;
		case '|':
			num_of_m++;
			if (num_of_m % 2 == 1)
			{
				term.symbol = "|";
				term.type = open_parenthesis;
				term.prioryty = 1;
			}
			else
			{
				term.symbol = "|";
				term.type = close_parenthesis;
				term.prioryty = 1;
			}
			break;
		}
		terms.InsLast(term);
	}
	term.symbol = "begin";
	term.type = begin_of_expression;
	terms.InsFirst(term);
	term.symbol = "end";
	term.type = end_of_expression;
	terms.InsLast(term);
}

bool PolishConvertor::IsSpecialSymb(const char& symb)
{
	std::string specialSymbols = "/+*()|-^";
	for (int i = 0; i < specialSymbols.size(); i++)
	{
		if (symb == specialSymbols[i])
		{
			return true;
		}
	}
	return false;
}

void PolishConvertor::SetUnOperators()
{
	for (int i = 1; i < terms.GetListLenght() - 1;i++)
	{
		if (terms.get(i).symbol == "-" &&
			(terms.get(i - 1).type == begin_of_expression ||
				terms.get(i - 1).type == open_parenthesis))
		{
			terms.get(i).type = un_operator;
			terms.get(i).prioryty = 3;
		}
	}
}

void PolishConvertor::PrintTerms()
{
	for (int i = 0; i < terms.GetListLenght(); i++)
	{
		std::cout << "'" << terms.get(i).symbol<<"'";
		switch (terms.get(i).type)
		{
		case open_parenthesis:
			std::cout << " open_parenthesis";
			break;
		case close_parenthesis:
			std::cout << " close_parenthesis";
			break;
		case bin_operator:
			std::cout << " bin_operator";
			break;
		case operand:
			std::cout << " operand";
			break;
		case begin_of_expression:
			std::cout << " begin_of_expression";
			break;
		case end_of_expression:
			std::cout << " end_of_expression";
			break;
		case un_operator:
			std::cout << " un_operator";
			break;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PolishConvertor::CheckSequenceOfTerms()
{
	for (int i = 1; i < terms.GetListLenght() - 1; i++)
	{
		TypeOfTerm prev = terms.get(i - 1).type;
		TypeOfTerm next = terms.get(i + 1).type;
		switch (terms.get(i).type)
		{
		case bin_operator:
			if (prev == bin_operator ||
				prev == un_operator ||
				prev == open_parenthesis ||
				prev == begin_of_expression ||
				next == bin_operator ||
				next == un_operator ||
				next == close_parenthesis ||
				next == end_of_expression)
			{
				throw std::logic_error("Wrong sequence of terms");
			}
			break;
		case operand:
			if (prev == operand ||
				next == operand ||
				prev == close_parenthesis ||
				next == open_parenthesis
				)
			{
				throw std::logic_error("Wrong sequence of terms");
			}
			break;
		case open_parenthesis:
			if (prev == close_parenthesis ||
				next == close_parenthesis ||
				next == bin_operator ||
				next == end_of_expression ||
				prev == operand)
			{
				throw std::logic_error("Wrong sequence of terms");
			}
			break;
		case close_parenthesis:
			if (next == operand ||
				next == open_parenthesis ||
				prev == open_parenthesis ||
				prev == bin_operator ||
				prev == un_operator)
			{
				throw std::logic_error("Wrong sequence of terms");
			}
			break;
		}
	}
}

std::string PolishConvertor::ConvertToPolish(std::string _expression)
{
	expression = _expression;
	polish_expression.DelList();
	terms.DelList();
	IsExpressionCorrect();
	num_of_var = 0;
	stack<Term> stack;
	for (int i = 1; i < terms.GetListLenght() - 1; i++)
	{
		Term current = terms.get(i);
		if (current.type == operand)
		{
			polish_expression.InsLast(current);
		}
		else if (current.type == bin_operator || current.type == un_operator)
		{
			if (stack.empty() || stack.top().prioryty < current.prioryty)
			{
				stack.push(current);
			}
			else
			{
				while (!stack.empty() && stack.top().prioryty >= current.prioryty)
				{
					polish_expression.InsLast(stack.top());
					stack.pop();
				}
				stack.push(current);
			}
		}
		else if (current.type == open_parenthesis)
		{
			stack.push(current);
		}
		else if (current.type == close_parenthesis)
		{
			while (stack.top().type != open_parenthesis)
			{
				polish_expression.InsLast(stack.top());
				stack.pop();
			}
			
			stack.pop();
			if (current.symbol == "|")
			{
				stack.push(current);
			}
		}
	}
	while (!stack.empty())
	{
		polish_expression.InsLast(stack.top());
		stack.pop();
	}
	std::string str_polish_expression = "";
	for (int i = 0; i < polish_expression.GetListLenght(); i++)
	{
		str_polish_expression += polish_expression.get(i).symbol;
		str_polish_expression += " ";
	}
	SetValues();
	return str_polish_expression;
}

void PolishConvertor::SetValues()
{
	for (int i = 0; i < polish_expression.GetListLenght(); i++)
	{
		if (polish_expression.get(i).type == operand)
		{
			if (CanSetValue(polish_expression.get(i)))
			{
				SetValue(polish_expression.get(i));
			}
			else
			{
				num_of_var++;
			}
		}
	}
}

void PolishConvertor::SetValue(Term& term)
{
	std::string str = term.symbol;
	bool isdouble = false;
	double result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			isdouble = true;
			break;
		}
	}
	if (isdouble)
	{
		int point_pos = str.size();
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
			{
				point_pos = i;
				break;
			}
		}
		pair* pairs = new pair[str.size() - 1];
		int counter = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
			{
				continue;
			}
			pairs[counter].symb = str[i];
			if (point_pos - i > 0)
			{
				pairs[counter].degree = point_pos - i - 1;
			}
			else
			{
				pairs[counter].degree = point_pos - i;
			}
			counter++;
		}
		
		for (int i = 0; i < str.size() - 1; i++)
		{
			result += (pairs[i].symb - '0') * pow(10, pairs[i].degree);
		}
		term.value = result;
		delete[]pairs;
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			result = result * 10 + str[i] - '0';
		}
		term.value = result;
	}
	
}

bool PolishConvertor::CanSetValue(Term& term)const
{
	if(term.symbol[0] == '.' || term.symbol[term.symbol.size() - 1] =='.')
	{
		return false;
	}
	for (int i = 0; i < term.symbol.size(); i++)
	{
		if (!IsDoubleOrPoint(term.symbol[i]))
		{
			return false;
		}
	}
	return true;
}

bool PolishConvertor::IsDoubleOrPoint(const char ch)const
{
	std::string numbers_and_point = "0123456789.";
	for (int i = 0; i < numbers_and_point.size(); i++)
	{
		if (numbers_and_point[i] == ch)
		{
			return true;
		}
	}
	return false;
}
