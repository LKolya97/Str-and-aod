#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
		int luck;
		int number;
public:

	int getLuck() {
		return luck;
	}
	void setLuck(int x) {
		luck = x;
	}
		int getNumber() {
		return number;
	}
	void setNumber(int x) {
		number = x;
	}
	Player() {
		luck = NULL;
		number=NULL;
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
