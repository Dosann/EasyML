#pragma once

#include <stdio.h>
#include <stdlib.h>

template<typename T>
class Matrix {

public:
	T* matrix;
	int height = 0;
	int width = 0;

public:
	Matrix() {};

	Matrix(T* data, int h, int w) {
		height = h;
		width = w;
		matrix = (T*)malloc(sizeof(T) * h * w);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				matrix[i*w + j] = data[i*w + j];
			}
		}
	}

	~Matrix() {
		free(matrix);
	}

	void Matrix::init(int h, int w) {
		height = h;
		width = w;
		matrix = (T*)malloc(sizeof(T) * h * w);
	}
};

void PrintMatrix(Matrix<float>* A);

void PrintMatrix(Matrix<int>* A);

template<typename T>
void ScalarAdd(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B);

//template<typename T>
//void ScalarSubtract<T>(Matrix out, Matrix A, Matrix B);

//template<typename T>
//void ScalarMultiply<T>(Matrix out, Matrix A, Matrix B);
