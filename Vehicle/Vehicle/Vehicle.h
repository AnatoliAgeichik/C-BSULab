#pragma once
#include<iostream>

using namespace std;

class Vehicle {
private:
	double avgSpeed;
	double costRoad;
	int countSeats;
	double carryingCapacity;
public:
	Vehicle();
	Vehicle(double avgSpeed, double costRoad, int countSeats, double carryingCapacity);
	Vehicle(const Vehicle& a);
	virtual void setSpeed(double speed);
	void setPrice(double price);
	virtual void setCountSeats(int c);
	virtual void setCarryingCapacity(double c);
	double getSpeed();
	double getPrice();
	int getCountSeats();
	double getCarryingCapacity();
	virtual ~Vehicle(){}
	Vehicle& operator =(const Vehicle& c);
	friend ostream& operator << (ostream& os, const Vehicle& c);
	double timeTrip(double distance);
	double priceTranspantationPassanger(double distance, int countPassanger);
	double priceShippin(double time, double weight);
	virtual string toString();
};