#ifndef EXEPTION_H
#define EXEPTION_H

class ExceptionDate
{
private:
	char str[200];
public:
	ExceptionDate(const char* str);
	const char* what();
};
#endif
