#pragma once

#include "LinearAlgebraTools.h"

#pragma region
template<class T> Vector<T>::Vector() {};

template<class T> Vector<T>::Vector(T* data, int l) {
	len = l;
	vector = new T[len];
	for (int i = 0; i < len; i++) {
		vector[i] = data[i];
	}
}
template<class T> Vector<T>::Vector(T* data, int l, VecDirection dir) {
	len = l;
	vector = new T[len];
	for (int i = 0; i < len; i++) {
		vector[i] = data[i];
	}
	vecd = dir;
}
template<class T> void Vector<T>::SetDirection(VecDirection dir) {
	vecd = dir;
}
template<class T> Vector<T>* Vector<T>::Transpose(bool inplace = false) {
	if (inplace) {
		vecd = vecd == ROW ? COL : ROW;
		return this;
	}
	else {
		Vector<T>* out = new Vector<T>(vector, len, vecd == ROW ? COL : ROW);
		return out;
	}
}
template<class T> Vector<T>* Vector<T>::ScalarAdd(Vector<T>* A, Vector<T>* B) {
	if (A->vecd != B->vecd || A->len != B->len) {
		printf("Error when adding two vectors: dimension not matched(%d in %d, %d in %d)\n", A->len, A->vecd, B->len, B->vecd);
		return NULL;
	}
	else {
		T* outarray = new T[A->len];
		for (int i = 0; i < A->len; i++) {
			outarray[i] = A->vector[i] + B->vector[i];
		}
		Vector<T>* out = new Vector<T>(outarray, A->len, A->vecd);
		delete[] outarray;
		return out;
	}
}
template<class T> Vector<T>* Vector<T>::ScalarSubtract(Vector<T>* A, Vector<T>* B) {
	if (A->vecd != B->vecd || A->len != B->len) {
		printf("Error when subtracting two vectors: dimension not matched(%d in %d, %d in %d)\n", A->len, A->vecd, B->len, B->vecd);
		return NULL;
	}
	else {
		T* outarray = new T[A->len];
		for (int i = 0; i < A->len; i++) {
			outarray[i] = A->vector[i] - B->vector[i];
		}
		Vector<T>* out = new Vector<T>(outarray, A->len, A->vecd);
		delete[] outarray;
		return out;
	}
}
template<class T> T Vector<T>::InnerProduct(Vector<T>* A, Vector<T>* B) {
	if (A->len != B->len) {
		printf("Error when innerproducting two vectors: dimension not matched(%d in %s, %d in %s)\n", A->len, A->vecd, B->len, B->vecd);
		return NULL;
	}
	else {
		T sum = 0;
		for (int i = 0; i < A->len; i++) {
			sum += A->vector[i] * B->vector[i];
		}
		return sum;
	}
}
template<class T> Matrix<T>* Vector<T>::VectorSpan(Vector<T>* A, Vector<T>* B) {
	if (A->vecd != COL || B->vecd != ROW) {
		printf("Error when spanning two vectors: dimension not matched(%d in %d, %d in %d)\n", A->len, A->vecd, B->len, B->vecd);
		return NULL;
	}
	else {
		Matrix<T>* out = new Matrix<T>();
		out->init(A->len, B->len);
		int offset = 0;
		for (int i = 0; i < A->len; i++) {
			for (int j = 0; j < B->len; j++) {
				out->matrix[offset] = A->vector[i] * B->vector[j];
				offset++;
			}
		}
		return out;
	}
}

template<class T> void Vector<T>::Print(Vector<float>* A) {
	switch (A->vecd) {
	case COL:
		for (int i = 0; i < A->len; i++) {
			printf("%f\n", A->vector[i]);
		} break;
	case ROW:
		for (int i = 0; i < A->len; i++) {
			printf("%f\t", A->vector[i]);
		} printf("\n"); break;
	}
}
template<class T> void Vector<T>::Print(Vector<int>* A) {
	switch (A->vecd) {
	case COL:
		for (int i = 0; i < A->len; i++) {
			printf("%d\n", A->vector[i]);
		} break;
	case ROW:
		for (int i = 0; i < A->len; i++) {
			printf("%d\t", A->vector[i]);
		} printf("\n"); break;
	}
}
template<class T> void Vector<T>::Print(Vector<double>* A) {
	switch (A->vecd) {
	case COL:
		for (int i = 0; i < A->len; i++) {
			printf("%f\n", A->vector[i]);
		} break;
	case ROW:
		for (int i = 0; i < A->len; i++) {
			printf("%f\t", A->vector[i]);
		} printf("\n"); break;
	}
}
#pragma endregion

#pragma region
// Matrix

template<class T> Matrix<T>::Matrix() {
	height = 0;
	width = 0;
};

template<class T> Matrix<T>::Matrix(T* data, int h, int w) {
	height = h;
	width = w;
	matrix = (T*)malloc(sizeof(T) * h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			matrix[i*w + j] = data[i*w + j];
		}
	}
}

template<class T> Matrix<T>::~Matrix() {
}

template<class T> void Matrix<T>::FreeAll() {
	free(matrix);
}

template<class T> void Matrix<T>::init(int h, int w) {
	height = h;
	width = w;
	matrix = (T*)malloc(sizeof(T) * h * w);
}


template<class T> void Matrix<T>::Print(Matrix<float>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%f\t", A->matrix[offset]);
			offset++;
		}
		printf("\n");
	}
}

template<class T> void Matrix<T>::Print(Matrix<int>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%d\t", A->matrix[offset]);
			offset++;
		}
		printf("\n");
	}
}

template<class T> void Matrix<T>::Print(Matrix<double>* A) {
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			printf("%f\t", A->matrix[offset]);
			offset++;
		}
		printf("\n");
	}
}

template<class T> Matrix<T>* Matrix<T>::ScalarAdd(Matrix<T>* A, Matrix<T>* B) {
	if (A->height != B->height || A->width != B->width) {
		printf("Error when adding two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return NULL;
	}
	Matrix<T>* out = new Matrix<T>();
	out->init(A->height, A->width);
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			out->matrix[offset] = A->matrix[offset] + B->matrix[offset];
			offset++;
		}
	}
	return out;
}

template<class T> Matrix<T>* Matrix<T>::ScalarSubtract(Matrix<T>* A, Matrix<T>* B) {
	if (A->height != B->height || A->width != B->width) {
		printf("Error when substracting two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return NULL;
	}
	Matrix<T>* out = new Matrix<T>();
	out->init(A->height, A->width);
	int offset = 0;
	for (int h = 0; h < A->height; h++) {
		for (int w = 0; w < A->width; w++) {
			out->matrix[offset] = A->matrix[offset] - B->matrix[offset];
			offset++;
		}
	}
	return out;
}

template<typename T> Matrix<T>* Matrix<T>::MatrixMultiply(Matrix<T>* A, Matrix<T>* B) {
	if (A->width != B->width) {
		printf("Error when multiplying two matrices: dimension not matched(%d by %d, %d by %d)\n", A->height, A->width, B->height, B->width);
		return NULL;
	}
	Matrix<T>* out = new Matrix<T>();
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
	return out;
}

template<class T, class S> Matrix<T>* operator*(Matrix<T> &A, S b) {
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

template<class T, class S> Matrix<T>* operator*(S b, Matrix<T> &A) {
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

#pragma endregion