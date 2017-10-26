#pragma once

#include "LinearAlgebraTools.h"

template<class T>
Matrix<T>::Matrix() {};

template<class T>
Matrix<T>::Matrix(T* data, int h, int w) {
	height = h;
	width = w;
	matrix = (T*)malloc(sizeof(T) * h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			matrix[i*w + j] = data[i*w + j];
		}
	}
}

template<class T>
Matrix<T>::~Matrix() {
}

template<class T>
void Matrix<T>::FreeAll() {
	free(matrix);
}

template<class T>
void Matrix<T>::init(int h, int w) {
	height = h;
	width = w;
	matrix = (T*)malloc(sizeof(T) * h * w);
}


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

void PrintMatrix(Matrix<double>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%f\t", A->matrix[offset]);
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

template<typename T>
void ScalarSubtract(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B) {
	if (A->height != B->height || A->width != B->width) {
		printf("Error when substracting two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return;
	}
	out->init(A->height, A->width);
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			out->matrix[offset] = A->matrix[offset] - B->matrix[offset];
			offset++;
		}
	}
}

template<typename T>
void MatrixMultiply(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B) {
	if (A->width != B->width) {
		printf("Error when multiplying two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return;
	}
	out->init(A->height, B->width);
	int sum = 0;
	int offset = 0;
	int offsetA = 0;
	int offsetB = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < B->width; w++) {
			offsetA = h * A->width;
			offsetB = w;
			sum = 0;
			for (int k = 0; k < A->width; k++) {
				sum += A->matrix[offsetA] * B->matrix[offsetB];
				offsetA += 1;
				offsetB += A->width;
			}
			out->matrix[offset] = sum;
			offset += 1;
		}
	}

}

template<class T, class S>
Matrix<T>* operator*(Matrix<T> &A, S b) {
	Matrix<T>* out = new Matrix<T>;
	out->init(A.height, A.width);
	int offset = 0;
	for (int h = 0; h < A.height; h++) {
		for (int w = 0; w < A.width; w++) {
			out->matrix[offset] = A.matrix[offset] * b;
			offset++;
		}
	}
	return out;
}

template<class T, class S>
Matrix<T>* operator*(S b, Matrix<T> &A) {
	Matrix<T>* out = new Matrix<T>;
	out->init(A.height, A.width);
	int offset = 0;
	for (int h = 0; h < A.height; h++) {
		for (int w = 0; w < A.width; w++) {
			out->matrix[offset] = A.matrix[offset] * b;
			offset++;
		}
	}
	return out;
}