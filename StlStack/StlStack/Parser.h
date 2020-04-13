#pragma once
#pragma once
#pragma once
#include<iostream>

using namespace std;

class Parser

{

public:

	static int ParseInt(istream& os);
	static int ParseInt(const char* r);
	static double ParseDouble(istream& os);
	static double ParseDouble(const char* s);

};