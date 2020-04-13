#pragma once
#include"Vehicle.h"
#include<cstring>

class Auto : public Vehicle
{
	string number;
public:
	Auto();
	Auto(double _avgSpeed, double _costRoad, int _countSeats, double _carryingCapacity, string numb);
	void setNumber(string numb);
	string getNumber();
	void setCountSeats(int c) override;
	void setCarryingCapacity(double c) override;
	void setSpeed(double c) override;
	friend ostream& operator << (ostream& os, const Auto& c);
	string toString();


};

