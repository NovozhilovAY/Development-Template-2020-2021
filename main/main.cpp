#include <iostream>
#include <locale>
#include "TList.h"


int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "������������ ������\n";
	TList<int> list;
	std::cout << "�������� �������� 4 � ������ ������\n";
	list.InsFirst(4);
	std::cout << "�������� �������� 6 � ������ ������\n";
	list.InsFirst(6);
	std::cout << "�������� �������� 2 � ������ ������\n";
	list.InsFirst(2);
	std::cout << "�������� �������� 17 � ����� ������\n";
	list.InsLast(17);
	std::cout << "�������� �������� 3 � ����� ������\n";
	list.InsLast(3);
	list.print();
	std::cout << "������� �� ������ ������\n";
	std::cout << "������� �� ����� ������\n";
	list.DelFirst();
	list.DelLast();
	list.print();
	std::cout << "������� ������\n";
	list.DelList();
	list.print();
	return 0;
}