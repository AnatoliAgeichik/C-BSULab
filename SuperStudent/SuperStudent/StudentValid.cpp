#include<iostream>
#include"StudentValidator.h"

int StudentValidator::validKurs(int n) {
	if (n < 1) {
		return 1;
	}
	else if (n>6)
	{
		return 6;
	}
	return n;
}