/* matrix.h
 Заголовочный файл с объявлением класса для работы с работы с матрицами
 Определение класса содержится в matrix.cpp  */
#include <iostream>
#define R 0
#define C 0

using namespace std;

class Matrix{
private:
	double **Storage;
	int Row;
	int Col;

public:
	Matrix(int row=R,int cow=C);
	Matrix(const Matrix &Mat);
	~Matrix();

	Matrix operator+ (const Matrix& Mat);
	Matrix operator+ (double num);
	Matrix operator- (const Matrix& Mat);
	Matrix operator- (double num);
	Matrix operator* (const Matrix& Mat);
	Matrix operator* (double num);

	Matrix& operator+= (const Matrix& Mat);
	Matrix& operator+= (double num);
	Matrix& operator-= (const Matrix& Mat);
	Matrix& operator-= (double num);
	Matrix& operator*= (const Matrix& Mat);
	Matrix& operator*= (double num);
	const Matrix& operator= (const Matrix& Mat);

	double* operator[] (int i);

	bool operator== (const Matrix& Mat);
	bool operator!= (const Matrix& Mat);

	friend ostream&  operator<< (ostream& out,Matrix& Mat);
};