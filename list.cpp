#include 'list.h'
#include <iostream>
using namespace std;
void List::create{
	for (;;) {
		// ������� �����, ���� �� ������ 0
		�in � i;
		if (!i) break;

		// ������� ����� ������� ������
		� = new Item;
		p->plr = i;

		// ������������ ����� ������� � ������ ������
		p->next = first;
		first = �;
	}

void List::printList{
	� = first;
while (p) {
	cout � p->plr � � �;
	� = p->next;
}
}
void List::deleList{
	while (first) {
		� = first;
		first = first->next;
		delete p;
	}
}

