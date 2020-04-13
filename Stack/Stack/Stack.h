#pragma once
#include "Node.h"

using namespace std;


template<class T>
class Stack
{
private:
	Node<T>* node;
public:
	~Stack();
	Stack();

	Stack(const Stack<T>& stack);
	Stack& operator =(const Stack<T>& stack);

	T top() const;
	void push(T c);
	void pop();
	void clearStack();
	void clear();
	bool isEmpty();
	template <class T> friend ostream& operator << (ostream & os, const Stack<T>& c);
};
