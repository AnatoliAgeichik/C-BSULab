#pragma once
#include<iostream>
#include"Phone.h"
class PhoneValidator
{
public:
	bool isWorldCode(char* w);
	bool isRegionCode(int r);
	bool isNumberCode(int n);
	void setTrueWorldCode(Phone& c, char* n);
	void setTrueRegionCode(Phone& c, int n);
	void setTrueNumberCode(Phone& c, int n);
	void setTruePhone(Phone& c, char* w, int r, int n);

};
