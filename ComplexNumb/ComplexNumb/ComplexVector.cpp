#include<iomanip>
#include"ComplexVector.h"
#include"ComplexNumbFactory.h"
#include"ComplexNumbException.h"

template <class T>
T* giveMemory(int n)
{
	if (n < 0) {
		cerr << "n should be >0";
		exit;
	}
	T* arr = new (nothrow) T[n];
	if (!arr)
	{
		cout << "Can't give memory";
		exit;
	}
	return arr;
}
template <class T>
void freeMemory(T*& arr)
{
	if (arr)
		delete[] arr;
	arr = nullptr;
}



ComplexVector::ComplexVector() {
	n = 1;
	arr = giveMemory<ComplexNumb>(1);
	arr[0] = 0;
}

ComplexVector::ComplexVector(ComplexNumb* a, int d) {
	n = d;
	arr = giveMemory<ComplexNumb>(n);
	
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
	arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = 0;//ComplexNumbFactory::randNumb();
	}
}
ComplexVector::ComplexVector(const ComplexVector& c) {
	n = c.n;
	arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = c.arr[i];
	}

}
ComplexVector::~ComplexVector() {
	freeMemory(arr);
}
ComplexVector& ComplexVector:: operator=(const ComplexVector& c) {
	if (this == &c)
		return *this;
	n = c.n;
	delete[] arr;
	//freeMemory(arr);
	arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = c.arr[i];
	}
	return *this;
}

bool ComplexVector::operator==(const ComplexVector & c) const {
	if (n != c.n)
		return false;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != c.arr[i])
			return false;
	}
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
ComplexNumb* ComplexVector::getVector() {
	return arr;
}
ComplexNumb ComplexVector::getEl(int i) {
	return arr[i];
}
void ComplexVector::setVect(ComplexNumb* a, int nn) {
	freeMemory(arr);
	n = nn;
	arr = giveMemory<ComplexNumb>(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = a[i];
	}
}
void ComplexVector::setRand(int nn) {
	n = nn;
	freeMemory(arr);
	arr = giveMemory<ComplexNumb>(n);
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





























