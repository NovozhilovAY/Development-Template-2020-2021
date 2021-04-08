#include "Polinom.h"
PolinomIterator::PolinomIterator()
{
	list = nullptr;
	cur_node = nullptr;
}
PolinomIterator::PolinomIterator(std::list<Monom>& _list)
{
	list = &_list;
	init();
}

void PolinomIterator::set_list(std::list<Monom>& _list)
{
	list = &_list;
	cur_node = list->begin()._Ptr;
}

void PolinomIterator::init()
{
	cur_node = list->begin()._Ptr;
}

bool PolinomIterator::has_next()
{
	if (cur_node != list->end()._Ptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PolinomIterator::go_next()
{
	if (!has_next())
	{
		throw std::exception("Out of list!");
	}
	cur_node = cur_node->_Next;
}

Monom& PolinomIterator::get_value()
{
	return cur_node->_Myval;
}

void PolinomIterator::del_cur()
{
	auto it = list->begin();
	while (it._Ptr!=cur_node)
	{
		it++;
	}
	list->erase(it);
}

void PolinomIterator::insert_before(const Monom& m)
{
	auto it = list->begin();
	while (it._Ptr != cur_node)
	{
		it++;
	}
	list->insert(it,m);
}
