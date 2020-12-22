#include "PolishConvertor.h"

#include <gtest.h>

bool eq(double n1, double n2)
{
	double eps = 0.00001;
	double tmp = abs(n1 - n2);
	if (tmp < eps)
	{
		return true;
	}
	else
	{
		return false;
	}
}

TEST(polishConvertor, can_add)
{
    EXPECT_NO_THROW(PolishConvertor pc("2+2"));
}
TEST(polishConvertor, can2_add)
{
	PolishConvertor pc;
	pc.ConvertToPolish("2+2");
	double res = pc.Calculate();
	EXPECT_EQ(4,res);
}
TEST(polishConvertor, can_sub)
{
	PolishConvertor pc;
	pc.ConvertToPolish("2-4");
	double res = pc.Calculate();
	EXPECT_EQ(-2, res);
}
TEST(polishConvertor, can_mult)
{
	PolishConvertor pc;
	pc.ConvertToPolish("2*4");
	double res = pc.Calculate();
	EXPECT_EQ(8, res);
}
TEST(polishConvertor, can_div)
{
	PolishConvertor pc;
	pc.ConvertToPolish("10/5");
	double res = pc.Calculate();
	EXPECT_EQ(2, res);
}
TEST(polishConvertor, un_minus_works)
{
	PolishConvertor pc;
	pc.ConvertToPolish("-5 + 3");
	double res = pc.Calculate();
	EXPECT_EQ(-2, res);
}
TEST(polishConvertor, module_works)
{
	PolishConvertor pc;
	pc.ConvertToPolish("|-5 + 3|");
	double res = pc.Calculate();
	EXPECT_EQ(2, res);
}
TEST(polishConvertor, exponentiation_works)
{
	PolishConvertor pc;
	pc.ConvertToPolish("2^10");
	double res = pc.Calculate();
	EXPECT_EQ(1024, res);
}
TEST(polishConvertor, expression_with_brackets)
{
	PolishConvertor pc;
	pc.ConvertToPolish("(2+3)+(2-(2+2))");
	double res = pc.Calculate();
	EXPECT_EQ(3, res);
}
TEST(polishConvertor, works_with_double_nums)
{
	PolishConvertor pc;
	pc.ConvertToPolish("2.3-1.1");
	double res = pc.Calculate();
	EXPECT_TRUE(eq(1.2, res));
}

TEST(polishConvertor, throw_when_brackets_are_incorrect)
{
	PolishConvertor pc;
	
	EXPECT_ANY_THROW(pc.ConvertToPolish("(2.3-1.1))"));
}
TEST(polishConvertor, throw_when_incorrect_signs_sequence)
{
	PolishConvertor pc;
	EXPECT_ANY_THROW(pc.ConvertToPolish("2*+4"));
}
TEST(polishConvertor, throw_when_incorrect_symbol)
{
	PolishConvertor pc;
	EXPECT_ANY_THROW(pc.ConvertToPolish("2$4"));
}
TEST(polishConvertor, solution_of_difficult_expression_1)
{
	PolishConvertor pc;
	pc.ConvertToPolish("(6 - 20) - 2 + 4 - (-2.5 ^ (2 * 2) - 5)");
	double res = pc.Calculate();
	EXPECT_TRUE(eq(32.0625, res));
}
TEST(polishConvertor, solution_of_difficult_expression_2)
{
	PolishConvertor pc;
	pc.ConvertToPolish("(3 * 5 + 8 / (2.0 + 3 * 2))");
	double res = pc.Calculate();
	EXPECT_TRUE(eq(16, res));
}
TEST(polishConvertor, solution_of_difficult_expression_3)
{
	PolishConvertor pc;
	pc.ConvertToPolish("(3 * 5 + 8 / (2.0 + 3 * 2)) - |20 * (-100)|");
	double res = pc.Calculate();
	EXPECT_TRUE(eq((-1984), res));
}
TEST(polishConvertor, can_add_var)
{
	PolishConvertor pc;
	pc.ConvertToPolish("a+2");
	EXPECT_NO_THROW(pc.AddVar("a",2));
}
TEST(polishConvertor, can_calculate_with_vars)
{
	PolishConvertor pc;
	pc.ConvertToPolish("a+b+c-10");
	pc.AddVar("a", 1);
	pc.AddVar("b", 2);
	pc.AddVar("c", 3);
	EXPECT_TRUE(eq(pc.Calculate(),-4));
}