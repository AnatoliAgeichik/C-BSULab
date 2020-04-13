#pragma once
#include"Vehicle.h"
#include<cstring>

class Wagon: public Vehicle
{
private:
	string type;
public:
	Wagon();
	Wagon(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity, string t);
	string getType();
	void setType(string t);
	void setCountSeats(int c) override;
	void setCarryingCapacity(double c) override;
	void setSpeed(double c) override;
	friend ostream& operator << (ostream& os, const Wagon& c);
	string toString();
};

