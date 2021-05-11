#include "HashTable.h"

int HashTable::hash(int _key, int p)
{
	return (std::abs(_key) + p) % size;
}

HashTable::HashTable()
{
	size = SIZE;
	data = new Hash[size];
	count = 0;
	for (int i = 0; i < size; ++i)
	{
		data[i].key = 0;
		data[i].status = EMPTY;
	}
}

HashTable::HashTable(int _size)
{
	size = _size;
	data = new Hash[size];
	count = 0;
	for (int i = 0; i < size; ++i)
	{
		data[i].key = 0;
		data[i].status = EMPTY;
	}
}

HashTable::~HashTable()
{
	delete[] data;
}

void HashTable::add(int _key)
{
	int index = hash(_key, 0);
	if (data[index].status == OCCUPIED)
	{
		for (int i = 0; i < size; ++i)
		{
			index = hash(_key, 0);
			if (data[index].status == EMPTY || data[index].status == DELETED)
			{
				break;
			}
		}
	}
	//предусмотреть переполнение
	data[index].key = _key;
	data[index].status = OCCUPIED;
}

void HashTable::printTable()
{
	std::cout << "Index\t" << "Data\t" << "Status\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << i << "\t" << data[i].key << "\t";// << data[i].status << "\n";
		switch (data[i].status)
		{
		case EMPTY:
			std::cout << "EMPTY\n";
			break;
		case OCCUPIED:
			std::cout << "OCCUPIED\n";
			break;
		case DELETED:
			std::cout << "DELETED\n";
			break;
		}
	}
}
