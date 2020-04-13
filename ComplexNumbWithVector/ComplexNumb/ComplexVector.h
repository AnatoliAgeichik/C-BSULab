#pragma once
#pragma once
#include<iostream>
#include"ComplexNumb.h"
#include<vector>

class ComplexVector {
private:
	int n;
	vector<ComplexNumb> arr;
public:
	ComplexVector();
	ComplexVector(int n);
	ComplexVector(vector<ComplexNumb> arr, int n);
	ComplexVector( ComplexNumb* a, int n);
	ComplexVector(const ComplexVector& c);
	~ComplexVector();
	ComplexVector& operator=(const ComplexVector& c);
	ComplexVector operator+(const ComplexVector& c) const;
	ComplexVector operator-(const ComplexVector& c) const;
	ComplexVector operator*(const ComplexVector& c) const;
	bool  operator ==(const ComplexVector& c) const;
	int getDim();
	ComplexNumb getEl(int i);
	vector<ComplexNumb> getVector();
	void setVect(vector<ComplexNumb> arr, int n);
	void setVect(ComplexNumb* arr, int n);
	void setRand(int n);
	void setRand();
	friend  ostream& operator << (ostream& os, const ComplexVector&);
	friend istream& operator >> (istream&, ComplexVector&);
};
