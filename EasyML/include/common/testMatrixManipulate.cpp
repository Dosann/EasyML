#include "common/LinearAlgebraTools.h"
//#include "LinearAlgebraTools.cpp"
#include <iostream>

int main()
{
	float Adata[9] = { 1,2,3, 2,4,6, 7,4,1 };
	Matrix<float> A(Adata, 3, 3);
	float Bdata[9] = { 7,6,5, 5,4,3, 1,7,13 };
	Matrix<float> B(Bdata, 3, 3);
	Matrix<float> C;
	printf("¾ØÕóA: \n");
	PrintMatrix(&A);
	printf("¾ØÕóB: \n");
	PrintMatrix(&B);
	ScalarAdd(&C, &A, &B);
	printf("¾ØÕóC: \n");
	PrintMatrix(&C);

	Matrix<float> D;
	ScalarSubtract(&D, &A, &B);
	printf("¾ØÕóD: \n");
	PrintMatrix(&D);

	Matrix<float> E;
	MatrixMultiply(&E, &A, &B);
	printf("¾ØÕóE: \n");
	PrintMatrix(&E);

	int b = 10;
	Matrix<float>* F = A * b;
	printf("¾ØÕóF: \n");
	PrintMatrix(F);
	F = b * A;
	printf("¾ØÕóF: \n");
	PrintMatrix(F);

	std::cin.get();
}