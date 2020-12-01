#include <stdio.h>
#include "QueueOnList.h"
#include <locale>
int main() {
	setlocale(LC_ALL, "Russian");
	QueueOnList<int> queue;
	std::cout << "���������� �������:"<<std::endl;

	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
		queue.print();
	}
	
	std::cout << "������ ������� � �������:" << std::endl;
	std::cout << queue.front() << std::endl;
	std::cout << "��������� ������� � �������:" << std::endl;
	std::cout << queue.back() << std::endl;
	std::cout << "�������� ��������� �������:" << std::endl;
	queue.print();
	while (!queue.empty())
	{
		queue.pop();
		queue.print();
	}
	return 0;
}