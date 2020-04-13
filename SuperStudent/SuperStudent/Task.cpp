#ifndef Student_CPP
#define Student_CPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include"Date.h"
#include"Student.h"
using namespace std;

Date randDate();
void randArr(Student *arr, int n);
void printArr(Student* arr, int end, int begin = 0);
int cntFacul(Student* arr, int n, char *facul);
void ListForFacul(Student* arr, int n, Student* list, char* facul);
int CountForBrDay(Student* arr, int n, Date d);
int CountForBrDay(Student* arr, int n, int d);
void ListForBrDay(Student* arr, int n, Student* list, Date d);
void ListForBrDay(Student* arr, int n, Student* list, int d);
void Swap(Student & a, Student  &b);
void sortFacul(Student *arr, int beg, int end);
void sortKurs(Student *arr, int beg, int end);
void printKurs(Student* arr, int beg, int end);
void listAll(Student* arr, int n);

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


Date randDate() {

	int day{ 0 };
	int mont{ 0 };
	int year{ 0 };

	mont = rand() % 12 + 1;

	year = rand() % 19 + 1985;
	Date d(day, mont, year);
	return d;

}

void randArr(Student *arr, int n) {
	int M = 5;
	char **f = new (nothrow) char*[M];
	if (!arr) {
		cout << "very bad";
		exit;
	}
	for (int i = 0; i < M; ++i) {
		f[i] = new char[10];
	}
	for (int i = 0; i < M; ++i) {
		switch (i)
		{
		case 0:
			strcpy(*(f + i), "Geo");
			break;
		case 1:
			strcpy(*(f + i), "History");
			break;
		case 2:
			strcpy(*(f + i), "Physic");
			break;
		case 3:
			strcpy(*(f + i), "Bio");
			break;
		case 4:
			strcpy(*(f + i), "Economic");
			f[i][8] = '\0';
			break;
		default:
			break;
		}
	}
	int tmp;
	for (int i = 0; i < n; ++i) {
		tmp = rand() % 5;
		arr[i].setFacul(f[tmp]);
		tmp = rand() % 6 + 1;
		arr[i].setKurs(tmp);
		arr[i].setDate(randDate());
	}
	for (int i = 0; i < M; i++)
	{
		delete[] f[i];
	}
	delete[] f;

}

void printArr(Student* arr, int end, int begin) {
	for (int i = begin; i < end; ++i)
		cout << arr[i];

}



int cntFacul(Student* arr, int n, char *facul) {
	int cnt{ 0 };
	for (int i = 0; i < n; ++i) {
		if (!strcmp(arr[i].getFacul(), facul))
			cnt++;

	}
	return cnt;
}
void ListForFacul(Student* arr, int n, Student* list, char* facul) {
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (!strcmp(arr[i].getFacul(), facul)) {
			list[tmp] = arr[i];
			tmp++;
		}

	}

}

int CountForBrDay(Student* arr, int n, Date d) {
	int tmp{ 0 };

	for (int i = 0; i < n; ++i) {
		if (arr[i].getDate().getYear() > d.getYear())
			tmp++;

	}
	return tmp;
}


void ListForBrDay(Student* arr, int n, Student* list, Date d) {
	int tmp{ 0 };
	int h;
	for (int i = 0; i < n; ++i) {
		if (arr[i].getDate().getYear() > d.getYear()) {
			list[tmp] = arr[i];
			tmp++;
		}
	}
}

int CountForBrDay(Student* arr, int n, int d) {
	int tmp{ 0 };
	for (int i = 0; i < n; ++i) {
		if (arr[i].getDate().getYear() > d)
			tmp++;

	}
	return tmp;
}


void ListForBrDay(Student* arr, int n, Student* list, int d) {
	int tmp{ 0 };
	int h;
	for (int i = 0; i < n; ++i) {
		if (arr[i].getDate().getYear() > d) {
			list[tmp] = arr[i];
			tmp++;
		}
	}
}


void Swap(Student & a, Student  &b)
{
	Student tmp;
	tmp = a;
	a = b;
	b = tmp;
}


void sortFacul(Student *arr, int beg, int end)
{
	int l = beg, r = end;
	Student piv = arr[(l + r) / 2];
	while (l < r)
	{
		while (strcmp(arr[l].getFacul(), piv.getFacul()) < 0)
			l++;
		while (strcmp(arr[r].getFacul(), piv.getFacul()) > 0)
			r--;
		if (l <= r)
			Swap(arr[l++], arr[r--]);
	}
	if (beg < r)
		sortFacul(arr, beg, r);
	if (end > l)
		sortFacul(arr, l, end);
}
void sortKurs(Student *arr, int beg, int end)
{
	int l = beg, r = end;
	Student piv = arr[(l + r) / 2];
	while (l < r)
	{
		while (arr[l].getKurs() < piv.getKurs())
			l++;
		while (arr[r].getKurs() > piv.getKurs())
			r--;
		if (l <= r)
			Swap(arr[l++], arr[r--]);
	}
	if (beg < r)
		sortKurs(arr, beg, r);
	if (end > l)
		sortKurs(arr, l, end);
}

void printKurs(Student* arr, int beg, int end) {
	int tmpEnd{ 0 };
	for (int j = beg; beg < end; ++j) {
		int k = arr[beg].getKurs();
		for (int i = beg; i < end; ++i) {
			if (!(arr[i].getKurs() == k))
			{
				break;
			}
			j++;
		}
		printArr(arr, j, beg);
		cout << "-------------------------------------------------------------------------------------------------------" << '\n';
		beg = j;
		j--;
	}
}


void listAll(Student* arr, int n) {
	sortFacul(arr, 0, n - 1);
	int end{ 0 };
	int start{ 0 };

	for (int j = 0; j < n; ++j) {

		char* f{ giveMemory<char>(strlen(arr[start].getFacul()) + 1) };
		strcpy(f, arr[start].getFacul());
		for (int i = start; i < n; ++i) {
			if (strcmp(f, arr[i].getFacul()))
			{
				break;
			}
			end++;
			j++;
		}
		sortKurs(arr, start, end - 1);
		printKurs(arr, start, end - 1);
		cout << "--------------------------------------------------------------------------------------------------" << '\n';
		start = end;
		delete[] f;
	}
	sortKurs(arr, start, n - 1);
	//printArr<Student*>(arr, n);





}
#endif