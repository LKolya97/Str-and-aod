#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
		int luck;
public:

	int getLuck() {
		return luck;
	}
	void setLuck(int x) {
		luck = x;
	}
	Player() {
		luck = 0;
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
