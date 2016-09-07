#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>

class Item {
public:
	//constructor
	Item(size_t value, size_t weight):
		_value(value), _weight(weight) {}
	//virtual destructor
	virtual ~Item() {}
	//getters
	virtual std::string getName() const { return _name; }
	virtual size_t getValue() const{ return _value; }
	virtual size_t getWeight() const { return _weight; }
	//function initializing item's elements from text files
	void initializeItem(std::string description, std::string body) {
		loadDescription(description);
		setupBody(body);
	}
	//method used to print item statistics
	virtual void printStats() {
		printf("\nValue:     %d gold pieces\nWeight:    %d kg", _value, _weight);
	}
	//method used to load the item "body" from a text file
	virtual void setupBody(std::string fileName);
	//prints the "body" of an item
	void printBody() {
		printf("\n");
		for (std::vector<std::string>::const_iterator line = _body.begin(); line != _body.end(); line++) printf("%s\n", line->c_str());
	}
	//method used to load the item description from a text file
	virtual void loadDescription(std::string fileName);
	//method used to print the description of an item
	virtual void printDescription(std::ostream& ostr) {
		ostr << _name << std::endl;
		for (std::vector<std::string>::const_iterator line = _description.begin(); line != _description.end(); line++)
			ostr << *line << std::endl;
	}
	//method used to collect item's statistic into an output stream
	virtual std::ostream& output(std::ostream& ostr) const {
		ostr << _name << ' ' << _value << ' ' << _weight;
		return ostr;
	}
	//overloaded insertion stream operator used to output the item statistics
	friend std::ostream& operator<<(std::ostream& ostr, Item& item) {
		item.output(ostr);
		return ostr;
	}
	//method used to prepare input stream to fill item's fields
	virtual std::istream& input(std::istream& istr) {
		istr >> _value >> _weight;
		return istr;
	}
	//overloaded exctraction stream operator used to output the item statistics
	friend std::istream& operator>>(std::istream& istr, Item& item) {
		item.input(istr);
		return istr;
	}
protected:
	std::string _name;
	size_t _value;
	size_t _weight;
	std::vector<std::string> _description;
	//vector of strings that will contain the visual representation of an item
	std::vector<std::string> _body;
};

//method used to load the item description from a text file
inline void Item::loadDescription(std::string fileName) {
	//creates input file stream
	std::ifstream load;
	//opens file 
	load.open(fileName);
	//checks if file is open
	if (load.fail()) {
		//prints error and quits if file failed to load
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}
	//iterates through file and adds lines to the item's description vector
	std::string line;
	while (getline(load, line)) {
		if (line == _name) {
			getline(load, line);
			while (line != _name) {
				_description.push_back(line);
				getline(load, line);
			}
		}
	}
	load.close();
}

//method used to load the item "body" from a text file
inline void Item::setupBody(std::string fileName) {
	std::ifstream load;
	load.open(fileName);
	if (load.fail()) {
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}
	//iterates through file and pushes strings which are "parts" of an item to the body vector
	std::string line;
	while (getline(load, line)) {
		if (line == _name) {
			getline(load, line);
			while (line != _name) {
				_body.push_back(line);
				getline(load, line);
			}
		}
	}
	load.close();
}