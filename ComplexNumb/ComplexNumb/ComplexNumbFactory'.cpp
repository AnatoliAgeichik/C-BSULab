#include<iostream>
#include"ComplexNumb.h"
#include"ComplexNumbFactory.h"

void ComplexNumbFactory::randNumb(ComplexNumb& t, int end, int begin) {
	//ComplexNumb t;
	//srand(time(0));
	t.setReal(rand() % (end - begin) + begin);
	t.setImaginary(rand() % (end - begin) + begin);

}