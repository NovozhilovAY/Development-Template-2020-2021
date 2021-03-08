#include <iostream>
#include <map>
#include <exception>
struct Roman
{
	std::string value;
};
struct Arabic
{
	int value;
};

class Convertor
{
	Roman roman;
	Arabic arabic;
public:
	Roman ConvertToRoman(const Arabic& arabic_num);
	Arabic ConvertToArabic(const Roman& roman_num);
	Roman get_roman();
	Arabic get_arabic();
	Roman check(const Roman& roman_num);
	void print();
private:
	void func_for_Marina_Andreevna(std::string& result,int num, std::string left, std::string mid, std::string right);
	bool is_roman_correct(const Roman& roman_num);
	bool is_char_in_str(const char& ch, const std::string& str);
};