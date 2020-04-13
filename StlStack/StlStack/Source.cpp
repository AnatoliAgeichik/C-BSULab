#include<iostream>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include"Parser.h"
#include"WorkWithSequence.h"
#include"StackException.h"

#include <windows.h>
using namespace std;

int main(){

		stack<double> st;
		double s;
		double buf[150];
		int len = 0;

		int a{ 0 };
		cout << "1-enter self; 2-enter file";
		while (a < 1 || a>2) {
			a = Parser::ParseInt(cin);

		}
		int n{ 0 };
		ifstream fff("input.txt");
		if (!fff) {
			cerr << "no file";
			fff.close();
			Sleep(2000);
			exit(0);
		}
		
		int tmp{ 0 };
		switch (a)
		{
		case 1:
			cout << "Size stack";
			n = Parser::ParseInt(cin);
			for (int i = 0; i < n; ++i) {
				tmp = Parser::ParseInt(cin);
				st.push(tmp);

			}
			break;
		case 2:
			
			while (1) {
				tmp = Parser::ParseDouble(fff);
				if (fff.eof()) {
					st.push(tmp);
					break;
				}
				st.push(tmp);
			}
			
		default:
			break;
		}
		a = 0;
		cout << "1-print inverse seq; 2-print seq";
		while (a < 1 || a>2) {
			a = Parser::ParseInt(cin);

		}
		switch (a)
		{
		case 1:
			WorkWithSequence::PrintInverseSeq(st);
			break;
		case 2:
			WorkWithSequence::PrintSeq(st);
		default:
			break;
		}
		system("pause");
}
