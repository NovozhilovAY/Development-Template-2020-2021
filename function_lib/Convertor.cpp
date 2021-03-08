#include "Convertor.h"

Roman Convertor::ConvertToRoman(const Arabic& arabic_num)
{
	std::map <int, std::string> table_of_values = { {1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"} };
	Roman result;
	result.value = "";

	int num_of_1000 = arabic_num.value / 1000;
	int num_of_100 = arabic_num.value % 1000 / 100;
	int num_of_10 = arabic_num.value % 100 / 10;
	int num_of_1 = arabic_num.value % 10;
	for (int i = 0; i < num_of_1000; i++)
	{
		result.value += table_of_values[1000];
	}
	func_for_Marina_Andreevna(result.value, num_of_100, table_of_values[100], table_of_values[500], table_of_values[1000]);
	func_for_Marina_Andreevna(result.value, num_of_10, table_of_values[10], table_of_values[50], table_of_values[100]);
	func_for_Marina_Andreevna(result.value, num_of_1, table_of_values[1], table_of_values[5], table_of_values[10]);
	roman = result;
	arabic = arabic_num;
	return result;
}

Arabic Convertor::ConvertToArabic(const Roman& roman_num)
{
	if (!is_roman_correct(roman_num))
	{
		throw std::logic_error("Wrong number!");
	}
	Arabic result;
	result.value = 0;
	std::map <char, int> table_of_values = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
	int i = 0;
	for (i; i < roman_num.value.size() - 1; i++)
	{
		if (table_of_values[roman_num.value[i]] >= table_of_values[roman_num.value[i + 1]])
		{
			result.value += table_of_values[roman_num.value[i]];
		}
		else
		{
			result.value -= table_of_values[roman_num.value[i]];
		}
	}
	result.value += table_of_values[roman_num.value[i]];
	roman = roman_num;
	arabic = result;
	return result;
}

Roman Convertor::get_roman()
{
	return roman;
}

Arabic Convertor::get_arabic()
{
	return arabic;
}

Roman Convertor::check(const Roman& roman_num)
{
	return ConvertToRoman(ConvertToArabic(roman_num));
}

void Convertor::print()
{
	std::cout << arabic.value << " - " << roman.value<<"\n";
}

void Convertor::func_for_Marina_Andreevna(std::string& result, int num, std::string left, std::string mid, std::string right)
{
	if (num != 0)
	{
		if (num >= 1 && num < 4)
		{
			for (int i = 0; i < num; i++)
			{
				result += left;
			}
		}
		else if (num == 4)
		{
			result += left;
			result += mid;
		}
		else if (num == 5)
		{
			result += mid;
		}
		else if (num >= 6 && num < 9)
		{
			result += mid;
			for (int i = 0; i < num - 5; i++)
			{
				result += left;
			}
		}
		else
		{
			result += left;
			result += right;
		}
	}
}

bool Convertor::is_roman_correct(const Roman& roman_num)
{
	for (int i = 0; i < roman_num.value.size()-1; i++)
	{
		switch (roman_num.value[i])
		{
		case 'I':
			if (!is_char_in_str(roman_num.value[i+1],"IVX"))
			{
				return false;
			}
			break;
		case 'V':
			if (roman_num.value[i + 1] != 'I')
			{
				return false;
			}
			break;
		case 'X':
			if(!is_char_in_str(roman_num.value[i+1], "IVXC"))
			{
				return false;
			}
			break;
		case 'L':
			if (!is_char_in_str(roman_num.value[i+1], "IVX"))
			{
				return false;
			}
			break;
		case 'C':
			if (!is_char_in_str(roman_num.value[i + 1], "IVXLC"))
			{
				return false;
			}
			break;
		case 'D':
			if (is_char_in_str(roman_num.value[i + 1], "M"))
			{
				return false;
			}
			break;
		}
	}
	return true;
}

bool Convertor::is_char_in_str(const char& ch, const std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
		{
			return true;
		}
	}
	return false;
}
