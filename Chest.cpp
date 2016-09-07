#include "Chest.h"

Chest::Chest() {
	_name = "Your chest";
	_slots = 10;
}

bool Chest::addItem(Item* item) {
	if (_occupied >= _slots) {
		printf("\nThere is not enough space for this item...");
		return false;
	} else {
		_occupied++;
		_storedItems.push_back(item);
		return true;
	}
}