#pragma once
#pragma once
#include<iostream>

using namespace std;
class ComplexNumb {
private:
	static const int COUNT_NUMV = 2;
	double* arr;
	template<class T>
	void freeMemory(T*& arr);

	template<class T>
	T* giveMemory(int n);
public:
	ComplexNumb();
	ComplexNumb(double a, double b = 0);
	ComplexNumb(double *nn);
	ComplexNumb(const ComplexNumb&);
	static ComplexNumb conjugate(const ComplexNumb);

	ComplexNumb operator+(const ComplexNumb&) const;
	ComplexNumb operator-(const ComplexNumb&) const;
	ComplexNumb operator*(const ComplexNumb&) const;
	ComplexNumb operator/(const ComplexNumb&) const;

	ComplexNumb& operator=(const ComplexNumb&);
	ComplexNumb& operator=(double a);

	bool operator == (const ComplexNumb& a) const;
	bool operator != (const ComplexNumb& a) const;
	//friend bool operator== (const ComplexNumb& a, const ComplexNumb& b)  ;


	int getCOUNT();
	double* getNumb();
	double getReal();
	double getIm();
	void setNumb(double* nn);
	void setNumb(double a, double b);
	void setReal(double a);
	void setImaginary(double a);
	~ComplexNumb();
	friend  ostream&  operator << (ostream& os, const ComplexNumb&);
	friend istream& operator >> (istream&, ComplexNumb&);
};