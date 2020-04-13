#include "Node.h"

template <class T>
Node<T>::Node() : data(), next{ nullptr }
{
}


template <class T>
Node<T>::~Node(){}

template <class T>
Node<T>::Node(const Node<T>& node) {
	data = node.data;
	next = node.next;
}
template <class T>
T Node<T>::getData() const {
	return data;
}

template <class T>
Node<T>* Node<T>::getNext() const {
	return next;
}

template <class T>
void Node<T>::setData(const T v) {
	data = v;
}

template <class T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
};