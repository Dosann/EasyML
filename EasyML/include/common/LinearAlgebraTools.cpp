#include "LinearAlgebraTools.h"

template<T>
int* GetMatrixSize(T[][] A){
	int width, height, total;
	total = sizeof(A) / sizeof(T);
	width = sizeof(A[0]) / sizeof(T);
	height = total / width;
	return{ height, width };
}

template<T>
void ScalarAdd(T[][] out, T[][] A, T[][] B){
	int* asize = GetMatrixSize(A);
	int* bsize = GetMatrixSize(B);
	if (asize[0] != bsize[0] || asize[1] != bsize[1]) {
		printf("Error when adding two matrix(%d by %d, %d by %d): dimension not matched!\n", asize[0], asize[1], bsize[0], bsize[1]);
		return;
	}
	out = new T[asize[0]][asize[1]];
	for (int height = 0; height < asize[0]; height++) {
		for (int width = 0; width < asize[1]; width++) {
			out[height][width] = A[height][width] + B[height][width];
		}
	}
}

template<T>
void ScalarSubtract(T[][] out, T[][] A, T[][] B)
{
	int* asize = GetMatrixSize(A);
	int* bsize = GetMatrixSize(B);
	if (asize[0] != bsize[0] || asize[1] != bsize[1]) {
		printf("Error when substracting two matrix(%d by %d, %d by %d): dimension not matched!\n", asize[0], asize[1], bsize[0], bsize[1]);
		return;
	}
	out = new T[asize[0]][asize[1]];
	for (int height = 0; height < asize[0]; height++) {
		for (int width = 0; width < asize[1]; width++) {
			out[height][width] = A[height][width] - B[height][width];
		}
	}
}

template<T>
void ScalarMultiply(T[][] out, T[][] A, T[][] B)
{
	int* asize = GetMatrixSize(A);
	int* bsize = GetMatrixSize(B);
	if (asize[1] != bsize[0]) {
		printf("Error when multiplying two matrix(%d by %d, %d by %d): dimension not matched!\n", asize[0], asize[1], bsize[0], bsize[1]);
		return;
	}
	out = new T[asize[0]][bsize[1]];
	for (int height = 0; height < asize[0]; height++) {
		for (int width = 0; width < bsize[1]; width++) {
			int temp = 0;
			for (int i = 0; i < asize[1]; i++) {
				temp += A[height][i] * B[i][width];
			}
			out[height][width] = temp;
		}
	}
}

void PrintMatrixInt(int[][] A)
{
	int* asize = GetMatrixSize(A);
	for (int height = 0; height < asize[0]; height++) {
		for (int width = 0; width < asize[1]; width++) {
			printf("%d\t", A[height][width])
		}
		printf("\n");
	}
}

void PrintMatrixFloat(float[][] A)
{
	int* asize = GetMatrixSize(A);
	for (int height = 0; height < asize[0]; height++) {
		for (int width = 0; width < asize[1]; width++) {
			printf("%f\t", A[height][width])
		}
		printf("\n");
	}
}