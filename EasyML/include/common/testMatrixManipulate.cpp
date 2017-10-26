#include "LinearAlgebraTools.h"
#include <iostream>

int main()
{
	float Adata[9] = { 1,2,3, 2,4,6, 7,4,1 };
	Matrix<float> A(Adata, 3, 3);
	float Bdata[9] = { 7,6,5, 5,4,3, 1,7,13 };
	Matrix<float> B(Bdata, 3, 3);
	Matrix<float> C;
	printf("����A: \n");
	PrintMatrix(&A);
	printf("����B: \n");
	PrintMatrix(&B);
	ScalarAdd(&C, &A, &B);
	printf("����C: \n");
	PrintMatrix(&C);

	std::cin.get();
}