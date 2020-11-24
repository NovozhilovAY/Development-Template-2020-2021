#include <iostream>
#include <locale>
#include "TList.h"


int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Тестирование списка\n";
	TList<int> list;
	std::cout << "Положили значение 4 в начало списка\n";
	list.InsFirst(4);
	std::cout << "Положили значение 6 в начало списка\n";
	list.InsFirst(6);
	std::cout << "Положили значение 2 в начало списка\n";
	list.InsFirst(2);
	std::cout << "Положили значение 17 в конец списка\n";
	list.InsLast(17);
	std::cout << "Положили значение 3 в конец списка\n";
	list.InsLast(3);
	list.print();
	std::cout << "Удалили из начала списка\n";
	std::cout << "Удалили из конца списка\n";
	list.DelFirst();
	list.DelLast();
	list.print();
	std::cout << "Удалили список\n";
	list.DelList();
	list.print();
	return 0;
}