#include <string>
#include <iostream>
#include"ComplexNumbException.h"
using namespace std;

ComplexNumbException::ComplexNumbException(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* ComplexNumbException::what() {
	return str;
}
