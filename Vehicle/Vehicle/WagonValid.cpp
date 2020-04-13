#include<iostream>
#include "WagonValid.h"
using namespace std;

int WagonValid::isCorrectCountPassanger(int c) {

	if (c > 15) {
		c = 15;
		cout << "No, max count passager 15" << '\n';
		cout << "count passager set 15" << '\n';
	}
	return c;

}

double WagonValid::isCorrectWeight(double c) {
	if (c > 2000)
	{
		c = 2000;
		cout << "No, max weight 2000 kg" << '\n';
		cout << "weight  set 2000" << '\n';

	}
	return c;
}
double WagonValid::isCorrectSpeed(double c) {
	if (c > 90)
	{
		c = 90;
		cout << "No, max speed 90" << '\n';
		cout << "speed  set 90" << '\n';

	}
	return c;
}