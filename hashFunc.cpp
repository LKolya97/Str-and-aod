#include "hash.h"

int HashTable::hashFunc(string str) {
	int asciisum = 0;
	for (int i = 0; i < str.length(); i++) {
		asciisum += str[i];
	}
	setAsciiSum(asciisum);
	asciisum = asciisum % PRIME_SIZE;
	setAsciiKey(asciisum);
	return asciisum;
}

HashTable::HashTable() {
	for (int i = 0; i < PRIME_SIZE; i++) {
		table[i] = NULL;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < PRIME_SIZE; i++) {
		delete table[i];
	}
}

void HashTable::push(int luck, string name) {
	int hashNumber = hashFunc(name);
	Player *plr = new Player(luck, name);
	Player *place = table[hashNumber];
	if (place == NULL) {
		table[hashNumber] = plr;
		return;
	}

	while (place->next != NULL) {
		place = place->next;
	}
	place->next = plr;
}

Player* HashTable::find(string name) {
	int hashNumber = hashFunc(name);
	Player *result = table[hashNumber];
	if (!result) {
		cout << "Player is not found" << endl;
		return NULL;
	}
	while (result->name != name) {
		if (!result->next) {
			cout << "Player is not found" << endl;
			break;
		}
		result = result->next;
	}
	return result;
}
