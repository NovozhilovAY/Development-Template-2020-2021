#include "Polinom.h"

bool Polinom::operator==(const Polinom& p)const
{
	return polinom == p.polinom;
}

Polinom& Polinom::operator=(const Polinom& p)
{
	polinom = p.polinom;
	it.init();
	return *this;
}

int Polinom::Calculate(int x, int y, int z)
{
	int res=0;
	it.init();
	while (it.has_next())
	{
		res += it.get_value().calculate(x, y, z);
		it.go_next();
	}
	return res;
}

std::string Polinom::to_str()
{
	std::string res = "";
	it.init();
	bool add_first_flag = false;
	Monom tmp = it.get_value();
	while (it.has_next())
	{
		if (tmp.get_coef() > 0 && add_first_flag)
		{
			res += "+" + tmp.to_str();
		}
		else
		{
			res += tmp.to_str();
		}
		it.go_next();
		tmp = it.get_value();
		add_first_flag = true;
	}

	return res;
}

void Polinom::DelPolinom()
{
	polinom.clear();
	set_null();
}

void Polinom::del_nulls()
{
	it.init();
	while (it.has_next())
	{
		if (it.get_value().get_coef() == 0)
		{
			it.del_cur();
			it.init();
		}
		if (!it.has_next())
		{
			break;
		}
		it.go_next();
	}
	if (polinom.size() == 0)
	{
		set_null();
	}
}

void Polinom::set_null()
{
	Monom null_monom(0, 0, 0, 0);
	if (polinom.size() == 0)
	{
		polinom.push_back(null_monom);
	}
}

Polinom::Polinom()
{
	Monom m(0, 0, 0, 0);
	polinom.push_back(m);
	it.set_list(polinom);
}

Polinom::Polinom(const std::vector<Monom>& monoms)
{
	if (monoms.size() == 0)
	{
		throw std::exception("Initial vector is empty!");
	}
	for (int i = 0; i < monoms.size(); i++)
	{
		it.set_list(polinom);
		*this += monoms[i];
	}
	del_nulls();
}

Polinom::Polinom(const Polinom& p)
{
	polinom = p.polinom;
	it.set_list(polinom);
	it.init();
}

Polinom Polinom::operator+(const Monom& monom) const
{
	Polinom res(*this);
	res += monom;
	return res;
}

Polinom Polinom::operator-(const Monom& monom) const
{
	Polinom res(*this);
	res -= monom;
	return res;
}

Polinom& Polinom::operator-=(const Monom& monom)
{
	if (polinom.size() == 0)
	{
		polinom.push_back(-monom);
		del_nulls();
		return *this;
	}
	it.init();
	while (it.has_next())
	{
		if (it.get_value() == monom)
		{
			it.get_value() -= monom;
			del_nulls();
			return *this;
		}
		else if (it.get_value() < monom)
		{
			it.insert_before(-monom);
			del_nulls();
			return *this;
		}
		it.go_next();
	}
	polinom.push_back(monom);
	del_nulls();
	return *this;
}

Polinom Polinom::operator*(const Monom& monom)
{
	Polinom p;
	it.init();
	while (it.has_next())
	{
		p += it.get_value() * monom;
		it.go_next();
	}
	return p;
}

Polinom& Polinom::operator*=(const Monom& monom)
{
	Polinom p;
	it.init();
	while (it.has_next())
	{
		p += it.get_value() * monom;
		it.go_next();
	}
	*this = p;
	return *this;
}

Polinom Polinom::operator+(Polinom& p)
{
	Polinom res(*this);
	p.it.init();
	while (p.it.has_next())
	{
		res += p.it.get_value();
		p.it.go_next();
	}
	return res;
}

Polinom& Polinom::operator+=(Polinom& p)
{
	p.it.init();
	while (p.it.has_next())
	{
		*this += p.it.get_value();
		p.it.go_next();
	}
	return *this;
}

Polinom Polinom::operator-(Polinom& p)
{
	Polinom res(*this);
	p.it.init();
	while (p.it.has_next())
	{
		res -= p.it.get_value();
		p.it.go_next();
	}
	return res;
}

Polinom& Polinom::operator-=(Polinom& p)
{
	p.it.init();
	while (p.it.has_next())
	{
		*this -= p.it.get_value();
		p.it.go_next();
	}
	return *this;
}

Polinom Polinom::operator*(Polinom& p)
{
	Polinom res;
	p.it.init();
	it.init();
	while (it.has_next())
	{
		while (p.it.has_next())
		{
			res += it.get_value() * p.it.get_value();
			p.it.go_next();
		}
		p.it.init();
		it.go_next();
	}

	return res;
}

Polinom& Polinom::operator*=(Polinom& p)
{
	Polinom res;
	p.it.init();
	it.init();
	while (it.has_next())
	{
		while (p.it.has_next())
		{
			res += it.get_value() * p.it.get_value();
			p.it.go_next();
		}
		p.it.init();
		it.go_next();
	}
	*this = res;
	return *this;
}

Polinom Polinom::operator*(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res *= m;
	return res;
}

Polinom& Polinom::operator*=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this *= m;
	return *this;
}

Polinom Polinom::operator-(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res -= m;
	return res;
}

Polinom& Polinom::operator-=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this -= m;
	return *this;
}

Polinom Polinom::operator+(const int& num) const
{
	Monom m(num, 0, 0, 0);
	Polinom res(*this);
	res += m;
	return res;
}

Polinom& Polinom::operator+=(const int& num)
{
	Monom m(num, 0, 0, 0);
	*this += m;
	return *this;
}

Polinom& Polinom::operator+=(const Monom& monom)
{
	if (polinom.size() == 0)
	{
		polinom.push_back(monom);
		del_nulls();
		return *this;
	}
	it.init();
	while (it.has_next())
	{
		if (it.get_value() == monom)
		{
			it.get_value() += monom;
			del_nulls();
			return *this;
		}
		else if(it.get_value() < monom)
		{
			it.insert_before(monom);
			del_nulls();
			return *this;
		}
		it.go_next();
	}
	polinom.push_back(monom);
	del_nulls();
	return *this;
}
