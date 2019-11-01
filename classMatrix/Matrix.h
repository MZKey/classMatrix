#pragma once

#include <vector>

typedef std::vector<std::vector<double>> matrix;

class Matrix
{
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	~Matrix();

	void fillRandValue();
	void fillRandValue(int limitL, int limitH);
	void Inverse();
	void Transpose();

	matrix add(const matrix& Matr) const;
	matrix sub(const matrix& Matr) const;
	matrix div(const matrix& Matr) const;
	matrix mul(const matrix& Matr) const;

	matrix operator + (const matrix& Matr2) const;
	matrix operator - (const matrix& Matr2) const;
	matrix operator * (const matrix& Matr2) const;
	matrix operator * (double number);
	matrix operator += (const matrix& Matr2);
	matrix operator -= (const matrix& Matr2);
	matrix operator *= (const matrix& Matr2);
	matrix operator /= (const matrix& Matr2);
	bool operator == (const matrix& Matr2) const;
	std::vector<double>& operator [](unsigned r);
private:
	matrix Matr;
};

