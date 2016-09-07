#pragma once

#include "Storage.h"

class Chest: public Storage {
public:
	Chest();
	bool addItem(Item* item);
};