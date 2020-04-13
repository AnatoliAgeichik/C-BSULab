#pragma once
#pragma once
class ComplexNumbException
{
private:
	char str[200];
public:
	ComplexNumbException(const char* str);
	const char* what();
};

