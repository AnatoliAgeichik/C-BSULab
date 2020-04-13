#include"Stack.h"
#include"WorkWithSequence.h"

template <class T>
Stack<T> WorkWithSequence<T>::reverseStack(Stack<T> st) {
	Stack<T> newStack;
	while (!(st.isEmpty())) {
		newStack.push(st.top());
		st.pop();
	}
	return newStack;
}

template <class T>
void WorkWithSequence<T>::PrintSeq(Stack<T> st) {


	T tmp = st.top();
	st.pop();
	cout << tmp<<'\n';
	/*
	Здесь мы ищем возрастающею последовательность в стеке
	*/
	while (!(st.isEmpty())) {
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

template <class T>
void WorkWithSequence<T>::PrintInverseSeq(Stack<T> st) {
	/*
	Перевернули стек и теперь нам надо искать уже убывающею последовательность
	1 2 3
	3 2 1
	*/
	st = reverseStack(st);
	
	T tmp = st.top();
	st.pop();
	cout << tmp << '\n';
	while (!(st.isEmpty())) {
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
