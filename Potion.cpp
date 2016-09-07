#include <fstream>
#include <conio.h>

#include "Potion.h"

using namespace std;

Potion::Potion(size_t value, size_t weight, size_t amount, size_t hp):
	Consumable(value, weight, amount), _restores(hp) {
	_name = "POTION";
}

void Potion::printStats() {
	Consumable::printStats();
	printf("\nRestores:  %d health points\n", _restores);
}

size_t Potion::getRestores() const {
	return _restores;
}

std::ostream & Potion::output(std::ostream & ostr) const {
	Consumable::output(ostr);
	ostr << ' ' << _restores;
	return ostr;
}

std::istream& Potion::input(std::istream& istr) {
	Consumable::input(istr);
	istr >> _restores;
	return istr;
}