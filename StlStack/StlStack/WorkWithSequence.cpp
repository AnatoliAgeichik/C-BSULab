#include<iostream>
#include<stack>
#include<vector>
#include"WorkWithSequence.h"

using namespace std;

stack<double> WorkWithSequence::reverseStack(stack<double> st) {
	stack<double> newStack;
	while (!(st.empty())) {
		newStack.push(st.top());
		st.pop();
	}
	return newStack;
}
void WorkWithSequence::PrintSeq(stack<double> st) {

	double tmp{ 0 };
	tmp = st.top();
	st.pop();
	cout << tmp << '\n';
	/*
	Здесь мы ищем возрастающею последовательность в стеке
	*/

	while (!(st.empty())) {
		if (tmp < st.top()) {
			tmp = st.top();
			cout << tmp;
			cout << '\n';
			st.pop();
		}
		else {

			tmp = st.top();
			cout << "---------------------------------------------------------------------------";
			cout << '\n';
			cout << tmp;
			cout << '\n';
			st.pop();
		}
	}
}

void WorkWithSequence::PrintInverseSeq(stack<double> st) {
	/*
	Перевернули стек и теперь нам надо искать уже убывающею последовательность
	1 2 3
	3 2 1
	*/
	st = reverseStack(st);
	double tmp{ 0 };
	tmp = st.top();
	st.pop();
	cout << tmp << '\n';
	while (!(st.empty())) {
		if (tmp > st.top()) {
			tmp = st.top();
			cout << tmp;
			cout << '\n';
			st.pop();
		}
		else {
			tmp = st.top();
			cout << "---------------------------------------------------------------------------";
			cout << '\n';
			cout << tmp;
			cout << '\n';
			st.pop();
		}
	}
	//PrintSeq(st);
}