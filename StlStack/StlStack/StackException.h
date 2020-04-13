#pragma once
class StackException
{
private:
	char str[200];
public:
	StackException(const char* str);
	const char* what();
};

