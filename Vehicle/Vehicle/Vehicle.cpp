#include"Vehicle.h"
#include"VehicleException.h"
#include<iostream>
#include<cstring>
#include <sstream>//для типа ostringstream в bool_cast

using namespace std;

Vehicle::Vehicle() : avgSpeed{ 0 }, costRoad{ 0 }, countSeats{ 0 }, carryingCapacity{ 0 } {}

Vehicle::Vehicle(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity):
	avgSpeed{_avgSpeed}, costRoad{_costRoad}, countSeats{_countSeats}, carryingCapacity{_carryingCapacity}{}

Vehicle::Vehicle(const Vehicle& a): avgSpeed{a.avgSpeed }, costRoad{ a.costRoad }, countSeats{ a.countSeats },
carryingCapacity{ a.carryingCapacity}{}

double Vehicle::getSpeed() { return avgSpeed; }

double Vehicle::getPrice() { return costRoad; }

int Vehicle::getCountSeats() { return countSeats; }

double Vehicle::getCarryingCapacity() { return carryingCapacity; }

void Vehicle::setSpeed(double speed) {
	if (speed < 0)
		throw VehicleException("speed should be >0");
	avgSpeed = speed;
}
void Vehicle::setPrice(double price) {
	if (price < 0)
		throw VehicleException("price should be >0");
	costRoad = price;
}
void Vehicle::setCountSeats(int c) {
	if (c < 0)
		throw VehicleException("CountSeats should be >0");
	countSeats = c;
}

void Vehicle::setCarryingCapacity(double c) {
	if (c < 0)
		throw VehicleException("CountSeats should be >0");
	carryingCapacity = c;
}

Vehicle& Vehicle::operator=(const Vehicle& c) {
	avgSpeed = c.avgSpeed;
	costRoad = c.costRoad;
	countSeats = c.countSeats;
	carryingCapacity = c.carryingCapacity;
	return *this;
}
ostream& operator << (ostream& os, const Vehicle& c) {
	os << c.avgSpeed << '\n';
	os << c.costRoad << '\n';
	os << c.countSeats << '\n';
	os << c.carryingCapacity << '\n';
	return os;
}
double Vehicle::timeTrip(double distance) {
	return (distance / avgSpeed);
}
double Vehicle::priceTranspantationPassanger(double distance, int countPassanger) {
	if (countPassanger <= 0)
		throw VehicleException("count passanger should be >0");
	int countTrip = countPassanger/ countSeats;
	if ((countPassanger % countSeats))
		countTrip++;
	
	
	double time = timeTrip(distance);
	return( time * costRoad * countTrip);

}
double Vehicle::priceShippin(double distance, double weight) {
	if (weight <= 0)
		throw VehicleException("weight should be >0");
	int countTrip = weight / carryingCapacity;
	if (weight / carryingCapacity)
		countTrip++;
	double time = timeTrip(distance);
	return(time * costRoad * countTrip);
}
string Vehicle::toString() {
	string rez;
	rez += to_string(avgSpeed) + "\n" + to_string(costRoad) + "\n" + to_string(countSeats) + "\n" + to_string(carryingCapacity);
	return rez;
}




























