#pragma once

#include "Storage.h"
#include "Chest.h"
#include "Backpack.h"

class SimulateEquiment {
public:
	SimulateEquiment() {}
	//method used to wrap all of the project's functionality
	void playSimulation();
	//methotd used to initialize player's backpack and chest from file's 
	void initializeSimulation();
	//saves equipment changes to text files and quits
	void saveAndQuit();
	//prints available options and ask user for input
	size_t optionsMenu();
	//handles user input
	void handleMenu();
	//tries to transfer given item between source and destination, returns false if failed
	bool transferItem(Storage& source, Storage& destination, Item* item);
private:
	Chest _playerChest;
	Backpack _playerBackpack;
};