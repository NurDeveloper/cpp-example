/* source.cpp
 Программа демонстрирует возможности класса Complex */

#include <iostream>
#include "complex.h"

using namespace std;

void main(){
	Complex a;
	Complex b(1);
	Complex c(1,1);
	cout << "a+b = " << a+b << endl
	     << "a-b = " << a-b << endl
	     << "b*c = " << b*c << endl;

	if (a == b) cout << "Something wrong...\n"; 
	cout << "As expected\n";

	return;
}