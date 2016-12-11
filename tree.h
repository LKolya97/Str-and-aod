// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
struct Node {    //структура
	int number;
	Node *l, *r;
};
Node *tree = NULL;
void push(int a, Node **t) {  //добавление элемента в дерево
	if ((*t) == NULL) {
		(*t) = new Node;
		(*t)->number = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}
	if (a > (*t)->number) push(a, &(*t)->r);
	else push(a, &(*t)->l);
}

void print(Node *t, int u) {
	if (t == NULL)
		return;
	else {
		print(t->l, ++u);
		for (int i = 0; i < u; ++i)cout << "|";
		cout << t->number << endl;
		u--;
	}
	print(t->r, ++u);
}
int main()
{
	int n, s;
	cout << "enter the amount of numbers";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "enter the number";
		cin >> s;
		push(s, &tree);
	}
	cout << "your tree: \n";
	print(tree, 0);
	cin >> n;
    return 0;
}

