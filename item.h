#include 'player.h'
struct Item {
	Player plr;
	Item* next;
};

void main()
{
	Item *first = 0; //��������� �� ������ ������
	Item *p;
	int i;
	// ������� ������
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

	// ������ ������ � ������� ��������
	� = first;
	while (p) {
		cout � p->plr � � �;
		� = p->next;
	}

	// ������ ������ � ������� ��������
	while (first) {
		� = first;
		first = first->next;
		delete p;
	}
}
