#include "Polinom.h"

#include <gtest.h>

TEST(Monom, the_default_constructor_works)
{
	EXPECT_NO_THROW(Monom m);
}

TEST(Monom, the_constructor_with_parameters_works)
{
	EXPECT_NO_THROW(Monom m(1,2,3,4));
}

TEST(Monom, throws_when_power_is_too_big)
{
	EXPECT_ANY_THROW(Monom m(1, 2, 50, 4));
}

TEST(Monom, the_copy_constructor_works)
{
	Monom m1;
	EXPECT_NO_THROW(Monom m(m1));
}

TEST(Monom, get_A_works)
{
	Monom m1;
	EXPECT_NO_THROW(m1.get_A());
}

TEST(Monom, get_B_works)
{
	Monom m1;
	EXPECT_NO_THROW(m1.get_B());
}

TEST(Monom, get_C_works)
{
	Monom m1;
	EXPECT_NO_THROW(m1.get_C());
}

TEST(Monom, get_coef_works)
{
	Monom m1;
	EXPECT_NO_THROW(m1.get_coef());
}

TEST(Monom, get_A_returns_the_correct_value)
{
	Monom m1(1,2,3,4);
	EXPECT_EQ(m1.get_A(),2);
}

TEST(Monom, get_B_returns_the_correct_value)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ(m1.get_B(), 3);
}

TEST(Monom, get_C_returns_the_correct_value)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ(m1.get_C(), 4);
}

TEST(Monom, get_coef_returns_the_correct_value)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ(m1.get_coef(), 1);
}

TEST(Monom, operator_ravnoravno_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 == m2);
}

TEST(Monom, operator_ravnoravno_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_TRUE(m1 == m2);
}

TEST(Monom, operator_ravnoravno_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_FALSE(m1 == m2);
}

TEST(Monom, operator_neravno_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 != m2);
}

TEST(Monom, operator_neravno_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_TRUE(m1 != m2);
}

TEST(Monom, operator_neravno_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_FALSE(m1 != m2);
}

TEST(Monom, operator_more_eq_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 >= m2);
}

TEST(Monom, operator_more_eq_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_TRUE(m1 >= m2);
}

TEST(Monom, operator_more_eq_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_FALSE(m1 >= m2);
}

TEST(Monom, operator_less_eq_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 <= m2);
}

TEST(Monom, operator_less_eq_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_TRUE(m1 <= m2);
}

TEST(Monom, operator_less_eq_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_FALSE(m2 <= m1);
}

TEST(Monom, operator_more_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 > m2);
}

TEST(Monom, operator_more_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 3, 4);
	EXPECT_TRUE(m1 > m2);
}

TEST(Monom, operator_more_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_FALSE(m1 > m2);
}

TEST(Monom, operator_less_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 < m2);
}

TEST(Monom, operator_less_returns_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 3, 4);
	EXPECT_TRUE(m2 < m1);
}

TEST(Monom, operator_less_returns_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_FALSE(m2 < m1);
}

TEST(Monom, operator_plus_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 + m2);
}

TEST(Monom, operator_plus_throws_when_monoms_not_similar)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_ANY_THROW(m1 + m2);
}

TEST(Monom, operator_plus_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(2, 2, 3, 4);
	EXPECT_EQ(res,m1 + m2);
}

TEST(Monom, operator_minus_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 2, 3, 4);
	EXPECT_NO_THROW(m1 - m2);
}

TEST(Monom, operator_minus_throws_when_monoms_not_similar)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 3, 3, 4);
	EXPECT_ANY_THROW(m1 - m2);
}

TEST(Monom, operator_minus_works_correctly)
{
	Monom m1(3, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(2, 2, 3, 4);
	EXPECT_EQ(res, m1 - m2);
}

TEST(Monom, operator_minus_eq_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 2, 3, 4);
	EXPECT_NO_THROW(m1 -= m2);
}

TEST(Monom, operator_minus_eq_throws_when_monoms_not_similar)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 3, 3, 4);
	EXPECT_ANY_THROW(m1 -= m2);
}

TEST(Monom, operator_minus_eq_works_correctly)
{
	Monom m1(3, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(2, 2, 3, 4);
	EXPECT_EQ(res, m1 -= m2);
}

TEST(Monom, operator_un_minus_works)
{
	Monom m1(3, 2, 3, 4);
	EXPECT_NO_THROW(-m1);
}

TEST(Monom, operator_un_minus_works_correctly)
{
	Monom m1(3, 2, 3, 4);
	Monom res(-3, 2, 3, 4);
	EXPECT_NO_THROW(res,-m1);
}


TEST(Monom, operator_plus_eq_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 += m2);
}

TEST(Monom, operator_plus_eq_throws_when_monoms_not_similar)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 3, 3, 4);
	EXPECT_ANY_THROW(m1 += m2);
}

TEST(Monom, operator_plus_eq_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(2, 2, 3, 4);
	EXPECT_EQ(res, m1 += m2);
}

TEST(Monom, operator_mult_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 * m2);
}

TEST(Monom, operator_mult_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(1, 4, 6, 8);
	EXPECT_EQ(res, m1 * m2);
}

TEST(Monom, operator_mult_eq_works)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_NO_THROW(m1 *= m2);
}

TEST(Monom, operator_mult_eq_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom res(1, 4, 6, 8);
	EXPECT_EQ(res, m1 *= m2);
}

TEST(Monom, calculate_works)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_NO_THROW(m1.calculate(1,2,3));
}

TEST(Monom, calculate_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ(512, m1.calculate(2, 2, 2));
}

TEST(Monom, to_str_works)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_NO_THROW(m1.to_str());
}

TEST(Monom, to_str_works_correctly)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ("X^2 * Y^3 * Z^4 ", m1.to_str());
}

TEST(Polinom, the_default_constructor_works)
{
	EXPECT_NO_THROW(Polinom m);
}

TEST(Polinom, the_constructor_with_parameters_works)
{
	Monom m;
	Monom m2;
	Monom m3;
	std::vector<Monom> monoms = { m, m2, m3 };
	EXPECT_NO_THROW(Polinom p(monoms));
}
TEST(Polinom, the_copy_constructor_works)
{
	Monom m;
	Monom m2;
	Monom m3;
	std::vector<Monom> monoms = { m, m2, m3 };
	Polinom p(monoms);
	EXPECT_NO_THROW(Polinom p2(p));
}

TEST(Polinom, the_eqeq_operator_works)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	std::vector<Monom> monoms = { m, m2, m3 };
	Polinom p(monoms);
	Polinom p2(monoms);
	EXPECT_NO_THROW(p == p2);
}

TEST(Polinom, the_eqeq_operator_returns_true)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	std::vector<Monom> monoms = { m, m2, m3 };
	Polinom p(monoms);
	Polinom p2(monoms);
	EXPECT_TRUE(p == p2);
}

TEST(Polinom, the_eqeq_operator_returns_false)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	std::vector<Monom> monoms2 = { m, m2, m4 };
	Polinom p(monoms1);
	Polinom p2(monoms2);
	EXPECT_FALSE(p == p2);
}

TEST(Polinom, plus_eq_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p += m4);
}

TEST(Polinom, plus_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p + m4);
}

TEST(Polinom, minus_eq_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p -= m4);
}

TEST(Polinom, minus_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p - m4);
}


TEST(Polinom, mult_eq_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p *= m4);
}

TEST(Polinom, mult_operator_works_with_monom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p * m4);
}

TEST(Polinom, plus_operator_works_with_polinom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	std::vector<Monom> monoms2 = { m, m2, m4 };
	Polinom p(monoms1);
	Polinom p2(monoms2);
	EXPECT_NO_THROW(p + p2);
}

TEST(Polinom, plus_eq_operator_works_with_polinom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	std::vector<Monom> monoms2 = { m, m2, m4 };
	Polinom p(monoms1);
	Polinom p2(monoms2);
	EXPECT_NO_THROW(p += p2);
}

TEST(Polinom, minus_operator_works_with_polinom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	std::vector<Monom> monoms2 = { m, m2, m4 };
	Polinom p(monoms1);
	Polinom p2(monoms2);
	EXPECT_NO_THROW(p - p2);
}

TEST(Polinom, minus_eq_operator_works_with_polinom)
{
	Monom m(1, 2, 3, 4);
	Monom m2(5, 6, 7, 8);
	Monom m3(9, 10, 11, 12);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m2, m3 };
	std::vector<Monom> monoms2 = { m, m2, m4 };
	Polinom p(monoms1);
	Polinom p2(monoms2);
	EXPECT_NO_THROW(p -= p2);
}

TEST(Polinom, to_str_works)
{
	Monom m(1, 2, 3, 4);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m4 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p.to_str());
}

TEST(Polinom, to_str_works_correctly)
{
	Monom m(1, 2, 3, 4);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m4 };
	Polinom p(monoms1);
	EXPECT_EQ("X^2 * Y^3 * Z^4 +X * Y * Z ", p.to_str());
}

TEST(Polinom, calculate_works)
{
	Monom m(1, 2, 3, 4);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m4 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p.Calculate(1, 2, 3));
}

TEST(Polinom, calculate_works_correctly)
{
	Monom m(1, 2, 3, 4);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m4 };
	Polinom p(monoms1);
	EXPECT_EQ(520, p.Calculate(2, 2, 2));
}