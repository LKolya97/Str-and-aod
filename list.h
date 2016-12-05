// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "player.h"
using namespace std;
struct element {
	Player plr;
	element *Next;
};

class List {
	element *Head;
public:
	List() { Head = NULL; }
	~List();
	void Add(Player plr);
	void Show();
};

void List::Add(Player plr) {
	element *temp = new element;
	temp->plr = plr;
	temp->Next = Head;
	Head = temp;
}
List::~List() {
	while (Head != NULL) {
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}

void List::Show() {
	element *temp = Head;
	while (temp != NULL) {
		cout << temp->plr << " ";
			temp=temp->Next;
	}
}
int main()
{

    return 0;
}

