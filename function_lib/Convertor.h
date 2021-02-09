#include <iostream>
#include <map>
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
};