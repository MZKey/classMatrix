#include "Matrix.h"



Matrix::Matrix()
{
}

Matrix::Matrix(unsigned n)
{
	Matr.resize(n);
	for (unsigned i = 0; i < n; i++)
		Matr[i].resize(n);
}

Matrix::Matrix(unsigned n, unsigned m)
{
	Matr.resize(n);
	for (unsigned i = 0; i < n; i++)
		Matr[i].resize(m);
}

Matrix::Matrix(const matrix m)
{
	Matr.resize(m.size());
	unsigned mj = 0;
	for (unsigned i = 0; i < m.size(); i++)
		if (m[i].size() > mj) mj = unsigned(m[i].size());

	for (unsigned i = 0; i < Matr.size(); i++)
	{
		Matr[i].resize(mj);
		for (unsigned j = 0; j < m[i].size(); j++)
			Matr[i][j] = m[i][j];
	}
}

Matrix::~Matrix()
{
}

unsigned Matrix::getN() const
{
	return unsigned(Matr.size());
}

unsigned Matrix::getM() const
{
	return unsigned(Matr[0].size());
}

void Matrix::setN(unsigned n)
{
	Matr.resize(n);
}

void Matrix::setM(unsigned m)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		Matr[i].resize(m);
}

unsigned Matrix::size() const
{
	return unsigned(Matr.size());
}

void Matrix::resize(unsigned n)
{
	this->resize(n, n);
}

void Matrix::resize(unsigned n, unsigned m)
{
	Matr.resize(n);
	for (unsigned i = 0; i < Matr.size(); i++)
		Matr[i].resize(m);
}

void Matrix::fillRandValue()
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = rand();
}

void Matrix::fillRandValue(int limitL, int limitH)
{
	srand(time(NULL));
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = limitL + rand() % (limitH - limitL + 1);
}

void Matrix::fillFixValue(double value)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = value;
}

void Matrix::transposeSelf()
{
	Matrix Result(unsigned(Matr[0].size()), unsigned(Matr.size()));
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Result[j][i] = Matr[i][j];

	*this = Result;
}

Matrix Matrix::transpose() const
{
	Matrix Result(unsigned(Matr[0].size()), unsigned(Matr.size()));
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Result[j][i] = Matr[i][j];

	return Result;
}

void Matrix::add(const Matrix& Matr2)
{
	
	*this = *this + Matr;
}

void Matrix::sub(const Matrix& Matr)
{
	*this = *this - Matr;
}

void Matrix::mul(const Matrix& Matr)
{
	*this = *this * Matr;
}

void Matrix::div(const double number)
{
	*this = *this / number;
}

std::vector<double>& Matrix::operator[](unsigned index)
{
	return this->Matr[index];
}

const std::vector<double>& Matrix::operator[](const unsigned index) const
{
	return this->Matr[index];
}

double & Matrix::operator()(unsigned r, unsigned c)
{
	return this->Matr[r][c];
}

const double & Matrix::operator()(unsigned r, unsigned c) const
{
	return this->Matr[r][c];
}

Matrix Matrix::operator+(const Matrix& Matr2) const
{
	if (isEquaSizelMatrix(*this, Matr2))
	{
		Matrix Result = *this;
		for (unsigned i = 0; i < Result.size(); i++)
			for (unsigned j = 0; j < Result[i].size(); j++)
				Result[i][j] += Matr2[i][j];

		return Result;
	}
	return Matrix();
}

Matrix Matrix::operator-(const Matrix & Matr2) const
{
	if (isEquaSizelMatrix(*this, Matr2))
	{
		Matrix Result = *this;
		for (unsigned i = 0; i < Result.size(); i++)
			for (unsigned j = 0; j < Result[i].size(); j++)
				Result[i][j] -= Matr2[i][j];

		return Result;
	}
	return Matrix();
}

Matrix Matrix::operator/(double number) const
{
	if (number != 0) 
	{
		Matrix Result = *this;
		for (unsigned i = 0; i < Result.size(); i++)
			for (unsigned j = 0; j < Result[i].size(); j++)
				Result[i][j] /= number;
		return Result;
	}
}

Matrix Matrix::operator*(const Matrix& Matr2) const
{
	if (isEqualColRow(*this, Matr2))
	{
		Matrix Result(unsigned(this->Matr.size()), unsigned(Matr2[0].size()));
		for (unsigned i = 0; i < Matr.size(); i++)
			for (unsigned j = 0; j < Matr2[0].size(); j++)
				for (unsigned k = 0; k < Matr2.size(); k++)
					Result[i][j] += Matr[i][k] * Matr2[k][j];

		return Result;
	}
	return Matrix();
}

Matrix Matrix::operator*(double number) const
{
	Matrix Result = *this;
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Result[i][j] = Matr[i][j] * number;

	return Result;
}

void Matrix::operator+=(const Matrix& Matr2)
{
	if (isEquaSizelMatrix(*this, Matr2))
	{
		for (unsigned i = 0; i < this->Matr.size(); i++)
			for (unsigned j = 0; j < this->Matr[i].size(); j++)
				this->Matr[i][j] += Matr2[i][j];
	}
}

void Matrix::operator-=(const Matrix& Matr2)
{
	if (isEquaSizelMatrix(*this, Matr2))
	{
		*this = *this - Matr2;
	}
}

void Matrix::operator*=(const Matrix& Matr2)
{
	if (isEqualColRow(*this, Matr2))
	{
		*this = *this * Matr2;
	}
}

void Matrix::operator/=(const double number)
{
	*this = *this / number;
}

bool Matrix::operator==(const Matrix& Matr2) const
{
	if (isEquaSizelMatrix(*this, Matr2))
	{
		for (unsigned i = 0; i < this->Matr.size(); i++)
			for (unsigned j = 0; j < Matr[i].size(); j++)
				if (Matr[i][j] != Matr2[i][j]) return false;

		return true;
	} else return false;
}

bool Matrix::operator!=(const Matrix& Matr2) const
{
	return Matr == Matr ? false : true;
}

bool Matrix::isSquareMatrix() const
{
	for (unsigned i = 0; i < Matr.size(); i++)
		if (Matr.size() != Matr[i].size()) return false;
	return true;
}

bool Matrix::isSquareMatrix(const Matrix& Matr) const
{
	return Matr.isSquareMatrix();
}

bool Matrix::isEquaSizelMatrix(const Matrix& Matr1, const Matrix& Matr2) const
{
	if (Matr1.size() != Matr2.size()) return false;
	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr2[i].size()) return false;
	return true;
}

bool Matrix::isEqualColRow(const Matrix & Matr1, const Matrix & Matr2) const
{
	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr2.size()) return false;
	for (unsigned i = 0; i < Matr2.size(); i++)
		if (Matr1.size() != Matr2[i].size()) return false;
	return true;
}

bool Matrix::isOutOfRange(const Matrix& Matr1, int n, int m) const
{
	return ((n >= 0 && n <= Matr1.size()) && (m >= 0 && m <= Matr1[n].size())) ? true : false;
}

double Matrix::Detr() const
{
	//if (!isSquareMatrix(Matr)) throw NotSquareMatric;

	if (Matr.size() == 1) return Matr[0][0];
	if (Matr.size() == 2) return Detr(Matr);

	double Determinate = 0;
	for (unsigned i = 0; i < Matr[0].size(); i++)
		Determinate += Detr(Matr, 0, i);

	return Determinate;
}

double Matrix::Detr(const Matrix& M, unsigned Row, unsigned Col) const
{
	Matrix Minor;
	Minor.resize(M.size() - 1);
	for (unsigned i = 0; i < Minor.size(); i++)
		Minor[i].resize(M[i].size() - 1);


	unsigned i1 = 0, j1 = 0;
	for (unsigned i = 0; i < M.size(); i++)
	{
		if (i == Row) continue;
		for (unsigned j = 0; j < M[i].size(); j++)
		{
			if (j == Col) continue;
			Minor[i1][j1] = M[i][j];
			j1++;
		}
		i1++;
		j1 = 0;
	}


	if (Minor.size() == 2) return (pow(-1, Row + Col) * M[Row][Col]) * Detr(Minor);


	double Determinate = 0;
	for (unsigned i = 0; i < Minor[0].size(); i++)
		Determinate += (pow(-1, Row + Col) * M[Row][Col]) * Detr(Minor, 0, i);
	return Determinate;
}

double Matrix::Detr(const Matrix& M) const
{
	return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
}

Matrix operator*(double number, const Matrix& Matr)
{
	return Matrix() = Matr * number;
}
