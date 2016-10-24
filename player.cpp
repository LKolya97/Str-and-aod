#include "player.h"
#include <iostream>
using namespace std;
bool Player::pass(int x, int y) {
	if (x > y) {
		cout << "пас успешно отдан\n";
		return 1;
	}
	else {
		cout << "пас перехвачен\n";
		return 0;
	}
}
bool Player::otbor(int x, int y) {
	if (x > y) {
		cout << "м€ч успешно отобран\n";
		return 1;
	}
	else {
		cout << "м€ч не отобран\n";
		return 0;
	}
}
bool Player::shot(int x, int y) {
	if (x > y) {
		cout << "√ол!\n";
		return 1;
	}
	else {
		cout << "вратарь отбил\n";
		return 0;
	}
}
