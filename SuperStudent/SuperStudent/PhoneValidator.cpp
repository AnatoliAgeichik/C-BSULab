#include<iostream>
#include"PhoneValidator.h"
#include"Phone.h"
bool PhoneValidator::isWorldCode(char* w) {
	if (w[0] != '+'){
		return false;
		}
	const int countDigitWorldCode{ 4 };
	if (sizeof(w) > countDigitWorldCode)
		return false;
	return true;
}
bool PhoneValidator::isRegionCode(int n) {
	const int DigitRegion{ 1000 };
	if (n >= DigitRegion)
		return false;
	return true;
}
bool PhoneValidator::isNumberCode(int n) {
	const int DigitNumb{ 10000000 };
	if (n >= DigitNumb)
		return false;
	return true;
}