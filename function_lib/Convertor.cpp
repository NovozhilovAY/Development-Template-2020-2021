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

	if (num_of_100 != 0)
	{
		if (num_of_100 >= 1 && num_of_100 < 4)
		{
			for (int i = 0; i < num_of_100; i++)
			{
				result.value += table_of_values[100];
			}
		}
		else if (num_of_100 == 4)
		{
			result.value += table_of_values[100];
			result.value += table_of_values[500];
		}
		else if (num_of_100 == 5)
		{
			result.value += table_of_values[500];
		}
		else if (num_of_100 >= 6 && num_of_100 < 9)
		{
			result.value += table_of_values[500];
			for (int i = 0; i < num_of_100 - 5; i++)
			{
				result.value += table_of_values[100];
			}
		}
		else
		{
			result.value += table_of_values[100];
			result.value += table_of_values[1000];
		}
	}


	if (num_of_10 != 0)
	{
		if (num_of_10 >= 1 && num_of_10 < 4)
		{
			for (int i = 0; i < num_of_10; i++)
			{
				result.value += table_of_values[10];
			}
		}
		else if (num_of_10 == 4)
		{
			result.value += table_of_values[10];
			result.value += table_of_values[50];
		}
		else if (num_of_10 == 5)
		{
			result.value += table_of_values[50];
		}
		else if (num_of_10 >= 6 && num_of_10 < 9)
		{
			result.value += table_of_values[50];
			for (int i = 0; i < num_of_10 - 5; i++)
			{
				result.value += table_of_values[10];
			}
		}
		else
		{
			result.value += table_of_values[10];
			result.value += table_of_values[100];
		}
	}

	if (num_of_1 != 0)
	{
		if (num_of_1 >= 1 && num_of_1 < 4)
		{
			for (int i = 0; i < num_of_1; i++)
			{
				result.value += table_of_values[1];
			}
		}
		else if (num_of_1 == 4)
		{
			result.value += table_of_values[1];
			result.value += table_of_values[5];
		}
		else if (num_of_1 == 5)
		{
			result.value += table_of_values[5];
		}
		else if (num_of_1 >= 6 && num_of_1 < 9)
		{
			result.value += table_of_values[5];
			for (int i = 0; i < num_of_1 - 5; i++)
			{
				result.value += table_of_values[1];
			}
		}
		else
		{
			result.value += table_of_values[1];
			result.value += table_of_values[10];
		}
	}
	roman = result;
	arabic = arabic_num;
	return result;
}

Arabic Convertor::ConvertToArabic(const Roman& roman_num)
{
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
