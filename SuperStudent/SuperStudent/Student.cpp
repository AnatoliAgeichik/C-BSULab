#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Date.h"
#include"Student.h"
#include"StudentValidator.h"
using namespace std;

template <class T>
T* giveMemory(int n)
{
	T *arr = new (nothrow) T[n];
	if (!arr)
	{
		cout << "Can't give memory";
		exit;
	}
	return arr;
}

template <class T>
void freeMemory(T*& arr)
{
	delete[] arr;
	arr = nullptr;
}





	Student :: Student() : name{ giveMemory<char>(5) }, surname{ giveMemory<char>(7) }, patronymic{ giveMemory<char>(10) },
		brDay{}, adress{ giveMemory<char>(4) },  facul{ giveMemory<char>(4) }, kurs{ 1 }{

		strcpy(name, "Ivan");
		strcpy(surname, "Ivanov");
		strcpy(patronymic, "Ivanovich");
		strcpy(adress, "NaN");
		strcpy(facul, "NNO");
	}
	Student ::Student(char* n, char* s, char* p, Date br, char* a, Phone ph, char* f, int k) :name{ giveMemory<char>(strlen(n)) },
		surname{ giveMemory<char>(strlen(s)) }, patronymic{ giveMemory<char>(strlen(p) + 1) }, brDay{ br }, adress{ giveMemory<char>(strlen(a) + 1) },
		phone{ ph }, facul{ giveMemory<char>(strlen(f) + 1) }{

		strcpy(name, n);
		strcpy(surname, s);
		strcpy(patronymic, p);
		strcpy(adress, a);
		strcpy(facul, f);
		StudentValidator sv;
		kurs = sv.validKurs(k);
		
		
	}
	Student:: Student(const Student& c) : name{ giveMemory<char>(strlen(c.name) + 1) }, surname{ giveMemory<char>(strlen(c.surname) + 1) },
		patronymic{ giveMemory<char>(strlen(c.patronymic) + 1) }, brDay{ c.brDay }, adress{ giveMemory<char>(strlen(c.adress) + 1) },
		phone{ c.phone }, facul{ giveMemory<char>(strlen(c.facul) + 1) }, kurs{ c.kurs }
	{
		strcpy(this->name, c.name);
		strcpy(this->surname, c.surname);
		strcpy(this->patronymic, c.patronymic);
		strcpy(this->adress, c.adress);
		strcpy(this->facul, c.facul);
	}
	Student:: ~Student() {
		delete[] name;
		delete[] surname;
		delete[] patronymic;
		delete[] adress;
		delete[] facul;
		//	freeMemory(name);
			//freeMemory(surname);
			//freeMemory(patronymic);
			//freeMemory(adress);
			//freeMemory(facul);
	}

	Student& Student:: operator = (const Student& c)
	{
		if (this == &c)
			return *this;
		delete[] name;
		delete[] surname;
		delete[]patronymic;
		name = giveMemory<char>(strlen(c.name) + 1);
		strcpy(this->name, c.name);
		surname = giveMemory<char>(strlen(c.surname) + 1);
		strcpy(this->surname, c.surname);
		patronymic = giveMemory<char>(strlen(c.patronymic) + 1);
		strcpy(this->patronymic, c.patronymic);
		brDay = c.brDay;
		delete[] this->adress;
		adress = giveMemory<char>(strlen(c.adress) + 1);
		strcpy(this->adress, c.adress);
		phone = c.phone;
		delete[] this->facul;
		facul = giveMemory<char>(strlen(c.facul) + 1);
		strcpy(this->facul, c.facul);
		kurs = c.kurs;
		return *this;
	}
	void Student::setName(char* n) {
		delete[] name;
		name = giveMemory<char>(strlen(n) + 1);
		name = giveMemory<char>(strlen(n) + 1);
		strcpy(name, n);
	}
	char* Student::getName() {
		return name;
	}
	void Student::setSurname(char* n) {
		delete[] surname;
		surname = giveMemory<char>(strlen(n) + 1);
		strcpy(surname, n);
	}
	char* Student::getSurname() {
		return surname;
	}
	void Student::setPatronymic(char* n) {
		delete[] patronymic;
		patronymic = giveMemory<char>(strlen(n) + 1);
		strcpy(patronymic, n);
	}
	char* Student::getPatronymic() {
		return name;
	}

	void Student::setAdress(char* n) {
		delete[] adress;
		adress = giveMemory<char>(strlen(n) + 1);
		strcpy(adress, n);
	}
	char* Student::getAdress() {
		return adress;
	}
	void Student::setFacul(char* n) {
		delete[] facul;
		facul = giveMemory<char>(strlen(n) + 1);
		strcpy(facul, n);
	}
	char* Student::getFacul() {
		return facul;
	}
	void Student::setPhone(Phone a) {
		phone = a;
		
	}
	Phone Student::getPhone() {
		return phone;
	}
	void Student::setKurs(int a) {
		StudentValidator sv;
		kurs = sv.validKurs(a);
	}
	int Student:: getKurs() {
		return kurs;
	}

	void Student::setDate(Date a) {
		brDay = a;

	}
	Date Student::getDate() {
		return brDay;
	}
	ostream& operator << (ostream & os,  Student& c)
	{
		os << c.name << ' ' << c.surname << '	' << c.patronymic << ' ' <<  c.brDay << ' ' << c.adress << ' ' << c.phone << ' ' << c.facul << ' ' << c.kurs << '\n';
		return os;
	}
	istream& operator >> (istream & os, Student &  c)
	{
		cout << "enter name" << '\n';
		os >> c.name;
		cout << "enter surname" << '\n';
		os >> c.surname;
		cout << "enter patronymic" << '\n';
		os >> c.patronymic;
		cout << "enter brDay" << '\n';
		os >> c.brDay;
		cout << "enter adress" << '\n';
		os >> c.adress;
		cout << "enter phone" << '\n';
		os >> c.phone;
		cout << "enter facul" << '\n';
		os >> c.facul;
		cout << "enter kurs" << '\n';
		os >> c.kurs;
		StudentValidator sv;
		c.kurs = sv.validKurs(c.kurs);
		
		return os;
	}

