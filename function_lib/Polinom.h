#pragma once
#include <list>
#include <vector>
#include "Monom.h"

class Polinom;
class PolinomIterator {
private:
	std::list<Monom>* list;
	std::_List_node<Monom, void*>* cur_node;
public:
	PolinomIterator();
	PolinomIterator(std::list<Monom>& _list);
	void set_list(std::list<Monom>& _list);
	void init();
	bool has_next();
	void go_next();
	Monom& get_value();
	void del_cur();
	void insert_before(const Monom& m);

};

class Polinom
{
friend PolinomIterator;
private:
	std::list<Monom> polinom;
	PolinomIterator it;
public:
	Polinom();
	Polinom(const std::vector<Monom>& monoms);
	Polinom(const Polinom& p);
	Polinom& operator+=(const Monom& monom);
	Polinom operator+(const Monom& monom)const;

	Polinom operator-(const Monom& monom)const;
	Polinom& operator-=(const Monom& monom);

	Polinom operator*(const Monom& monom);
	Polinom& operator*=(const Monom& monom);

	Polinom operator+(Polinom& p);
	Polinom& operator+=(Polinom& p);

	Polinom operator-(Polinom& p);
	Polinom& operator-=(Polinom& p);
	Polinom operator*(Polinom& p);
	Polinom& operator*=(Polinom& p);

	Polinom operator*(const int& num)const;
	Polinom& operator*=(const int& num);

	Polinom operator-(const int& num)const;
	Polinom& operator-=(const int& num);

	Polinom operator+(const int& num)const;
	Polinom& operator+=(const int& num);

	bool operator==(const Polinom& p)const;
	Polinom& operator=(const Polinom& p);
	int Calculate(int x, int y, int z);

	std::string to_str();
	void DelPolinom();

private:
	void del_nulls();
	void set_null();
};
