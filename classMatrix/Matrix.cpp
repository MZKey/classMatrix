#include "Matrix.h"



Matrix::Matrix()
{
}

Matrix::Matrix(unsigned rc)
{
	Matr.resize(rc);
	for (unsigned i = 0; i < rc; i++)
		Matr[i].resize(rc);
}

Matrix::Matrix(unsigned rows, unsigned columns)
{
	Matr.resize(rows);
	for (unsigned i = 0; i < rows; i++)
	{
		Matr[i].resize(columns);
	}
}


Matrix::~Matrix()
{
}

void Matrix::fillRandValue()
{
	for (unsigned i = 0; i < Matr.size(); i++)
	{
		for (unsigned j = 0; j < Matr[i].size(); j++)
		{
			Matr[i][j] = rand();
		}
	}
}

std::vector<double>& Matrix::operator[](unsigned r)
{
	return this->Matr[r];
}

matrix Matrix::operator+(const matrix& Matr2) const
{
	if (isEqualMatrix(this->Matr, Matr2))
	{
		matrix Result = this->Matr;
		for (unsigned i = 0; i < Result.size(); i++)
		{
			for (unsigned j = 0; j < Result[i].size(); j++)
			{
				Result[i][j] += Matr2[i][j];
			}
		}
		return Result;
	}
}

matrix Matrix::operator-(const matrix & Matr2) const
{
	if (isEqualMatrix(this->Matr, Matr2))
	{
		matrix Result = this->Matr;
		for (unsigned i = 0; i < Result.size(); i++)
		{
			for (unsigned j = 0; j < Result[i].size(); j++)
			{
				Result[i][j] -= Matr2[i][j];
			}
		}
		return Result;
	}
}

bool Matrix::operator==(const matrix & Matr2) const
{
	if (isEqualMatrix(this->Matr, Matr2))
	{
		for (unsigned i = 0; i < this->Matr.size(); i++)
		{
			for (unsigned j = 0; j < Matr[i].size(); j++)
			{
				if (Matr[i][j] != Matr2[i][j]) return false;
			}
		}
		return true;
	} else return false;
}

bool Matrix::isEqualMatrix(const matrix& Matr1, const matrix& Matr2) const
{
	if (Matr1.size() != Matr2.size()) return false;

	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr2[i].size()) return false;

	return true;
}

bool Matrix::isEqualRowCol(const matrix & Matr1, const matrix & Matr2) const
{
	return false;
}
