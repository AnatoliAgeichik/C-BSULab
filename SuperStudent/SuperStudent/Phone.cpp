#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Phone.h"
#include"PhoneValidator.h"
#include<cstring>
using namespace std;

template <class T>
T* giveMemory(int n)
{
	T *arr = new (nothrow) T[n];
	if (!arr)
	{
		cout << "Can't give memory";
		exit;
	}
	return arr;
}

Phone::Phone() : world{ giveMemory<char>(5) }, reg{ 25 }, numb{1234567} {
	strcpy(world, "+375");
}
Phone::Phone(char* w, int r, int n)  {
	this->setWorld(w);
	this->setReg(r);
	this->setNumb(n);
}

Phone::Phone(const Phone& c) : world{ giveMemory<char>(strlen(c.world) + 1) }, reg{ c.reg }, numb{c.numb} {
	strcpy(world, c.world);
}
 Phone& Phone:: operator = (const Phone& c) {
	 delete[] world;
	 world = giveMemory<char>(strlen(c.world) + 1);
	 strcpy(world, c.world);
	 reg = c.reg;
	 numb = c.numb;
	 return *this;
 }
 void Phone:: setWorld(char* w) {
	 PhoneValidator pv;
	 //cout << pv.isWorldCode(w) << '\n';
	 if (pv.isWorldCode(w)) {
		 delete[] world;
		 world = giveMemory<char>(strlen(w) + 1);
		 strcpy(world, w);
	 }
	 else {
		 cout << "Bad data";
		 char STANDARTCODE [5] = "+375";
		 delete[] world;
		 world = giveMemory<char>(strlen(w) + 1);
		 strcpy(world, STANDARTCODE);
	 }  
}
 void Phone::setReg(int r) {
	 PhoneValidator pv;
	 //cout << pv.isRegionCode(r) << '\n';
	 if (pv.isRegionCode(r)) {
		 reg = r;
	 }
	 else {
		 cerr << "Bad data";
		 const int STANDARTREGION = 29;
		 reg = STANDARTREGION;
	 }
}
 void Phone::setNumb(int n) {
	 PhoneValidator pv;
	// cout << pv.isNumberCode(n) << '\n';
	 if (pv.isNumberCode(n))
		 numb = n;
	 else {
		 cerr << "Bad numb";
		 const int STANDARTNUMBER = 1234567;
		 numb = STANDARTNUMBER;
	 }
}
char* Phone:: getWorld() {
	return world;
}
int Phone::getReg() {
	return reg;
}
int Phone::getNumb() {
	return numb;
}
ostream & operator<<(std::ostream& os, Phone& c) {
	os << c.world << ' ' << c.reg << ' ' << c.numb;
	return os;
}
istream & operator>>(std::istream& os, Phone& c) {
	cout << "Please, enter your world code";
	os.clear();
	os >> c.world;
	cout << "Please, enter your region code";
	c.setWorld(c.world);
	os >> c.reg;
	c.setReg(c.reg);
	cout << "Please, enter your numb code";
	os >> c.numb;
	c.setNumb(c.numb);
	return os;
}
 
