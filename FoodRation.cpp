#include "FoodRation.h"

FoodRation::FoodRation(size_t value, size_t weight, size_t amount, double boost):
	Consumable(value, weight, amount), _boost(boost) {
	_name = "FOOD_RATION";
}

double FoodRation::getBoost() const {
	return _boost;
}

void FoodRation::printStats() {
	Consumable::printStats();
	printf("\nGives:     %.0f%% strength boost\n", 100*_boost);
}

std::ostream & FoodRation::output(std::ostream & ostr) const {
	Consumable::output(ostr);
	ostr << ' ' << _boost;
	return ostr;
}

std::istream& FoodRation::input(std::istream& istr) {
	Consumable::input(istr);
	istr >> _boost;
	return istr;
}