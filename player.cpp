#include "player.h"
#include <iostream>
using namespace std;
bool Player::pass(int x, int y) {
	if (x > y) {
		cout << "��� ������� �����\n";
		return 1;
	}
	else {
		cout << "��� ����������\n";
		return 0;
	}
}
bool Player::otbor(int x, int y) {
	if (x > y) {
		cout << "��� ������� �������\n";
		return 1;
	}
	else {
		cout << "��� �� �������\n";
		return 0;
	}
}
bool Player::shot(int x, int y) {
	if (x > y) {
		cout << "���!\n";
		return 1;
	}
	else {
		cout << "������� �����\n";
		return 0;
	}
}
