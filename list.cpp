#include 'list.h'
#include <iostream>
using namespace std;
void List::create{
	for (;;) {
		// Вводить числа, пока не введем 0
		сin » i;
		if (!i) break;

		// Создать новый элемент списка
		р = new Item;
		p->plr = i;

		// Присоединить новый элемент к началу списка
		p->next = first;
		first = р;
	}

void List::printList{
	р = first;
while (p) {
	cout « p->plr « » »;
	р = p->next;
}
}
void List::deleList{
	while (first) {
		р = first;
		first = first->next;
		delete p;
	}
}

