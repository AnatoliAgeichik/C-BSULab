#pragma once

#include<iostream>
using namespace std;
class Phone 
{
private:
	char* world;
	int reg;
	int numb;
public:
	Phone();
	Phone(char* w,int r, int n);
	~Phone() {
		delete[] world;
	}
	Phone(const Phone& c);
	Phone& operator = ( const Phone& c); 
	void setWorld(char* w);
	void setReg(int r);
	void setNumb(int n);
	char* getWorld();
	int getReg();
	int getNumb();
	friend std::ostream & operator<<(std::ostream& os, Phone& c);
	friend std::istream & operator>>(std::istream& os, Phone& c);
};