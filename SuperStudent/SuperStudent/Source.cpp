#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Date.h"
#include"DateValidator.h"
#include"ExeptionDate.h"
#include"Month.h"
#include"Phone.h"
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




int main()
{
		int cnt;
		cout << "Please, enter count student";
		cin >> cnt;
		Student* arr;
		arr = giveMemory<Student>(cnt);

		int a;
		cout << "if you want to generate an array randomly press 1 " << '\n';
		cout << "if you want to enter the array yourself randomly press 2 " << '\n';
		bool flag = true;
		while (flag) {
			cin >> a;
			switch (a) {
			case 1:
				randArr(arr, cnt);
				flag = false;
				break;
			case 2:
				for (int k = 0; k < cnt; ++k) {
					cin >> arr[k];
				}
				flag = false;
				break;
			default:
				cout << "bad value, please 1 or 2" << '\n';
				break;

			}
		}

		cout << "if you want to see list for a given faculty press 1 " << '\n';
		cout << "if you want to see list student lists for each faculty and course press 2 " << '\n';
		cout << "if you want to see list of students born after a given year. 3 " << '\n';
		flag = true;
		char* f = giveMemory<char>(30);
		int cntF{ 0 };
		int y{ 0 };
		int cntY{ 0 };
		Student * l;
		while (flag) {
			cin >> a;
			switch (a) {
			case 1:
				cout << "Please enter name faculty" << endl;
				cin.ignore();
				cin.getline(f, 30);
				cntF = cntFacul(arr, cnt, f);
				l = giveMemory<Student>(cntF);
				ListForFacul(arr, cnt, l, f);
				printArr(l, cntF);
				flag = false;

				break;
			case 2:
				listAll(arr, cnt);
				flag = false;
				break;
			case 3:

				cout << "Please enter year" << '\n';
				cin >> y;
				cntY = CountForBrDay(arr, cnt, y);
				l = giveMemory<Student>(cntY);
				ListForBrDay(arr, cnt, l, y);
				printArr(l, cntY);
				flag = false;
				break;
			default:
				cout << "bad value, please 1 or 2 or 3" << '\n';
				break;

			}
		}

		delete[] f;
		system("pause");
		/*
		Date d{ 33,12,2009 };
		char* name{ giveMemory<char>(7) };
		strcpy(name, "Vasaya");
		int p{ 7654321 };
		Student loh(name, name, name, d, name, p, name, 5);
		//cout << loh;
		int n{ 1000 };
		Student* arr{ giveMemory<Student>(n) };
		randArr(arr, n);
		listAll(arr, n);
		//sortKurs(arr, 0, n-1);
		//printArr<Student*>(arr, n);
		delete[] name;
	*/
	/*
	char* f = new char;
	strcpy(f, "Geo");
	//int a = cntFacul(arr, n, f);
	//Student *l= giveMemory<Student>(a) ;
	//ListForFacul(arr, n, l,a, f);
	printArr<Student*>(arr, n);
	cout << "--------------------------------------------------------------------------------------------------------"<<'\n';
	//printArr<Student*>(l, a);
	Date dd(12, 11, 1998);
	int b = CountForBrDay(arr, n, dd);
	Student *ll = giveMemory<Student>(b);
	ListForBrDay(arr, n, ll, dd);
	printArr<Student*>(ll, b);
	//cout << d;
	*/
	}

