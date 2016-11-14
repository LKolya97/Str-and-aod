#include 'player.h'
struct Item {
	Player plr;
	Item* next;
};

void main()
{
	Item *first = 0; //Указатель на начало списка
	Item *p;
	int i;
	// Создать список
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

	// Пройти список и вывести элементы
	р = first;
	while (p) {
		cout « p->plr « » »;
		р = p->next;
	}

	// Пройти список и удалить элементы
	while (first) {
		р = first;
		first = first->next;
		delete p;
	}
}
