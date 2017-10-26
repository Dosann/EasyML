#include "LinearAlgebraTools.h"

void PrintMatrix(Matrix<float>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%f\t", A->matrix[offset]);
			offset++;
		}
		printf("\n");
	}
}

void PrintMatrix(Matrix<int>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%d\t", A->matrix[offset]);
			offset++;
		}
		printf("\n");
	}
}

template<typename T>
void ScalarAdd(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B) {
	if (A->height != B->height || A->width != B->width) {
		printf("Error when adding two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return;
	}
	out->init(A->height, A->width);
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			out->matrix[offset] = A->matrix[offset] + B->matrix[offset];
			offset++;
		}
	}
}