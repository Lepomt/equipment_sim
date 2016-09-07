#include "Backpack.h"

Backpack::Backpack() {
	_name = "Player";
	_slots = 6;
	_capacity = 30;
}
size_t Backpack::totalWeight() {
	size_t total = 0;
	for (size_t it = 0; it < _storedItems.size(); it++) {
		total += _storedItems[it]->getWeight();
	}
	return total;
}

bool Backpack::addItem(Item* item) {
	if (_occupied >= _slots) {
		printf("\nThere is not enough space for this item...");
		return false;
	} else if (_capacity < totalWeight() + item->getWeight()) {
		printf("\nThis item is too heavy!");
		return false;
	} else { 
		_occupied++;
		_storedItems.push_back(item);
		return true;
	}
}