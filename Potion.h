#pragma once

#include "Consumable.h"

class Potion: public Consumable{
public:
	Potion(size_t value, size_t weight, size_t amount, size_t hp);
	//getters
	size_t getRestores() const;
	void printStats();
	std::ostream& output(std::ostream& ostr) const;
	std::istream& input(std::istream& istr);
private:
	size_t _restores;
};