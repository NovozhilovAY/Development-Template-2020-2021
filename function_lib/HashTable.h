#pragma once
#include <iostream>
#define SIZE 20;
enum Status{EMPTY, OCCUPIED, DELETED};

struct Hash
{
	int key;
	Status status;
};

class HashTable
{
	Hash* data;
	int size;
	int count;

	int hash(int _key, int p);
public:
	HashTable();
	HashTable(int _size);
	~HashTable();
	void add(int _key);
	void remove(int _key);
	bool search(int _key);
	void printTable();
};