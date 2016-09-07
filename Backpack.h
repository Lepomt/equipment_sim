#pragma once

#include "Storage.h"

class Backpack: public Storage {
public:
	Backpack();
	size_t totalWeight();
	bool addItem(Item* item);
private:
	size_t _capacity;
};