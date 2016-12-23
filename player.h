#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#include <iostream>
using namespace std;
class Player {
private:
		int luck;
		string name;
public:

	int getLuck() {
		return luck;
	}
	void setLuck(int x) {
		luck = x;
	}
	int getName() {
		return name;
	}
	void setName(string x) {
		name = x;
	}
	Player() {
		luck = 0;
		name = NULL;
	}
	~Player() {
	}
	
		bool pass(int x, int y) {
		}
		bool otbor(int x, int y) {
		}
		bool shot(int x, int y) {
		}

	};
#endif
