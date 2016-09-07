#include "Armour.h"

Armour::Armour(size_t value, size_t weight, size_t durability, std::string type, size_t def):
	Wearable(value, weight, durability, type), _defense(def) {
	_name = "ARMOUR";
}

size_t Armour::getDef() const {
	return _defense;
}

void Armour::printStats() {
	Wearable::printStats();
	printf("\nDefense:   blocks %d damage\n", _defense);
}

std::ostream & Armour::output(std::ostream & ostr) const{
	Wearable::output(ostr);
	ostr << ' ' << _defense;
	return ostr;
}

std::istream & Armour::input(std::istream & istr) {
	Wearable::input(istr);
	istr >> _defense;
	return istr;
}
