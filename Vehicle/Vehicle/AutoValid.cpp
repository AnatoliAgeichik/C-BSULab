#include<iostream>
#include "AutoValid.h"

using namespace std;

int AutoValid::isCorrectCountPassanger(int c) {

	if (c > 25) {
		c = 25;
		cout << "No, max count passager 25" << '\n';
		cout << "count passager set 25" << '\n';
	}
	return c;

}

double AutoValid::isCorrectWeight(double c) {
	if (c > 1500)
	{
		c = 1500;
		cout << "No, max weight 1500 kg" << '\n';
		cout << "weight  set 1500" << '\n';

	}
	return c;
}
double AutoValid::isCorrectSpeed(double c) {
	if (c > 140)
	{
		c = 140;
		cout << "No, max speed 140 " << '\n';
		cout << "speed  set 140" << '\n';

	}
	return c;
}