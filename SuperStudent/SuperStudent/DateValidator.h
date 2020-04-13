#ifndef DATEVALIDATOR_H
#define DATEVALIDATOR_H

class DateValidator
{
public:
	bool isYearValid(int y);
	bool isMonthValid(int y);
	bool isLeap(int y);
	bool isDayValid(int d, int m, int y);
	bool isNumberValid(int number);
	bool isCourse(int course);
	bool isGroup(int group);
	bool isAverageBall(double b);
};
#endif
