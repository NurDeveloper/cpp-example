//Определение класса для работы с матрицами

#include "matrix.h"

Matrix::Matrix(int row,int col){
	Storage = new double *[row];
	for (int i=0; i<row; i++)
		Storage[i] = new double [col];

	for (int i=0; i<row; i++)
		for (int j=0; j<col; j++)
			Storage[i][j]=0;

	Row=row;
	Col=col;
}

Matrix::Matrix(const Matrix &Mat){
	if (this!=&Mat){
		Storage = new double *[Mat.Row];
		for (int i=0; i<Mat.Row; i++)
			Storage[i] = new double [Mat.Col];

		for (int i=0; i<Mat.Row; i++)
			for (int j=0; j<Mat.Col; j++)
				Storage[i][j]=Mat.Storage[i][j];

		Row=Mat.Row;
		Col=Mat.Col;
	}
}

Matrix Matrix::operator+ (const Matrix& Mat){
	if ((Row==Mat.Row) && (Col==Mat.Col)){
		Matrix result(Row,Col);
		for (int i=0; i<Row; i++)
			for (int j=0; j<Col; j++)
				result.Storage[i][j]=Storage[i][j]+Mat.Storage[i][j];
		return result;
	}
	else exit(1); 
}

Matrix Matrix::operator+ (double num){
	Matrix result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]+=num;

	return result;
}

Matrix Matrix::operator- (const Matrix& Mat){
	if ((Row==Mat.Row) && (Col==Mat.Col)){
		Matrix result(Row,Col);
		for (int i=0; i<Row; i++)
			for (int j=0; j<Col; j++)
				result.Storage[i][j]=Storage[i][j]-Mat.Storage[i][j];
		return result;
	}
	else exit(1);
}

Matrix Matrix::operator- (double num){
	Matrix result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]-=num;

	return result;
}

Matrix Matrix::operator* (const Matrix& Mat){
	if (Col==Mat.Row){
		Matrix result(Row,Mat.Col);

		for (int i=0; i<result.Row; i++)
			for (int j=0; j<result.Col; j++)
				result.Storage[i][j]=0;

		for (int i=0; i<result.Row; i++)
			for (int j=0; j<result.Col; j++)
				for (int k=0; k<Col; k++)
					result.Storage[i][j]+=Storage[i][k]*Mat.Storage[k][j];
		return result;
	}
	else exit(1);
}

Matrix Matrix::operator* (double num){
	Matrix result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]*=num;

	return result;
}

Matrix& Matrix::operator+= (const Matrix& Mat){
	(*this)=(*this)+Mat;
	return *this;}

Matrix& Matrix::operator+= (double num){
	(*this)=(*this)+num;
	return *this;}

Matrix& Matrix::operator-= (const Matrix& Mat){
	(*this)=(*this)-Mat;
	return *this;}

Matrix& Matrix::operator-= (double num){
	(*this)=(*this)-num;
	return *this;}

Matrix& Matrix::operator*= (const Matrix& Mat){
	(*this)=(*this)*Mat;
	return *this;}

Matrix& Matrix::operator*= (double num){
	(*this)=(*this)*num;
	return *this;}

const Matrix& Matrix::operator= (const Matrix& Mat){
	if (this==&Mat) return *this;
	else
	{
		if (Storage) delete [] Storage;
		if (Mat.Storage){
			Storage = new double *[Mat.Row];
			for (int i=0; i<Mat.Row; i++)
				Storage[i] = new double [Mat.Col];

			for (int i=0; i<Mat.Row; i++)
				for (int j=0; j<Mat.Col; j++)
					Storage[i][j]=Mat.Storage[i][j];
		}
		else Storage=0;

		Row=Mat.Row;
		Col=Mat.Col;
		return *this;
	}
}

double* Matrix::operator[] (int i){
	if (((i>=0) && (i<Row)) || ((i>=0) && (i<Col))) return Storage[i];
	else exit(1);
}

bool Matrix::operator== (const Matrix& Mat){
	if ((Row==Mat.Row) && (Col==Mat.Col)){
		int i=0;
		int j=0;

		while ((i<Row) && (j<Col)){
			if (Storage[i][j]!=Mat.Storage[i][j]) return false;
			i++; j++;
		}
		return true;
	}
	else return false;
}

bool Matrix::operator!= (const Matrix& Mat){
	return !((*this)==Mat);
}

Matrix::~Matrix(){
	delete [] Storage;
}

ostream&  operator<< (ostream& out,Matrix& Mat){
	for (int i=0; i<Mat.Row; i++){
		for (int j=0; j<Mat.Col; j++){
			out.width(5);
			out<<Mat.Storage[i][j];
		}
		out<<endl;
	}
	return out;
}