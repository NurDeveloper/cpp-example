/* complex.h
 Заголовочный файл с объявлением класса для работы с комплексными числами
 Определение класса содержится в complex.cpp  */
#include <iostream>

using namespace std;

class Complex{
	float Re;
	float Im;

public:
	Complex();
	Complex(float re);
	Complex(float re,float im);

	Complex operator+ (const Complex& cmlx);
	Complex operator- (const Complex& cmlx);
	Complex operator* (const Complex& cmlx);
	bool operator== (const Complex& cmlx);
	bool operator!= (const Complex& cmlx);

	friend ostream&  operator<< (ostream& out, const Complex& cmlx);
};