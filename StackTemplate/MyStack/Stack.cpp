#include"Node.h"
#include"Stack.h"
#include"StackException.h"


/*template<class T>
void Stack<T>::deleteStack(Node<T> *nod) {
	if (nod->getNext())
		deleteStack(nod->getNext());
	delete nod;
}*/
template <class T>
void Stack<T>::clearStack()
{
	while (node)
	{
		Node<T>* tmp = node;
		node = node->next;
		delete tmp;
	}
}

template<class T>
Stack<T>::~Stack() {
	clearStack();
}

template <class T>
Stack<T>::Stack(): node()
{

}
template <class T>
Stack<T>::Stack(const Stack<T>& stack)
{
	Node<T>* tmp{ stack.node };
	Node<T>* now{ nullptr };
	Node<T>* start{ nullptr };
	while (tmp)
	{
		if (!now)
			now = new Node<T>;
		now->setData(tmp->getData());
		if (tmp->getNext())
			now->setNext(new Node<T>());
		else
			now->setNext(nullptr);
		if (!start)

			start = now;
		tmp = tmp->getNext();
		if (now->getNext())
			now = now->getNext();
	}
	node = start;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack) {
	//мой код
	
	Node<T>* tmp{ stack.node };
	Node<T>* now{ nullptr };
	Node<T>* start{ nullptr };
	while (tmp)
	{
		if (!now)
			now = new Node<T>;
		now->setData(tmp->getData());
		if (tmp->getNext())
			now->setNext(new Node<T>());
		else
			now->setNext(nullptr);
		if (!start)
			start = now;
		tmp = tmp->getNext();
		if (now->getNext())
			now = now->getNext();
	}
	node = start;
	return *this;
}

template <class T>

T Stack<T>::top() const{
	if (node)
		return node->getData();
	else

		throw StackException("Element not found");

}

template <class T>
void Stack<T>::push(T c) {
	Node<T>* nd = new Node<T>;
	nd->setData(c);
	nd->setNext(node);
	node = nd;

}
template <class T>
void Stack<T>::pop() {
	/*Node * tmp = node->getNext();
	delete node;
	node = tmp;*/
	
	if (node) {
		Node<T>* tmp{ node->getNext() };
		delete node;
		node = tmp;
		
	}
	else {
		throw StackException("Element not found");
	}
}

template <class T>
void Stack<T>::clear() {
	if (node)
		deleteStack(node);
	node = nullptr;
	
}
template <class T>
bool Stack<T>::isEmpty() {
	return (!node);
}

template <class T>
ostream& operator<< (ostream & os, const Stack<T>& c) {
	Node<T>* tmp{ c.node };
	while (tmp)
	{
		os << tmp->getData() << " ";
		tmp = tmp->getNext();
	}
	os << endl;
	return os;
}

















