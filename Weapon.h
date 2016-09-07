#pragma once

#include "Wearable.h"

class Weapon: public Wearable {
public:
	Weapon(size_t value, size_t weight, size_t _durability, std::string type, size_t dmg);
	size_t getDmg() const;
	void printStats();
	std::ostream& output(std::ostream& ostr) const;
	std::istream& input(std::istream& istr);
private:
	//how much damage the weapon deals
	size_t _damage;
};