#ifndef GOALY_H
#define GOALY_H
#include "player.h"
class Goaly : public Player {
private:

	bool saveShot(int x, int y) {
		return (x > y);
	}
};
#endif
