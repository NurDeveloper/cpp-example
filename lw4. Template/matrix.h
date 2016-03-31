/* matrix.h
 Заголовочный файл с объявлением класса для работы с матрицами.
 Класс построен на базе шаблонов.  */
#include <iostream>
#define R 100
#define C 100

using namespace std;

template <class Data> class Matrix{
private:
	Data **Storage;
	int Row;
	int Col;

public:
	Matrix(int row=R,int cow=C);
	Matrix(const Matrix<Data>& Mat);
	~Matrix();

	Matrix<Data> operator+ (const Matrix<Data>& Mat);
	Matrix<Data> operator+ (Data D);
	Matrix<Data> operator- (const Matrix<Data>& Mat);
	Matrix<Data> operator- (Data D);
	Matrix<Data> operator* (const Matrix<Data>& Mat);
	Matrix<Data> operator* (Data D);

	Matrix<Data>& operator+= (const Matrix<Data>& Mat);
	Matrix<Data>& operator+= (Data D);
	Matrix<Data>& operator-= (const Matrix<Data>& Mat);
	Matrix<Data>& operator-= (Data D);
	Matrix<Data>& operator*= (const Matrix<Data>& Mat);
	Matrix<Data>& operator*= (Data D);
	const Matrix<Data>& operator= (const Matrix<Data>& Mat);

	Data* operator[] (int i);

	bool operator== (const Matrix<Data>& Mat);
	bool operator!= (const Matrix<Data>& Mat);

	template <class Data>
	friend ostream&  operator<< (ostream& out, const Matrix<Data>& Mat);
};

template <class Data>
Matrix <Data>::Matrix(int row,int col){
	Storage = new Data *[row];
	for (int i=0; i<row; i++)
		Storage[i] = new Data [col];

	for (int i=0; i<row; i++)
		for (int j=0; j<col; j++)
			Storage[i][j]=0;

	Row=row;
	Col=col;
}

template <class Data>
Matrix <Data>::Matrix(const Matrix<Data>& Mat){
	if (this!=&Mat){
		Storage = new Data *[Mat.Row];
		for (int i=0; i<Mat.Row; i++)
			Storage[i] = new Data [Mat.Col];

		for (int i=0; i<Mat.Row; i++)
			for (int j=0; j<Mat.Col; j++)
				Storage[i][j]=Mat.Storage[i][j];

		Row=Mat.Row;
		Col=Mat.Col;
	}
}

template <class Data>
Matrix<Data> Matrix<Data>::operator+ (const Matrix<Data>& Mat){
	if ((Row==Mat.Row) && (Col==Mat.Col)){
		Matrix<Data> result(Row,Col);
		for (int i=0; i<Row; i++)
			for (int j=0; j<Col; j++)
				result.Storage[i][j]=Storage[i][j]+Mat.Storage[i][j];
		return result;
	}
	else exit(1); 
}

template <class Data>
Matrix<Data> Matrix<Data>::operator+ (Data D){
	Matrix<Data> result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]+=D;

	return result;
}

template <class Data>
Matrix<Data> Matrix <Data>::operator- (const Matrix<Data>& Mat){
	if ((Row==Mat.Row) && (Col==Mat.Col)){
		Matrix<Data> result(Row,Col);
		for (int i=0; i<Row; i++)
			for (int j=0; j<Col; j++)
				result.Storage[i][j]=Storage[i][j]-Mat.Storage[i][j];
		return result;
	}
	else exit(1);
}

template <class Data>
Matrix<Data> Matrix <Data>::operator- (Data D){
	Matrix<Data> result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]-=D;

	return result;
}

template <class Data>
Matrix<Data> Matrix <Data>::operator* (const Matrix<Data>& Mat){
	if (Col==Mat.Row){
		Matrix<Data> result(Row,Mat.Col);

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

template <class Data>
Matrix<Data> Matrix <Data>::operator* (Data D){
	Matrix<Data> result((*this));

	for (int i=0; i<Row; i++)
		for (int j=0; j<Col; j++)
			result.Storage[i][j]*=D;

	return result;
}

template <class Data>
Matrix<Data>& Matrix <Data>::operator+= (const Matrix<Data>& Mat){
	(*this)=(*this)+Mat;
	return *this;}

template <class Data>
Matrix<Data>& Matrix <Data>::operator+= (Data D){
	(*this)=(*this)+D;
	return *this;}

template <class Data>
Matrix<Data>& Matrix <Data>::operator-= (const Matrix<Data>& Mat){
	(*this)=(*this)-Mat;
	return *this;}

template <class Data>
Matrix<Data>& Matrix <Data>::operator-= (Data D){
	(*this)=(*this)-D;
	return *this;}

template <class Data>
Matrix<Data>& Matrix <Data>::operator*= (const Matrix<Data>& Mat){
	(*this)=(*this)*Mat;
	return *this;}

template <class Data>
Matrix<Data>& Matrix <Data>::operator*= (Data D){
	(*this)=(*this)*D;
	return *this;}

template <class Data>
const Matrix<Data>& Matrix <Data>::operator= (const Matrix<Data>& Mat){
	if (this==&Mat) return *this;
	else
	{
		if (Storage) delete [] Storage;
		if (Mat.Storage){
			Storage = new Data *[Mat.Row];
			for (int i=0; i<Mat.Row; i++)
				Storage[i] = new Data [Mat.Col];

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

template <class Data>
Data* Matrix <Data>::operator[] (int i){
	if (((i>=0) && (i<Row)) || ((i>=0) && (i<Col))) return Storage[i];
	else exit(1);
}

template <class Data>
bool Matrix <Data>::operator== (const Matrix<Data>& Mat){
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

template <class Data>
bool Matrix <Data>::operator!= (const Matrix<Data>& Mat){
	return !((*this)==Mat);
}

template <class Data>
Matrix <Data>::~Matrix(){
	delete [] Storage;
}

template <class Data>
ostream&  operator<< (ostream& out,const Matrix<Data>& Mat){
	for (int i=0; i<Mat.Row; i++){
		for (int j=0; j<Mat.Col; j++){
			out.width(5);
			out<<Mat.Storage[i][j];
		}
		out<<endl;
	}
	return out;
}