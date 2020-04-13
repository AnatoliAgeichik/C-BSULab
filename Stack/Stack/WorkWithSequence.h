#pragma once
#include"Stack.h"



template<class T>
class WorkWithSequence {
public:
	static Stack<T> reverseStack(Stack<T> st);
	static void PrintInverseSeq(Stack<T> st);
	static void PrintSeq(Stack<T> st);
};