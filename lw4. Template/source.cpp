/* source.cpp
 Программа демонстрирует возможности класса Matrix c использованием шаблонов.
 На примере матрицы заполненной классом Complex, который реализует
 работу с комплексными числами*/

#include <iostream>
#include "complex.h"
#include "matrix.h"

using namespace std;

void main(){
	//Matrix<Complex> a(2,2);
	//Matrix<Complex> b(2,2);

	//Complex num1(4,3);
	//Complex num2(2);

	//for (int i=0; i<2; i++)
	//	for (int j=0; j<2; j++)
	//		a[i][j]=num1;

	//for (int i=0; i<2; i++)
	//	for (int j=0; j<2; j++)
	//		b[i][j]=num2;

	//Matrix<Complex> c(a+b);

	//if (a+b==c)
	//	cout<<c<<endl;
	//for (int i=0; i<2; i++)
	//	for (int j=0; j<2; j++)
	//		cout<<a[i][j]<<endl;


	Matrix<int> a;
	Matrix<int> b;

	int num1=43;
	int num2=2;

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			a[i][j]=num1;

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			b[i][j]=num2;

	Matrix<int> c(a+b);

	if (a+b==c)
		cout<<c<<endl;



	return;}