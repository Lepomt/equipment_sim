#pragma once

#include "Item.h"

class Consumable: public Item {
public:
	Consumable(size_t value, size_t weight, size_t amount):
		Item(value, weight),  _amount(amount) {}
	size_t getAmount() const { return _amount; }
	virtual void printStats() {
		Item::printStats();
		printf("\nStack of:  %d", _amount);
	}
	virtual std::ostream& output(std::ostream& ostr) const {
		Item::output(ostr);
		ostr << ' ' << _amount;
		return ostr;
	}
	virtual std::istream& input(std::istream& istr) {
		Item::input(istr);
		istr >> _amount;
		return istr;
	}
protected:
	size_t _amount;
};