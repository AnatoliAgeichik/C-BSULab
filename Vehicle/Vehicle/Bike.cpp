#include"Bike.h"
#include"VehicleException.h"
#include"BikeValid.h"

Bike::Bike() {

}
Bike::Bike(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity)
	:Vehicle(_avgSpeed, _costRoad, _countSeats, _carryingCapacity)
{
	_countSeats = BikeValid::isCorrectCountPassanger(_countSeats);
	_carryingCapacity = BikeValid::isCorrectWeight(_carryingCapacity);
	_avgSpeed = BikeValid::isCorrectSpeed(_avgSpeed);
	this->setCountSeats(_countSeats);
	this->setCarryingCapacity(_carryingCapacity);
	this->setSpeed(_avgSpeed);
}
void Bike::setCountSeats(int c) {
	c = BikeValid::isCorrectCountPassanger(c);
	Vehicle::setCountSeats(c);
}
void Bike::setCarryingCapacity(double c) {
	c = BikeValid::isCorrectWeight(c);
	Vehicle::setCarryingCapacity(c);

}
void Bike::setSpeed(double c) {
	c = BikeValid::isCorrectSpeed(c);
	Vehicle::setSpeed(c);
}
ostream& operator << (ostream& os, const Bike& c) {
	os <<(Vehicle&) c;
	return os;
}
string Bike::toString() {
	string rez = Vehicle::toString();
	return rez;
}