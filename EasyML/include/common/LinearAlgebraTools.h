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
	Matrix();
	Matrix(T* data, int h, int w);
	~Matrix();

	void FreeAll();

	void init(int h, int w);
};

void PrintMatrix(Matrix<float>* A);

void PrintMatrix(Matrix<int>* A);

template<typename T>
void ScalarAdd(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B);

template<typename T>
void ScalarSubtract(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B);

template<typename T>
void MatrixMultiply(Matrix<T>* out, Matrix<T>* A, Matrix<T>* B);

template<class T, class S>
Matrix<T>* operator*(Matrix<T> &A, S b);

template<class T, class S>
Matrix<T>* operator*(S b, Matrix<T> &A);





#include "LinearAlgebraTools_imple.h"