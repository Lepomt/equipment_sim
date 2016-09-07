#pragma once

#include "Wearable.h"

class Armour: public Wearable {
public:
	Armour(size_t value, size_t weight, size_t _durability, std::string type, size_t def);
	size_t getDef() const;
	void printStats();
	std::ostream& output(std::ostream& ostr) const;
	std::istream& input(std::istream& istr);
private:
	size_t _defense;
};