#ifndef DATE_H
#define DATE_H
#include<iostream>
#include <string>
#include "Month.h"
class Date
{
	int day = 11;
	Month month = SEP;
	int year = 2000;
public:
	Date();//конструктор по умолчанию
	Date(int d, int m, int y);
	~Date();

	void setMonth(int m);
	void setYear(int y);
	void setDay(int d);
	void setDate(int d, int m, int y);

	int getDay();
	int getMonth();
	int getYear();
	char* toCharArray();
	friend std::ostream& operator<<(std::ostream& out,  Date& c);
	friend std::istream& operator>>(std::istream& os,  Date& c);
	//friend ostream& operator << (ostream & os, const Date& c);
	// friend istream& operator >> (istream & os, Date &  c);
	
	std::string toString();
};
#endif
