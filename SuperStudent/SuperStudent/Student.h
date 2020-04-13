#pragma once
#ifndef Student_H
#define Student_H
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include"Date.h"
#include"Phone.h"
using namespace std;




class Student {
private:
	char* name;
	char* surname;
	char* patronymic;
	Date brDay;
	char* adress;
	Phone phone;
	char* facul;
	int kurs;
	
public:
	Student();
	Student(char* n, char* s, char* p, Date br, char* a, Phone ph, char* f, int k);
	Student(const Student& c);
	~Student();
	Student& operator = (const Student& c);
	
	void setName(char* n);
	char* getName();
	void setSurname(char* n);
	char* getSurname();
	void setPatronymic(char* n);
	char* getPatronymic();

	void setAdress(char* n);
	char* getAdress();
	void setFacul(char* n);
	char* getFacul();
	void setPhone(Phone a);
	Phone getPhone();
	void setKurs(int a);
	int getKurs();

	void setDate(Date a);
	Date getDate();
	friend std:: ostream& operator << (ostream & os,  Student& c);
	friend std:: istream& operator >> (istream & os, Student &  c);
};
#endif