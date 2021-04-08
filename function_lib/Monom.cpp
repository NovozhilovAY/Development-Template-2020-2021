#include "Monom.h"

void Monom::set_power(int A, int B, int C)
{
	power = A * max_power * max_power + B * max_power + C;
}

Monom::Monom()
{
	coef = 1;
	set_power(1, 1, 1);
}

Monom::Monom(int _coef, int A, int B, int C)
{
	if (A >= max_power || B >= max_power || C >= max_power)
	{
		throw std::exception("Power is too big!");
	}
	coef = _coef;
	set_power(A, B, C);
}

Monom::Monom(const Monom& m)
{
	coef = m.coef;
	power = m.power;
}

int Monom::get_A()const
{
	return power / max_power / max_power;
}

int Monom::get_B()const
{
	return (power - get_A() * max_power * max_power) / max_power;
}

int Monom::get_C()const
{
	return power % max_power;
}

int Monom::get_coef()const
{
	return coef;
}

bool Monom::operator==(const Monom& m) const
{
	return power == m.power;
}

bool Monom::operator!=(const Monom& m) const
{
	return power!=m.power;
}

bool Monom::operator<=(const Monom& m) const
{
	return power <= m.power;
}

bool Monom::operator>=(const Monom& m) const
{
	return power >= m.power;
}

bool Monom::operator>(const Monom& m) const
{
	return power > m.power;
}

bool Monom::operator<(const Monom& m) const
{
	return power < m.power;
}

Monom Monom::operator+(const Monom& m) const
{
	if (*this != m)
	{
		throw std::exception("Monoms aren't similar!");
	}
	Monom res(*this);
	res.coef += m.coef;
	return res;
}

Monom& Monom::operator+=(const Monom& m)
{
	if (*this != m)
	{
		throw std::exception("Monoms aren't similar!");
	}
	coef += m.coef;
	return *this;
}

Monom Monom::operator-(const Monom& m) const
{
	if (*this != m)
	{
		throw std::exception("Monoms aren't similar!");
	}
	Monom res(*this);
	res.coef += m.coef;
	return res;
}

Monom Monom::operator-() const
{
	Monom res(*this);
	res.coef *= -1;
	return res;
}

Monom& Monom::operator-=(const Monom& m)
{
	if (*this != m)
	{
		throw std::exception("Monoms aren't similar!");
	}
	coef -= m.coef;
	return *this;
}

Monom Monom::operator*(const Monom& m) const
{
	return Monom(coef*m.coef, get_A() + m.get_A(), get_B() + m.get_B(), get_C() + m.get_C());
}

Monom& Monom::operator*=(const Monom& m)
{
	coef *= m.coef;
	set_power(get_A() + m.get_A(), get_B() + m.get_B(), get_C() + m.get_C());
	return *this;
}

Monom Monom::operator*(const int& num) const
{
	Monom res(*this);
	res.coef *= num;
	return res;
}

Monom& Monom::operator*=(const int& num)
{
	coef *= num;
	return *this;
}

int Monom::calculate(int x, int y, int z)
{
	return coef * pow(x,get_A()) * pow(y,get_B()) * pow(z,get_C());
}

std::string Monom::to_str()const
{
	std::string res = "";
	int A = get_A();
	int B = get_B();
	int C = get_C();
	if (coef == -1)
	{
		res += "-";
	}
	else if (coef == 1)
	{
		res += "";
	}
	else if(coef == 0)
	{
		res += std::to_string(coef);
	}
	else
	{
		res += std::to_string(coef) + " * ";
	}

	if (A)
	{
		if (A == 1)
		{
			res += "X * ";
		}
		else
		{
			res += "X^" + std::to_string(A) + " * ";
		}
	}
	if (B)
	{
		if (B == 1)
		{
			res += "Y * ";
		}
		else
		{
			res += "Y^" + std::to_string(B) + " * ";
		}
	}
	if (C)
	{
		if (C == 1)
		{
			res += "Z ";
		}
		else
		{
			res += "Z^" + std::to_string(C) + " ";
		}
	}
	return res;
}
