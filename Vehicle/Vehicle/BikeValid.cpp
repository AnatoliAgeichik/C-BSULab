#include<iostream>
#include "BikeValid.h"
using namespace std;

int BikeValid::isCorrectCountPassanger(int c) {
	
	if (c > 2) {
		c = 2;
		cout << "No, max count passager 2" << '\n';
		cout << "count passager set 2" << '\n';
	}
	return c;

}

double BikeValid::isCorrectWeight(double c) {
	if (c > 45)
	{
		c = 45;
		cout << "No, max weight 45 kg" << '\n';
		cout << "weight  set 45" << '\n';

	}
	return c;
}
double BikeValid::isCorrectSpeed(double c) {
	if (c > 60)
	{
		c = 60;
		cout << "No, max speed 75" << '\n';
		cout << "speed  set 75" << '\n';

	}
	return c;
}