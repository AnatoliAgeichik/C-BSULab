#pragma once
#include <iostream>

template <class T>
class Node
{

public:
	T data;
	Node<T>* next;

	~Node();

	Node();
	Node(const Node<T>& node);

	T getData() const;

	Node* getNext() const;

	void setData(const T newData);

	void setNext(Node<T>* newNext);
	
};



