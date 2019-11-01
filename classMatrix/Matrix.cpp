#include "Matrix.h"



Matrix::Matrix()
{
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
