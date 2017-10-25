#pragma once

template<T>
int* GetMatrixSize(T[][] A);

template<T>
void ScalarAdd(T[][] out, T[][] A, T[][] B);

template<T>
void ScalarSubtract(T[][] out, T[][] A, T[][] B);

template<T>
void ScalarMultiply(T[][] out, T[][] A, T[][] B);

void PrintMatrixInt(int A[][]);

void PrintMatrixFloat(float A[][]);