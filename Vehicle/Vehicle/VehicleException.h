#pragma once
#include<stdexcept>
using namespace std;
class VehicleException : exception
{
public:
	VehicleException (const char* str) :exception(str) {};

};
