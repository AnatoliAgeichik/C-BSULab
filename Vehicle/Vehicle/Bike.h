#pragma once
#include"Vehicle.h"

class Bike : public Vehicle {
public:
	Bike();
	Bike(double avgSpeed, double costRoad, int countSeats, double carryingCapacity);
	void setCountSeats(int c) override;
	void setCarryingCapacity(double c) override;
	void setSpeed(double c) override;
	
	virtual ~Bike(){}
	friend ostream& operator << (ostream& os, const Bike& c);
	string toString();
};