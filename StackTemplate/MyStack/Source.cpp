#include<iomanip>
#include<fstream>
#include"Node.h"
#include"Node.cpp"
#include"Stack.h"
#include"Stack.cpp"
#include"WorkWithSequence.h"
#include"WorkWithSequence.cpp"
#include"Parser.h"
#include"StackException.h"
#include"Elephant.h"
int main() {
	/*
	Stack<char> st;
	st.push('a');
	st.push('f');
	st.push('s');
	st.push('a');
	cout << st;  
	*/
	Elephant elephant1(130, "gray", "elephant1", 17);
	Elephant elephant2(125, "gray", "elephant1", 18);
	Elephant elephant3(135, "gray", "elephant1", 16);
	Elephant elephant4(165, "gray", "elephant1", 12);
	Elephant elephant5(115, "gray", "elephant1", 18);
	Stack<Elephant> st;
	st.push(elephant1);
	st.push(elephant2);
	st.push(elephant3);
	st.push(elephant4);
	st.push(elephant5);
	//ofstream ggg("input.txt");
	//ggg << elephant1;
	//ggg << elephant2;
	//ggg << elephant3;
	//ggg << elephant4;
	//ggg << elephant5;
	//cout << st;
	//WorkWithSequence<Elephant>::PrintInverseSeq(st);
	//WorkWithSequence<Elephant>::PrintSeq(st);

	//st.push(5);
	//st.push(8);
	//st.push(4);
	//cout << st;

	
	/*
	Stack<double> st;
	*/
	int a{ 0 };
	cout << "1-enter self; 2-enter file";
	while (a < 1 || a>2) {
		a=Parser::ParseInt(cin);

	}
	int n{ 0 };
	ifstream fff("input.txt");
	if (!fff)
		throw StackException("no file");
	int tttt{ 0 };

	Elephant tmp;
	switch (a)
	{
	case 1:
		cout << "Size stack";
		n = Parser::ParseInt(cin);
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			st.push(tmp);

		}
		break;
	case 2:
		while (1) {
			if (fff.eof())
				st.push(tmp);
				break;
			fff>>tmp;
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
		WorkWithSequence<Elephant>::PrintInverseSeq(st);
		break;
	case 2:
		WorkWithSequence<Elephant>::PrintSeq(st);
	default:
		break;
	}
	system("pause");
}