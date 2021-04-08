#pragma once
#include <iostream>
#include <string>
#define max_power 20

class Monom
{
private:
	int coef;
	int power;

	void set_power(int A, int B, int C);
public:
	Monom();
	Monom(int _coef, int A, int B, int C);
	Monom(const Monom& m);

	int get_A()const;
	int get_B()const;
	int get_C()const;
	int get_coef()const;

	bool operator==(const Monom& m)const;
	bool operator!=(const Monom& m)const;
	bool operator<=(const Monom& m)const;
	bool operator>=(const Monom& m)const;
	bool operator>(const Monom& m)const;
	bool operator<(const Monom& m)const;

	Monom operator+(const Monom& m)const;
	Monom& operator+=(const Monom& m);

	Monom operator-(const Monom& m)const;
	Monom operator-()const;
	Monom& operator-=(const Monom& m);

	Monom operator*(const Monom& m)const;
	Monom& operator*=(const Monom& m);

	Monom operator*(const int& num)const;
	Monom& operator*=(const int& num);

	int calculate(int x, int y, int z);

	std::string to_str()const;

};