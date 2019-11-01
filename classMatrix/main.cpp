#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	double chislo;
	Matrix matr(5,5);
	matr.fillRandValue();
	chislo = matr[3][3];
	cout << chislo << endl;

	matr[3][3] = 5;
	chislo = matr[3][3];
	cout << chislo << endl;

	return 0;
}