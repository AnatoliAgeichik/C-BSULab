#include<iomanip>
#include"ComplexVector.h"
#include"ComplexNumbFactory.h"
#include"ComplexNumbException.h"





ComplexVector::ComplexVector() {
	n = 1;
	arr.resize(n);
	//arr = giveMemory<ComplexNumb>(1);
	//arr[0] = 0;
}

ComplexVector::ComplexVector(vector<ComplexNumb> a, int d) {
	n = d;
	//arr = giveMemory<ComplexNumb>(n);
	arr.resize(n);
	try
	{
		arr = a;


	}
	catch (const std::exception&)
	{
		throw ComplexNumbException("Error");
	}
}
ComplexVector::ComplexVector(ComplexNumb* a, int d) {
	n = d;
	//arr = giveMemory<ComplexNumb>(n);
	arr.resize(n);
	try
	{
		for (int i = 0; i < n; ++i) {
			arr[i] = a[i];
		}


	}
	catch (const std::exception&)
	{
		throw ComplexNumbException("Error");
	}
}
ComplexVector::ComplexVector(int nn) {
	n = nn;
	arr.resize(n);
	//arr = giveMemory<ComplexNumb>(n);
	
}
ComplexVector::ComplexVector(const ComplexVector& c) {
	n = c.n;
	//arr = giveMemory<ComplexNumb>(n);
	arr.resize(n);
	arr = c.arr;

}
ComplexVector::~ComplexVector() {
	
}
ComplexVector& ComplexVector:: operator=(const ComplexVector& c) {
	if (this == &c)
		return *this;
	n = c.n;
	arr.resize(n);
	arr = c.arr;
	return *this;
}

bool ComplexVector::operator==(const ComplexVector & c) const {
	if (n != c.n)
		return false;
	if (arr != c.arr) 
		return false;
	return true;
}

ComplexVector ComplexVector::operator+(const ComplexVector& c) const {
	if (n != c.n) {
		cerr << "vectors of different dimensions";
		ComplexVector{ *this };
	}
	ComplexVector tmp(n);
	for (int i = 0; i < n; ++i) {
		tmp.arr[i] = arr[i] + c.arr[i];
	}
	return tmp;

}
ComplexVector ComplexVector::operator-(const ComplexVector& c) const {
	if (n != c.n) {
		cerr << "vectors of different dimensions";
		return ComplexVector{ *this };
	}
	ComplexVector tmp(n);
	for (int i = 0; i < n; ++i) {
		tmp.arr[i] = arr[i] - c.arr[i];
	}
	return tmp;
}
ComplexVector ComplexVector::operator*(const ComplexVector& c) const {
	if (n != c.n) {
		cerr << "vectors of different dimensions";
		return ComplexVector{ *this };
	}
	ComplexVector tmp(n);
	for (int i = 0; i < n; ++i) {
		tmp.arr[i] = arr[i] * c.arr[i];
	}
	return tmp;
}
ostream& operator << (ostream& os, const ComplexVector& c) {
	for (int i = 0; i < c.n; ++i) {
		os << c.arr[i];
	}
	os << '\n';
	return os;
}
istream& operator >> (istream& os, ComplexVector& c) {
	for (int i = 0; i < c.n; ++i) {
		os >> c.arr[i];
	}
	return os;

}
int ComplexVector::getDim() {
	return n;
}
vector<ComplexNumb> ComplexVector::getVector() {
	return arr;
}
ComplexNumb ComplexVector::getEl(int i) {
	return arr[i];
}
void ComplexVector::setVect(ComplexNumb* a, int nn) {
	//freeMemory(arr);
	n = nn;
	arr.resize(n);
	//arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = a[i];
	}
}
void ComplexVector::setVect(vector<ComplexNumb> a, int nn) {
	//freeMemory(arr);
	n = nn;
	arr.resize(n);
	//arr = giveMemory<ComplexNumb>(n);
	arr = a;
}
void ComplexVector::setRand(int nn) {
	n = nn;
	//freeMemory(arr);
	//arr = giveMemory<ComplexNumb>(n);
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		ComplexNumbFactory::randNumb(arr[i]);
	}
}
void ComplexVector::setRand() {

	//freeMemory(arr);
	//arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		//arr[i] = ComplexNumbFactory::randNumb(*this,5000,0);
		ComplexNumbFactory::randNumb(arr[i], 0, 500);
	}
}





























