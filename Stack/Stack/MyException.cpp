#include <string>
#include <iostream>
#include"MyException.h"
using namespace std;

MyException::MyException(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* MyException::what() {
	return str;
}
