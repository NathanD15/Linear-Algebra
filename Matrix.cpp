#include "Matrix.h"


	Matrix::Matrix(double a[2][2]) {
		row = 2; col = 2;
		m = new double*[col];
		for (int i = 0; i < 2; i++) {
			m[i] = new double[2];
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				m[i][j] = a[i][j];
			}
		}
	}

	Matrix::Matrix(double a[3][3]) {
		row = 3; col = 3;
		m = new double*[col];
		for (int i = 0; i < 3; i++) {
			m[i] = new double[3];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				m[i][j] = a[i][j];
			}
		}
	}

	Matrix::Matrix(double** a, int c, int r) {
		row = r; col = c;
		m = new double*[col];
		for (int i = 0; i < col; i++) {
			m[i] = new double[row];
		}
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				m[i][j] = a[i][j];
			}
		}
	}

	void Matrix::print() {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				std::cout << m[i][j] << ", ";
			}
			std::cout << std::endl;
		}
	}

	Matrix Matrix::operator * (double c) {
		double **newm = new double*[col];
		for (int i = 0; i < col; i++) {
			newm[i] = new double[row];
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				newm[i][j] = m[i][j] * c;
			}
		}

		return Matrix(newm, col, row);
	}

	Matrix Matrix::operator + (Matrix ma) {
		double **newm = new double*[col];
		for (int i = 0; i < col; i++) {
			newm[i] = new double[row];
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				newm[i][j] = m[i][j] + ma.m[i][j];
			}
		}

		return Matrix(newm, col, row);
	}
	Matrix Matrix::operator - (Matrix ma) {
		return Matrix(m, col, row) + (ma*-1);
	}
	Matrix Matrix::operator * (Matrix ma) {
		double **newm = new double*[col];
		for (int i = 0; i < col; i++) {
			newm[i] = new double[row];
		}

		for (int c = 0; c < col; c++) {
			for (int r = 0; r < row; r++) {
				newm[r][c] = 0;
				for (int n = 0; n < col; n++) {
					newm[r][c] += m[r][n] * ma.m[n][c];
				}
			}
		}

		return Matrix(newm, col, row);
	}
	Matrix Matrix::operator ^ (double c) {
		Matrix ma(m, col, row);
		for (int i = 0; i < c - 1; i++) {
			ma = ma * Matrix(m, col, row);;
		}
		return ma;
	}

	Vector Matrix::operator * (Vector V) {
		double *a = new double[V.size];

		for (int i = 0; i < V.size; i++) {
			a[i] = 0;
			for (int c = 0; c < col; c++) {
				a[i] += V.v[c] * m[i][c];
			}
		}

		return Vector(a, 3);
	}
