#pragma once

#include "Consumable.h"

class FoodRation: public Consumable {
public:
	FoodRation(size_t value, size_t weight, size_t amount, double boost);
	double getBoost() const;
	void printStats();
	std::ostream& output(std::ostream& ostr) const;
	std::istream& input(std::istream& istr);
private:
	double _boost;
};