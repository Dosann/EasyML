#include "LinearAlgebraTools.h"
#include <iostream>

int main()
{
	float A[3][3] = { {1,2,3}, {2,4,6}, {7,4,1} };
	float B[3][3] = { {7,6,5}, {5,4,3}, {1,7,13} };
	float C[3][3];
	PrintMatrixFloat(A);
	PrintMatrixFloat(B);

	std::cin.get();
}