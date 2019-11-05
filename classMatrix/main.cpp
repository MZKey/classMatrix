#include <iostream>
#include "Matrix.h"

using namespace std;

void printMatrix(const Matrix& matr)
{
	for (unsigned i = 0; i < matr.size(); i++)
	{
		for (unsigned j = 0; j < matr[i].size(); j++)
		{
			cout.width(3);
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Matrix matr(3, 3);
	matr.fillRandValue(-10, 25);
	printMatrix(matr);
	cout << endl;
	cout << matr.Detr() << endl;

	
	matr(2, 2) = 5;
	printMatrix(matr);

	//Matrix matr(2, 3);
	//Matrix matr2(3, 2);
	//matr.fillRandValue(1, 5);
	//matr2.fillRandValue(1, 5);
	////matr2 = matr;

	//Matrix matr3 = matr * matr2;
	//printMatrix(matr);
	//cout << endl;
	//printMatrix(matr2);
	//cout << endl;
	//printMatrix(matr3);
	//cout << endl;

	//Matrix matr4({ {2,3,5},{5,2} });
	//printMatrix(matr4);
	//cout << endl;
	//matr4.transposeSelf();
	//printMatrix(matr4);
	//cout << endl;
	//Matrix matr5 = matr4.transpose();
	//printMatrix(matr5);
	//matr5[1][2] = 5;
	//matr5[1].resize(2);
	//cout << endl;
	//printMatrix(matr5);

	//Matrix matr6({
	//	{5,3,1},
	//	{3,-1,2},
	//	{1,-3,-6}
	//	});
	//double deter = matr6.Detr();
	//cout << endl;
	//printMatrix(matr6);
	//cout << endl;
	//cout << deter << endl;
	/*Matrix matr5(5);
	printMatrix(matr5);*/
	//matr2.fillRandValue();
	//if (matr == matr2) cout << "Equal" << endl;
	//else cout << "Not equal" << endl;
	//matr.fillRandValue();
	//matr2 = matr;
	//printMatrix(matr);
	//printMatrix(matr2);
	////cout << chislo << endl;
	//cout << endl;
	//
	//matr[3][3] = 5;
	//printMatrix(matr);
	////chislo = matr[3][3];

	return 0;
}