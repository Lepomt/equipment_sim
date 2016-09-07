#pragma once

#include "Item.h"

class Wearable: public Item {
public:
	Wearable(size_t value, size_t weight, size_t durability, std::string type) :
		Item(value, weight), _durability(100), _type(type) { }
	double getDur() const { return _durability; }
	void setupBody(std::string fileName);
	void loadDescription(std::string fileName);
	virtual void printStats() {
		Item::printStats();
		printf("\nDurability: %d", _durability);
	}
	void printDescription(std::ostream& ostr);
	virtual std::ostream& output(std::ostream& ostr) const {
		Item::output(ostr);
		ostr << ' ' << _durability << ' ' << _type;
		return ostr;
	}
	virtual std::istream& input(std::istream& istr) {
		Item::input(istr);
		istr >> _durability >> _type;
		return istr;
	}
protected:
	size_t _durability;
	std::string _type;
};

inline void Wearable::setupBody(std::string fileName) {
	std::ifstream load;
	load.open(fileName);
	if (load.fail()) {
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}
	std::string line;
	while (getline(load, line)) {
		if (line == _type) {
			getline(load, line);
			while (line != _type) {
				_body.push_back(line);
				getline(load, line);
			}
		}
	}
	load.close();
}

inline void Wearable::loadDescription(std::string fileName) {
	std::ifstream load;
	load.open(fileName);
	if (load.fail()) {
		perror(fileName.c_str());
		printf("\nPress any key to continue.");
		_getch();
		exit(1);
	}
	std::string line;
	while (getline(load, line)) {
		if (line == _type) {
			getline(load, line);
			while (line != _type) {
				_description.push_back(line);
				getline(load, line);
			}
		}
	}
	load.close();
}

inline void Wearable::printDescription(std::ostream& ostr) {
	ostr << _type << std::endl;
	for (std::vector<std::string>::const_iterator line = _description.begin(); line != _description.end(); line++)
		ostr << *line << std::endl;
}