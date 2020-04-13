#include<iostream>
#include"Parser.h"
#include<cstring>

using namespace std;
int Parser::ParseInt(istream& os) {

	char numberInStr[256];

	//string numberInStr;
	char* end = 0;

	long value = 0;

	bool flag = true;

	while (flag)

	{

		cout << endl << "Please, enter int value:";

		os.clear();//очищаем состояние потока (делаем его работоспособным)

		os.sync();//очищаем поток от имеющихся в нем символов.

		os >> numberInStr;

		errno = 0;

		value = strtol(numberInStr, &end, 10);



		if (errno != 0) {

			cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";

		}

		else if (*end)

		{

			if (end == numberInStr) {

				cout << "Conversion error, this is not number" << endl;//"rr123456789"

			}

			else {

				cout << "Converted partially: " << value << ", non-convertible part: " << end << endl;//"12345rr6789"

				flag = false;

			}

		}

		else

		{

			cout << "Converted successfully: " << value << endl;//"123456789"

			flag = false;

		}

	}

	return static_cast<int> (value);



}


double Parser::ParseDouble(istream& os) {

	char numberInStr[256];

	char* end = 0;

	double value = 0;

	bool flag = true;

	//cout << endl << "Please, enter double value:";

	os.clear();//очищаем состояние потока (делаем его работоспособным)

	os.sync();//очищаем поток от имеющихся в нем символов.

	os >> numberInStr;

	errno = 0;

	value = strtod(numberInStr, &end);



	if (errno != 0) {

		cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";

	}

	else if (*end)

	{

		if (end == numberInStr) {

			cout << "Conversion error, this is not number" << endl;//"rr123456789"

		}

		else {

			cout << "Converted partially: " << value << ", non-convertible part: " << end << endl;//"12345rr6789"

			flag = false;

		}

	}

	else

	{

		//cout << "Converted successfully: " << value << endl;//"123456789"

		flag = false;

	}



	return static_cast<double> (value);



}

double Parser::ParseDouble(const char* s) {


	char* end = 0;

	double value = 0;

	bool flag = true;



	errno = 0;

	value = strtod(s, &end);



	if (errno != 0) {

		cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";

	}

	else if (*end)

	{

		if (end == s) {

			cout << "Conversion error, this is not number" << endl;//"rr123456789"

		}

		else {

			cout << "Converted partially: " << value << ", non-convertible part: " << end << endl;//"12345rr6789"

			flag = false;

		}

	}

	else

	{

		cout << "Converted successfully: " << value << endl;//"123456789"

		flag = false;

	}



	return static_cast<double> (value);



}

int Parser::ParseInt(const char* s) {


	char* end = 0;

	int value = 0;

	bool flag = true;



	errno = 0;

	value = strtod(s, &end);



	if (errno != 0) {

		cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";

	}

	else if (*end)

	{

		if (end == s) {

			cout << "Conversion error, this is not number" << endl;//"rr123456789"

		}

		else {

			cout << "Converted partially: " << value << ", non-convertible part: " << end << endl;//"12345rr6789"

			flag = false;

		}

	}

	else

	{

		cout << "Converted successfully: " << value << endl;//"123456789"

		flag = false;

	}



	return static_cast<int> (value);



}
