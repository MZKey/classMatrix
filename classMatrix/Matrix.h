#pragma once

#include <vector>
#include <ctime>

class Matrix
{	
private:
	typedef std::vector<std::vector<double>> matrix;
	matrix Matr;

	double Detr(const Matrix& M, unsigned Row, unsigned Col) const;
	double Detr(const Matrix& M) const;
public:
	Matrix();
	Matrix(unsigned n);
	Matrix(unsigned n, unsigned m);
	Matrix(const matrix m);
	~Matrix();

	unsigned getN() const;
	unsigned getM() const;

	void setN(unsigned n);
	void setM(unsigned m);

	unsigned size() const;
	void resize(unsigned n);
	void resize(unsigned n, unsigned m);
	void fillRandValue();
	void fillRandValue(int limitL, int limitH);
	void fillFixValue(double value);
	void inverse();
	void transposeSelf();
	Matrix transpose() const;

	void add(const Matrix& Matr);
	void sub(const Matrix& Matr);
	void mul(const Matrix& Matr);
	void div(const double number);

	Matrix operator + (const Matrix& Matr2) const;
	Matrix operator - (const Matrix& Matr2) const;
	Matrix operator / (const double number) const;
	Matrix operator * (const Matrix& Matr2) const;
	Matrix operator * (double number) const;
	friend Matrix operator * (double number, const Matrix& Matr);

	void operator += (const Matrix& Matr2);
	void operator -= (const Matrix& Matr2);
	void operator *= (const Matrix& Matr2);
	void operator /= (const double number);
	bool operator == (const Matrix& Matr2) const;
	bool operator != (const Matrix& Matr2) const;

	bool isSquareMatrix() const;
	bool isSquareMatrix(const Matrix& Matr) const;
	bool isEquaSizelMatrix(const Matrix& Matr1, const Matrix& Matr2) const;
	bool isEqualColRow(const Matrix& Matr1, const Matrix& Matr2) const;
	bool isOutOfRange(const Matrix& Matr1, int n, int m) const;
	double Detr() const;
	std::vector<double>& operator [](unsigned r);
	const std::vector<double>& operator [](const unsigned r) const;

};

//class Vector : std::vector<double>
//{
//private:
//	void std::vector<double>::resize(size_t _Newsize);
//};