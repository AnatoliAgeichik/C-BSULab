#include <time.h>
#include "DateValidator.h"


#define NUM_GROUP 15
#define MAX_BALL 10
#define COURSE 5
#define MAX_NUMBER 9999999



/*
bool DateValidator::isYearValid(int year) {
	//struct tm newtime;
	//time_t now = time(0);
	//localtime_s(&newtime, &now);
	//int currentDay = newtime.tm_mday;
	//int currentMonth = newtime.tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	//int currentYear = newtime.tm_year + 1900; // Year is # years since 1900
	if ((year >= 0)&& (year <= 2015))
		return true;
	else return false;
}
*/
bool DateValidator::isYearValid(int y) {
	if (y > 0 && y < 2015)
		return true;
	else
		return false;
}
bool DateValidator::isMonthValid(int m) {
	if (m >= 1 && m <= 12)
		return true;
	else return false;
}
bool DateValidator::isLeap(int y) {
	return !(y % 4 != 0 || y % 100 == 0 && y % 400 != 0);
}

bool DateValidator::isDayValid(int d, int m, int y) {
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYearValid(y) && isYearValid(m)) {
		if (isLeap(y))
			lastMonthDay[1] = 29;
		if (d >= 1 && d <= lastMonthDay[m- 1])
			return true;
		else return false;
	}
	else return false;
}

bool DateValidator::isNumberValid(int number) {
	if (number >= 1 && number <= MAX_NUMBER)
		return true;
	else return false;
}

bool DateValidator::isCourse(int course) {
	if (course >= 1 && course <= COURSE)
		return true;
	else return false;
}

bool DateValidator::isGroup(int groupe) {
	if (groupe >= 1 && groupe <= NUM_GROUP)
		return true;
	else return false;
}

bool DateValidator::isAverageBall(double b) {
	if (b >= 1 && b <= MAX_BALL)
		return true;
	else return false;
}
