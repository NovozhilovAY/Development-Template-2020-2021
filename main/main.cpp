#include <stdio.h>
#include "HashTable.h"

int main() {
	HashTable h;
	h.printTable();
	h.add(7);
	h.add(3);
	h.add(228);
	h.add(-4);
	h.printTable();
  return 0;
}