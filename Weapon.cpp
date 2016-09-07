#include "Weapon.h"

Weapon::Weapon(size_t value, size_t weight, size_t durability, std::string type, size_t dmg):
	Wearable(value, weight, durability, type), _damage(dmg) {
	_name = "WEAPON";
}

size_t Weapon::getDmg() const {
	return _damage;
}

void Weapon::printStats() {
	Wearable::printStats();
	printf("\nDamage:    %d health points\n", _damage);
}

std::ostream & Weapon::output(std::ostream& ostr) const {
	Wearable::output(ostr);
	ostr << ' ' << _damage;
	return ostr;
}

std::istream& Weapon::input(std::istream& istr) {
	Wearable::input(istr);
	istr >> _damage;
	return istr;
}