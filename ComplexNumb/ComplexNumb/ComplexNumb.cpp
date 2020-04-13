#include<iostream>
#include"ComplexNumb.h"
#include"Parser.h"
#include"ComplexNumbException.h"

template <class T>
T* ComplexNumb::giveMemory(int n)
{
	if (n < 0) {
		throw ComplexNumbException("n should be >0");

	}
	T* arr = new (nothrow) T[n];
	if (!arr)
	{
		throw ComplexNumbException("Can't give memory");
		exit(1);
	}
	return arr;
}
template <class T>
void ComplexNumb::freeMemory(T*& arr)
{
	if (arr)
		delete[] arr;
	arr = nullptr;
}

ComplexNumb::ComplexNumb() : arr{ giveMemory<double>(COUNT_NUMV) } {
	arr[0] = 0;
	arr[1] = 0;

}
ComplexNumb::ComplexNumb(double a, double b) : arr{ giveMemory<double>(COUNT_NUMV) } {

	arr[0] = a;
	arr[1] = b;

}

ComplexNumb::ComplexNumb(const ComplexNumb& c) : arr{ giveMemory<double>(COUNT_NUMV) } {
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c.arr[i];
	}
}
ComplexNumb::ComplexNumb(double* c) : arr{ giveMemory<double>(COUNT_NUMV) } {
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c[i];
	}
}
int ComplexNumb::getCOUNT() {
	return COUNT_NUMV;
}
double* ComplexNumb::getNumb() {
	return arr;
}
void ComplexNumb::setNumb(double* c) {
	freeMemory(arr);
	arr = giveMemory<double>(COUNT_NUMV);
	for (int i = 0; i < COUNT_NUMV; ++i) {
		arr[i] = c[i];
	}
}
void ComplexNumb::setNumb(double a, double b) {
	arr[0] = a;
	arr[1] = b;
}
ComplexNumb::~ComplexNumb() {
	freeMemory(arr);
}
ComplexNumb ComplexNumb::operator+(const ComplexNumb& a) const {
	ComplexNumb tmp;
	for (int i = 0; i < COUNT_NUMV; ++i) {
		tmp.arr[i] = arr[i] + a.arr[i];
	}
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
	tmp.arr[0] = (arr[0] * a.arr[0]) - (arr[1] * a.arr[1]);
	tmp.arr[1] = (arr[0] * a.arr[1]) + (arr[1] * a.arr[0]);

	return tmp;
}
ComplexNumb ComplexNumb::conjugate(const ComplexNumb a)  {
	a.arr[1] = -a.arr[1];
	return a;
}

ComplexNumb ComplexNumb::operator/(const ComplexNumb& a) const {
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
	freeMemory(arr);
	arr = giveMemory<double>(COUNT_NUMV);
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



































