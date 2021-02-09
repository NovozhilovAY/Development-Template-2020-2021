#include "Convertor.h"

#include <gtest.h>


TEST(test_lib, test_1)
{
	Convertor c;
	Arabic ar;
	ar.value = 1;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("I", c.get_roman().value);
}

TEST(test_lib, test_10)
{
	Convertor c;
	Arabic ar;
	ar.value = 10;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("X", c.get_roman().value);
}

TEST(test_lib, test_5)
{
	Convertor c;
	Arabic ar;
	ar.value = 5;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("V", c.get_roman().value);
}
TEST(test_lib, test_4)
{
	Convertor c;
	Arabic ar;
	ar.value = 4;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("IV", c.get_roman().value);
}
TEST(test_lib, test_9)
{
	Convertor c;
	Arabic ar;
	ar.value = 4;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("IX", c.get_roman().value);
}
TEST(test_lib, test_7)
{
	Convertor c;
	Arabic ar;
	ar.value = 7;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("VII", c.get_roman().value);
}
TEST(test_lib, test_99)
{
	Convertor c;
	Arabic ar;
	ar.value = 99;
	c.ConvertToRoman(ar);
	EXPECT_TRUE("XCIX", c.get_roman().value);
}
TEST(test_lib, test_I)
{
	Convertor c;
	Roman r;
	r.value = "I";
	c.ConvertToArabic(r);
	EXPECT_TRUE(1, c.get_arabic().value);
}
TEST(test_lib, test_IV)
{
	Convertor c;
	Roman r;
	r.value = "IV";
	c.ConvertToArabic(r);
	EXPECT_TRUE(4, c.get_arabic().value);
}
TEST(test_lib, test_VI)
{
	Convertor c;
	Roman r;
	r.value = "VI";
	c.ConvertToArabic(r);
	EXPECT_TRUE(6, c.get_arabic().value);
}
TEST(test_lib, test_IX)
{
	Convertor c;
	Roman r;
	r.value = "IX";
	c.ConvertToArabic(r);
	EXPECT_TRUE(9, c.get_arabic().value);
}
TEST(test_lib, test_X)
{
	Convertor c;
	Roman r;
	r.value = "X";
	c.ConvertToArabic(r);
	EXPECT_TRUE(10, c.get_arabic().value);
}
TEST(test_lib, test_XCIX)
{
	Convertor c;
	Roman r;
	r.value = "XCIX";
	c.ConvertToArabic(r);
	EXPECT_TRUE(99, c.get_arabic().value);
}
TEST(test_lib, test_chech_when_number_is_wrong1)
{
	Convertor c;
	Roman r;
	r.value = "IIIIII";
	r = c.check(r);
	EXPECT_TRUE("VI", r.value);
}
TEST(test_lib, test_check_when_number_is_wrong2)
{
	Convertor c;
	Roman r;
	r.value = "XXXXXXX";
	r = c.check(r);
	EXPECT_TRUE("LXX", r.value);
}
TEST(test_lib, test_check_when_number_is_correct)
{
	Convertor c;
	Roman r;
	r.value = "XIII";
	r = c.check(r);
	EXPECT_TRUE("XIII", r.value);
}