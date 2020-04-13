#pragma once
#include <iostream>
const double MaxWeightElephant = 8000.;
const int MaxAgeElephant = 70;

using namespace std;


class Elephant
{
private:
	double weight;	//	weight>0 && weight<=MaxWeightElephant
	char* color;
	char* name;
	int age;	//age>=0 && age ><=MaxAgeElephant

public:
	Elephant();//ctor
	Elephant(double weight,const char* color,const char* name, int age);//ctor
	Elephant(const Elephant &ob);
	~Elephant();//destructor;
	void setWeight(double newWeight);
	double getWeight();
	void setAge(int newAge);
	int getAge();
	void setColor(const char* newColor);
	char *getColor();
	void setName(const char* newName);
	char *getName();
	void setElephant(double newWeight, char* newColor, char* newName, int newAge);
	void EnterElephantFromConsole();

	friend ostream &operator<<(ostream &stream, const Elephant &ob);
	friend istream &operator>>(istream &stream, Elephant &ob);
	friend bool operator==(const Elephant& left, const Elephant& right);
	friend bool operator!=(const Elephant& left, const Elephant& right);
	bool operator<(const Elephant &ob);
	bool operator>(const Elephant &ob);
	bool operator<=(const Elephant &ob);
	bool operator>=(const Elephant &ob);
	Elephant& operator=(const Elephant& right);
};



