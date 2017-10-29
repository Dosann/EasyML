#include "common/LinearAlgebraTools.h"
//#include "LinearAlgebraTools.cpp"
#include <iostream>

int main()
{
	float Adata[9] = { 1,2,3, 2,4,6, 7,4,1 };
	float Bdata[9] = { 7,6,5, 5,4,3, 1,7,13 };

	printf("开始测试矩阵运算: \n");
	Matrix<float> A(Adata, 3, 3);
	Matrix<float> B(Bdata, 3, 3);
	printf("矩阵A: \n");
	Matrix<int>::Print(&A);
	printf("矩阵B: \n");
	Matrix<int>::Print(&B);
	printf("矩阵C: \n");
	Matrix<float>* C = Matrix<float>::ScalarAdd(&A, &B);
	Matrix<int>::Print(C);

	printf("矩阵D: \n");
	Matrix<float>* D = Matrix<float>::ScalarSubtract(&A, &B);
	Matrix<int>::Print(D);

	printf("矩阵E: \n");
	Matrix<float>* E = Matrix<float>::MatrixMultiply(&A, &B);
	Matrix<int>::Print(E);

	int b = 10;
	Matrix<float>* F = A * b;
	printf("矩阵F: \n");
	Matrix<int>::Print(F);
	F = b * A;
	printf("矩阵F: \n");
	Matrix<int>::Print(F);

	printf("\n");
	printf("开始测试向量运算: \n");
	int s1 = sizeof(Adata);
	Vector<float> vA(Adata, sizeof(Adata)/sizeof(Adata[0]), COL);
	Vector<float> vB(Bdata, sizeof(Bdata)/sizeof(Bdata[0]), COL);
	Vector<float>* vC = Vector<float>::ScalarAdd(&vA, &vB);
	Vector<float>* vD = Vector<float>::ScalarSubtract(&vA, &vB);
	float ip = Vector<float>::InnerProduct(&vA, &vB);
	Matrix<float>* vE = Vector<float>::VectorSpan(&vA, vB.Transpose());
	printf("向量vA: \n");
	Vector<int>::Print(&vA);
	printf("向量vB: \n");
	Vector<int>::Print(&vB);
	printf("向量vC: \n");
	Vector<int>::Print(vC);
	printf("向量vD: \n");
	Vector<int>::Print(vD);
	printf("矩阵vE: \n");
	Matrix<int>::Print(vE);



	std::cin.get();
}