#pragma once
#include <iostream>
#include "Vector.h"

class Matrix {
public:
	double **m;
	int row;
	int col;

	Matrix(double a[2][2]);
	Matrix(double a[3][3]);
	Matrix(double** a, int c, int r);

	void print();

	Matrix operator * (double c);
	Matrix operator + (Matrix ma);
	Matrix operator - (Matrix ma);
	Matrix operator * (Matrix ma);
	Matrix operator ^ (double c);
	Vector operator * (Vector V);

};