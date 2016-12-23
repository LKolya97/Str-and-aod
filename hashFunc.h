#include <iostream>
#include <string>
#include "player.h"
using namespace std;
#define PRIME_SIZE 53 


class HashTable {
	int asciiSum;
	int asciiKey;
public:
	Player *table[PRIME_SIZE];
	HashTable();
	~HashTable();
	void setAsciiSum(int ascii1) {
		asciiSum = ascii1;
	}
	int getAsciiSum() {
		return asciiSum;
	}
	void setAsciiKey(int ascii2) {
		asciiKey = ascii2;
	}
	int getAsciiKey() {
		return asciiKey;
	}
	int hashFunc(string str);
	void push(int luck, string name); 
	Player* find(string name); 
};
