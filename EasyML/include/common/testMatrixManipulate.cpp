#include "common/LinearAlgebraTools.h"
//#include "LinearAlgebraTools.cpp"
#include <iostream>

int main()
{
	float Adata[9] = { 1,2,3, 2,4,6, 7,4,1 };
	float Bdata[9] = { 7,6,5, 5,4,3, 1,7,13 };

	printf("��ʼ���Ծ�������: \n");
	Matrix<float> A(Adata, 3, 3);
	Matrix<float> B(Bdata, 3, 3);
	Matrix<float> C;
	printf("����A: \n");
	Matrix<int>::Print(&A);
	printf("����B: \n");
	Matrix<int>::Print(&B);
	ScalarAdd(&C, &A, &B);
	printf("����C: \n");
	Matrix<int>::Print(&C);

	Matrix<float> D;
	ScalarSubtract(&D, &A, &B);
	printf("����D: \n");
	Matrix<int>::Print(&D);

	Matrix<float> E;
	MatrixMultiply(&E, &A, &B);
	printf("����E: \n");
	Matrix<int>::Print(&E);

	int b = 10;
	Matrix<float>* F = A * b;
	printf("����F: \n");
	Matrix<int>::Print(F);
	F = b * A;
	printf("����F: \n");
	Matrix<int>::Print(F);

	printf("\n");
	printf("��ʼ������������: \n");
	int s1 = sizeof(Adata);
	Vector<float> vA(Adata, sizeof(Adata)/sizeof(Adata[0]), COL);
	Vector<float> vB(Bdata, sizeof(Bdata)/sizeof(Bdata[0]), COL);
	Vector<float>* vC = Vector<float>::ScalarAdd(&vA, &vB);
	Vector<float>* vD = Vector<float>::ScalarSubtract(&vA, &vB);
	float ip = Vector<float>::InnerProduct(&vA, &vB);
	Matrix<float>* vE = Vector<float>::VectorSpan(&vA, vB.Transpose());
	printf("����vA: \n");
	Vector<int>::Print(&vA);
	printf("����vB: \n");
	Vector<int>::Print(vB.Transpose());
	printf("����vC: \n");
	Vector<int>::Print(vC);
	printf("����vD: \n");
	Vector<int>::Print(vD);
	printf("����vE: \n");
	Matrix<int>::Print(vE);



	std::cin.get();
}