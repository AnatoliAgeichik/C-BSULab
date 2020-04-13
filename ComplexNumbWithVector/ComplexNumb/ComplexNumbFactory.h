#pragma once
#pragma once
#include<iostream>
#include<ctime>
#include"ComplexNumb.h"

class ComplexNumbFactory
{
public:
	static void randNumb(ComplexNumb &t, int begin = -5000, int end = 5000);
};
