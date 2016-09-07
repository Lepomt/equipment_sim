#include "SimulateEquiment.h"

void SimulateEquiment::playSimulation() {
	initializeSimulation();
	handleMenu();
	saveAndQuit();
}

void SimulateEquiment::initializeSimulation() {
	_playerChest.initStorage("chest.txt");
	_playerBackpack.initStorage("backpack.txt");
}

void SimulateEquiment::saveAndQuit() {
	_playerChest.saveStorage("chest.txt");
	_playerBackpack.saveStorage("backpack.txt");
	printf("Press any key to exit...");
	_getch();
}


size_t SimulateEquiment::optionsMenu() {
	printf("\n"
		"\nWhat do you want to do?"
		"\n1. Put an item into the chest."
		"\n2. Take an item from the chest."
		"\n3. See the contents of the chest."
		"\n4. Look at your equipment."
		"\n5. Show an item and its statistics."
		"\n0. Leave and save.");
	size_t choice = 0;
	while (true) {
		printf("\nChoice: ");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 5) return choice;
		printf("Invalid intput. Try again...");
		_getch();
	}
}

void SimulateEquiment::handleMenu() {
	size_t which;
	while (true) {
		switch (optionsMenu()) {
		case 1:
			_playerBackpack.showItemList();
			printf("\nPress number key coressponding to the item you want to move: ");
			scanf_s("%d", &which);
			while (which >= _playerBackpack.getOccupied()) {
				printf("\nIt appears you do not have so many items.\nTry again: ");
				scanf_s("%d", &which);
			}
			if (transferItem(_playerBackpack, _playerChest, &_playerBackpack[which - 1])) {
				printf("\nTransfer  complete.\n");
			} else {
				printf("\nTransfer  failed.\n");
			}
			break;
		case 2:
			_playerChest.showItemList();
			printf("\nPress number key coressponding to the item you want to take out: ");
			scanf_s("%d", &which);
			while (which > _playerChest.getOccupied()) {
				printf("\nIt appears you do not have so many items.\nTry again: ");
				scanf_s("%d", &which);
			}
			if (transferItem(_playerChest, _playerBackpack, &_playerChest[which - 1])) {
				printf("\nTransfer  complete.\n");
			} else {
				printf("\nTransfer  failed.\n");
			}
			break;
		case 3:
			_playerChest.viewStorage();
			break;
		case 4:
			_playerBackpack.viewStorage();
			break;
		case 5:
			printf("\nShow item from: "
				"\n1. Backpack."
				"\n2. Chest.");
			scanf_s("%d", &which);
			which--;
			if (which == 0 || which == 1) {
				//shows contents of desired storage
				if (!which) _playerBackpack.showItemList();
				else _playerChest.showItemList();
				printf("\nWhich item do you want to view: ");
				scanf_s("%d", &which);
				//shows specific item
				if (!which) _playerBackpack.showItem(which - 1);
				else _playerChest.showItem(which - 1);
			} else printf("Choice not valid, try again.");
			break;
		case 0:
			return;
		default:
			printf("\nError.");
		}
	}
}

bool SimulateEquiment::transferItem(Storage& source, Storage& destination, Item* item) {
	//checks if item transfer can be done
	if (source.removeItem(item->getName())) {
		if (destination.addItem(item)) {
			return true;
		} else {
			//add the item back to source if it can not be added to destination
			source.addItem(item);
			return false;
		}
	}
	return false;
}