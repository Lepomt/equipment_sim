#pragma once

#include <fstream>
#include <string>

#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "FoodRation.h"

class Storage {
public:
	Storage() {
		_storedItems.reserve(_slots);
		_occupied = 1;
	}
	virtual ~Storage() = 0;
	//getters
	size_t getOccupied() { return _occupied; }
	//overloaded array operator used to access items inside storage
	Item& operator[](const size_t at);
	//method saving to file the contents of storage
	virtual void saveStorage(std::string fileName);
	//method loading from file items to storage
	virtual void loadStorage(std::string fileName);
	//method initializing storage (loads items, their bodies and descriptions)
	virtual void initStorage(std::string fileName);
	//shows the contents of storage by printing their numbered visual representations
	virtual void viewStorage();
	//shows all the available information about items in the storage (visual representation, description, statistics)
	virtual void showItemList();
	//adds an item if possible
	virtual bool addItem(Item* item) = 0;
	//finds an item and removes it if possible
	virtual bool removeItem(std::string itemName);
	//shows desired item and its statistics
	virtual void showItem(size_t which);
protected:
	std::string _name;
	size_t _slots; //contains the total number of accessible slots
	size_t _occupied; //keeps track of the amount of slots in use
	std::vector<Item*> _storedItems;
};

inline Storage::~Storage() {
	for (std::vector<Item*>::iterator it = _storedItems.begin(); it != _storedItems.end(); it++) {
		delete *it;
	}
	_storedItems.clear();
}

inline Item& Storage::operator[](const size_t at) {
	return *_storedItems.at(at);
}

inline void Storage::saveStorage(std::string fileName) {
	std::ofstream save;
	save.open(fileName);
	if (save.fail()) {
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}

	while (!_storedItems.empty()) {
		save << *_storedItems.back() << std::endl;
		_storedItems.pop_back();
	}
	save.close();
}

inline void Storage::loadStorage(std::string fileName) {
	std::ifstream load;
	load.open(fileName);
	if (load.fail()) {
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}
	//variable to check what class of item is being loaded
	std::string data;
	//variables holding values to initialize object's fields
	while (load >> data) {
		printf("\nOCC: %d, %s", _occupied, _name.c_str());
		//managing different cases of data loading
		switch (data[0]) {
		case 'P': //potion
			_storedItems.push_back(new Potion(0, 0, 0, 0));
			load >> *_storedItems.back();
			_occupied++;
			break;
		case 'F': //food ration
			_storedItems.push_back(new FoodRation(0, 0, 0, 0.0));
			load >> *_storedItems.back();
			_occupied++;
			break;
		case 'W': //weapon
			_storedItems.push_back(new Weapon(0, 0, 0, "\0", 0));
			load >> *_storedItems.back();
			_occupied++;
			break;
		case 'A': //armour
			_storedItems.push_back(new Armour(0, 0, 0, "\0", 0));
			load >> *_storedItems.back();
			_occupied++;
			break;
		}
	}
	load.close();
}

inline void Storage::initStorage(std::string fileName) {
	loadStorage(fileName);
	for (size_t it = 0; it < _storedItems.size(); it++) {
		_storedItems[it]->initializeItem("descriptions.txt", "ASCII_items.txt");
	}
}

inline void Storage::viewStorage() {
	for (size_t it = 0; it < _storedItems.size(); it++) {
		_storedItems[it]->printBody();
		printf("\n");
		_storedItems[it]->printDescription(std::cerr);
		_storedItems[it]->printStats();
	}
}

inline void Storage::showItemList() {
	for (size_t it = 0; it < _storedItems.size(); it++) {
		printf("%d. ", it+1);
		_storedItems[it]->printBody();
		printf("\n");
	}
}

inline bool Storage::removeItem(std::string itemName) {
	for (size_t it = 0; it < _storedItems.size(); it++) {
		if (_storedItems[it]->getName() == itemName) {
			_storedItems[it] = _storedItems.back();
			_storedItems.pop_back();
			_occupied--;
			return true;
		}
	}
	return false;
}

inline void Storage::showItem(size_t which) {
	if (which < 0 || which >= this->_occupied) {
		printf("Item not found at this index.");
	} else {
		_storedItems[which]->printBody();
		_storedItems[which]->printStats();
		_storedItems[which]->printDescription(std::cerr);
	}
}
