#include <string>
#include <iostream>
#include"StackException.h"
using namespace std;

StackException::StackException(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* StackException::what() {
	return str;
}
