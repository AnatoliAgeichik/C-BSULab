#include<iostream>
#include "ConsoleHelp.h"
#include"Vehicle.h"
#include"Auto.h"
#include"Bike.h"
#include"Wagon.h"
using namespace std;

void ConsoleHelp::randAuto(Vehicle** arr, int numb, Auto& c) {
	
	c.setSpeed(rand() % 110);
	c.setPrice(rand() % 500);
	c.setCountSeats(rand() % 20);
	c.setCarryingCapacity(rand() % 600);
	arr[numb] = &c;
}
void ConsoleHelp::randBike(Vehicle** arr, int numb, Bike& c) {
	
	c.setSpeed(rand() % 110);
	c.setPrice(rand() % 500);
	c.setCountSeats(rand() % 20);
	c.setCarryingCapacity(rand() % 600);
	arr[numb] = &c;
}
void ConsoleHelp::randWagon(Vehicle** arr, int numb, Wagon& c) {

	
	c.setSpeed(rand() % 110);
	c.setPrice(rand() % 500);
	c.setCountSeats(rand() % 20);
	c.setCarryingCapacity(rand() % 600);
	arr[numb] = &c;
}
void ConsoleHelp::printArr(Vehicle** arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i]->toString()<<'\n'<<'\n';
	
}
void ConsoleHelp::menu() {
	int countEl{ 0 };
	cout << "please enter coutn el";
	cin >> countEl;
	int tmp{ 0 };
	Bike a;
	Auto b;
	Wagon c;
	Vehicle** arr = new Vehicle * [countEl];
	for (int i = 0; i < countEl; i++) {
		tmp = rand() % 3;
		switch (tmp)
		{
		case 0:
			randAuto(arr, i, b);
			break;
		case 1:
			randBike(arr, i,a);
			break;
		case 2:
			randWagon(arr, i,c);
			break;
		default:
			break;
		}
		
	}

	printArr(arr, countEl);
	int k{ -1 };
	int numbK{ 0 };
	double dist{ 0 };
	int countPass{ 0 };
	double weight{ 0 };
	while (k) {
		if (!k)
			break;
		
		cout << '\n'<<"1-time road, 2-cost road passager, 3-cost shippin 0-for exit"<<'\n' << '\n';
		cin >> k;
		bool flag{ 1 };
		while (flag) {
			cout << "enrer numb arr" << '\n';

			cin >> numbK;
			if (numbK < countEl)
				flag = 0;
			else 
				cout << "numb arr should be < count element. Try again" << '\n';

		}
		
		switch (k)
		{
		case 1:
			cout << "please enter dist"<<'\n';
			cin >> dist;
			cout << arr[numbK]->timeTrip(dist);
			
			break;
		case 2:
			cout << "please enter dist" << '\n';
			cin >> dist;
			cout << "please enter count passanger" << '\n';
			cin >>countPass;

			cout<<arr[numbK]->priceTranspantationPassanger(dist, countPass);
			break;
		case 3:
			cout << "please enter dist" << '\n';
			cin >> dist;
			cout << "please enter weight" << '\n';
			cin >> weight;
			cout << arr[numbK]->priceShippin(dist, weight);
			break;
		default:
			break;
		}

	}




}