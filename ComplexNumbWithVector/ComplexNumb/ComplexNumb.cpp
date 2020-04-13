#include<iostream>
#include"ComplexNumb.h"
#include"Parser.h"
#include"ComplexNumbException.h"

ComplexNumb::ComplexNumb()  {
	arr.resize(2);

}
ComplexNumb::ComplexNumb(double a, double b) {
	arr.resize(2);
	arr[0] = a;
	arr[1] = b;

}

ComplexNumb::ComplexNumb(const ComplexNumb& c) {
	arr.resize(2);
	arr[0] = c.arr[0];
	arr[1] = c.arr[1];
}
ComplexNumb::ComplexNumb(vector<double> nn) {
	if (nn.size() < 2) {
	//	cout << "loh";
		throw ComplexNumbException("Error vector dont have 2 el");
		
	}
	try
	{
		arr[0] = nn[0];
		arr[1] = nn[1];
	}
	catch (const std::exception&)
	{
		throw ComplexNumbException("Error ");
	}
}
ComplexNumb::ComplexNumb(double* c) {
	arr.resize(2);
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c[i];
	}
}
int ComplexNumb::getCOUNT() {
	return COUNT_NUMV;
}
vector<double> ComplexNumb::getNumb() {
	return arr;
}
void ComplexNumb::setNumb(double* c) {
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c[i];
	}
}
void ComplexNumb::setNumb(double a, double b) {
	arr[0] = a;
	arr[1] = b;
}
ComplexNumb::~ComplexNumb() {
	//freeMemory(arr);
}
ComplexNumb ComplexNumb::operator+(const ComplexNumb& a) const  {
	ComplexNumb tmp;
	cout << tmp.arr.size() << arr.size() << a.arr.size();
	//tmp.arr.resize(2);
	tmp.arr[0] = arr[0] + a.arr[0];
	tmp.arr[1] = arr[1] + a.arr[1];
	return tmp;
}
ComplexNumb ComplexNumb::operator-(const ComplexNumb& a) const {
	ComplexNumb tmp;
	for (int i = 0; i < COUNT_NUMV; ++i) {
		tmp.arr[i] = arr[i] - a.arr[i];
	}
	return tmp;
}
ComplexNumb ComplexNumb::operator*(const ComplexNumb& a) const {
	ComplexNumb tmp;
	//tmp.arr.resize(2);
	tmp.arr[0] = (arr[0] * a.arr[0]) - (arr[1] * a.arr[1]);
	tmp.arr[1] = (arr[0] * a.arr[1]) + (arr[1] * a.arr[0]);

	return tmp;
}
ComplexNumb ComplexNumb::conjugate( ComplexNumb a)  {
	a.arr[1] = -a.arr[1];
	return a;
}

ComplexNumb ComplexNumb::operator/( ComplexNumb& a) const {
	ComplexNumb tmp(0, 0);
	if (a == tmp)
		throw ComplexNumbException("cannot be divided by zero");
	ComplexNumb numerator;
	
	ComplexNumb ac = conjugate(a);
	numerator = *this * ac;
	double den = a.arr[0] * a.arr[0] + a.arr[1] * a.arr[1];
	ComplexNumb rez;
	rez.arr[0] = numerator.arr[0] / den;
	rez.arr[1] = numerator.arr[1] / den;
	return rez;
	
	
}
void ComplexNumb::setReal(double a) {
	arr[0] = a;
}
void ComplexNumb::setImaginary(double a) {
	arr[1] = a;
}
ComplexNumb& ComplexNumb::operator=(const ComplexNumb& c) {
	if (this == &c)
		return *this;
	//freeMemory(arr);
	//arr = giveMemory<double>(COUNT_NUMV);
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c.arr[i];
	}
	return *this;
}

bool ComplexNumb::operator == (const ComplexNumb& a) const {
	if (arr[0] != a.arr[0])
		return false;
	if (arr[1] != a.arr[1])
		return false;
	return true;

}

bool ComplexNumb::operator != (const ComplexNumb& a) const {
	if (arr[0] == a.arr[0])
		return false;
	if (arr[1] == a.arr[1])
		return false;
	return true;

}
/*
bool operator == (const ComplexNumb& a, const ComplexNumb& b) {
	if (a.arr[0] != b.arr[0])
		return false;
	if (a.arr[1] != b.arr[1])
		return false;
	return true;

}*/

double ComplexNumb::getReal() {
	return arr[0];
}


double ComplexNumb::getIm() {
	return arr[1];
}



ComplexNumb& ComplexNumb :: operator=(double a) {
	arr[0] = a;
	arr[1] = 0;
	return *this;
}
ostream& operator << (ostream& os, const ComplexNumb& c) {
	os << c.arr[0] << " + " << c.arr[1] << 'i' << ' ';
	return os;
}
istream& operator >> (istream& os, ComplexNumb& c) {
	c.arr[0] = Parser::ParseInt(os);
	c.arr[1] = Parser::ParseInt(os);
	return os;
}



































