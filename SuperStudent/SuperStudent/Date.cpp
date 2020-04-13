#include <iostream>
#include <time.h>
#include "Date.h"
#include "ExeptionDate.h"
#include "DateValidator.h"
using namespace std;

Date::Date() {
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	this->day = newtime.tm_mday;
	this->month = static_cast<Month>(newtime.tm_mon + 1); // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	this->year = newtime.tm_year + 1900; // Year is # years since 1900
}

Date::Date(int d, int m, int y) {
	DateValidator dv;
	if (dv.isYearValid(y)) {
		year = y;
	}
	if (dv.isMonthValid(m)) {
		month = static_cast<Month>(m);
	}
	if (dv.isMonthValid(d)) {
		day = d;
	}
}

Date::~Date() {}

void Date::setMonth(int m) {
	//DateValidator validator;
	if (m>0 && m< 13)
		this->month = static_cast<Month>(m);
	else {
		 const int STANDARTMONTH{ 1 };
		cerr << "Bad month";
		this->month =static_cast<Month>( STANDARTMONTH);

	}
}

void Date::setYear(int y) {
	//DateValidator validator;
	if(y>0 && y<2015)
		this->year = y;
	else {
		const int STANDARTYEAR{ 1999 };
		cerr << "Bad year";
		this->year = STANDARTYEAR;

	}
}
void Date::setDay(int d) {
	DateValidator validator;
	if (validator.isYearValid(d))
		this->day = d;
	else {
		const int STANDARTDAY{ 1 };
		cerr << "Bad day";
		this->day = STANDARTDAY;
	}
}
void Date::setDate(int d, int m, int y) {
	DateValidator validator;
	const Date STANDARTDATE(1, 1, 1999);
	if (validator.isDayValid(day, month, y)) {
		this->day = d;
		this->month = static_cast<Month>(m);
		this->year = y;
	}
	else {
		cerr << "Bad Date";
		this->day = STANDARTDATE.day;
		this->month = static_cast<Month>( STANDARTDATE.month);
		this->year = STANDARTDATE.year;
	}
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

char* Date::toCharArray() {
	char* str = new char[100];
	char strForDay[5];//3-для дня, либо 5-для года
	_itoa_s(day, strForDay, 10);
	strcpy_s(str, 3, strForDay);
	strcat_s(str, 4, " ");
	strcat_s(str, 13, monthStr[month - 1]);
	strcat_s(str, 14, " ");
	_itoa_s(year, strForDay, 10);
	strcat_s(str, 18, strForDay);
	return str;
}

std::ostream& operator<<(std::ostream& out,  Date& c)
{
	out << c.day << ' ' << c.month << ' ' << c.year << ' ';
	return out;
}

std::istream& operator>>(std::istream& os, Date& c)
{
	int d{ 0 };
	int m{ 0 };
	int y{ 0 };
	os >> d;
	os >> m;
	os >> y;
	
	DateValidator dv;
	if (dv.isYearValid(y)) {
		c.year = y;
	}
	if (dv.isMonthValid(m)) {
		c.month = static_cast<Month>(m);
	}
	if (dv.isMonthValid(d)) {
		c.day = d;
	}
	//c.setYear(y);
	//c.setMonth(m);
	//c.setDay(d);
	return os;
}
std::string Date::toString() {
	std::string str;
	str = std::to_string(day);
	str = str + " " + monthString[month - 1] + " ";
	str += std::to_string(year);

	return str;
}
