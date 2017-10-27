#pragma once
#include <stdio.h>
#include <stdlib.h>

enum VecDirection { COL, ROW };

template<class T> class Vector;
template<class T> class Matrix;

template<class T>
class Vector {
public:
	T* vector;
	int len;
	VecDirection vecd;

public:
	Vector(T* data, int l);
	Vector(T* data, int l, VecDirection d);
	Vector();
	void SetDirection(VecDirection d);
	Vector* Transpose();

public:
	static Vector* ScalarAdd(Vector* A, Vector* B);
	static Vector* ScalarSubtract(Vector* A, Vector* B);
	static T InnerProduct(Vector* A, Vector* B);
	static Matrix<T>* VectorSpan(Vector* A, Vector* B);
	static void Print(Vector<float>* A);
	static void Print(Vector<int>* A);
	static void Print(Vector<double>* A);
};

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
public:
	static void Print(Matrix<float>* A);
	static void Print(Matrix<int>* A);
	static void Print(Matrix<double>* A);
};


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