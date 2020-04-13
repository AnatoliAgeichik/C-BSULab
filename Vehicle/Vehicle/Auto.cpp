#include "Auto.h"
#include"AutoValid.h"

Auto::Auto():Vehicle() {
	number = "nulll";

}
Auto::Auto(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity, string numb) :
	Vehicle(_avgSpeed, _costRoad, _countSeats, _carryingCapacity) {
	number = numb;

	_countSeats = AutoValid::isCorrectCountPassanger(_countSeats);
	_carryingCapacity = AutoValid::isCorrectWeight(_carryingCapacity);
	_avgSpeed = AutoValid::isCorrectSpeed(_avgSpeed);
	this->setCountSeats(_countSeats);
	this->setCarryingCapacity(_carryingCapacity);
	this->setSpeed(_avgSpeed);
}

void Auto::setNumber(string numb) {
	number = numb;
}
string Auto::getNumber() {
	return number;
}

void Auto::setCountSeats(int c) {
	c = AutoValid::isCorrectCountPassanger(c);
	Vehicle::setCountSeats(c);
}
void Auto::setCarryingCapacity(double c) {
	c = AutoValid::isCorrectWeight(c);
	Vehicle::setCarryingCapacity(c);

}
void Auto::setSpeed(double c) {
	c = AutoValid::isCorrectSpeed(c);
	Vehicle::setSpeed(c);
}
ostream& operator << (ostream& os, const Auto& c) {
	os << (Vehicle&)c;
	os << c.number;
	return os;
}
string Auto::toString() {
	string rez = Vehicle::toString();
	rez += '\n'+number;
	return rez;
}