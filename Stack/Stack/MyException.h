#pragma once
class MyException
{
private:
	char str[200];
public:
	MyException(const char* str);
	const char* what();
};

