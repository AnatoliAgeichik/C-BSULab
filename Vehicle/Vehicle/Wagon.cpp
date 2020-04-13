#include "Wagon.h"
#include"WagonValid.h"

Wagon::Wagon() :Vehicle() {
	type = "closed";
}
Wagon::Wagon(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity, string t) :
	Vehicle(_avgSpeed, _costRoad, _countSeats, _carryingCapacity) {
	type = t;

	_countSeats = WagonValid::isCorrectCountPassanger(_countSeats);
	_carryingCapacity = WagonValid::isCorrectWeight(_carryingCapacity);
	_avgSpeed = WagonValid::isCorrectSpeed(_avgSpeed);
	this->setCountSeats(_countSeats);
	this->setCarryingCapacity(_carryingCapacity);
	this->setSpeed(_avgSpeed);
}

void Wagon::setType(string t) {
	type = t;
}
string Wagon::getType() {
	return type;
}

void Wagon::setCountSeats(int c) {
	c = WagonValid::isCorrectCountPassanger(c);
	Vehicle::setCountSeats(c);
}
void Wagon::setCarryingCapacity(double c) {
	c = WagonValid::isCorrectWeight(c);
	Vehicle::setCarryingCapacity(c);

}
void Wagon::setSpeed(double c) {
	c = WagonValid::isCorrectSpeed(c);
	Vehicle::setSpeed(c);
}
ostream& operator << (ostream& os, const Wagon& c) {
	os << (Vehicle&)c;
	os << c.type;
	return os;
}
string Wagon::toString() {
	string rez = Vehicle::toString();
	rez += '\n' + type;
	return rez;
}