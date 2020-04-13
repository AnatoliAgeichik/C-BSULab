#pragma once
#include"Vehicle.h"
#include"Auto.h"
#include"Bike.h"
#include"Wagon.h"

class ConsoleHelp
{
public:
	void menu();
	void randBike(Vehicle** arr, int numb, Bike& c);
	void randAuto(Vehicle** arr, int numb, Auto& c);
	void randWagon(Vehicle** arr, int numb, Wagon& c);
	void printArr(Vehicle** arr, int n);
};

