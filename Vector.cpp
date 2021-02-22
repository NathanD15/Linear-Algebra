#include <iostream>
#include "Vector.h"

	Vector::Vector(double vv[], int s) {
		v = vv;
		size = s;
	}

	void Vector::print() {
		for (int i = 0; i < size; i++) {
			std::cout << v[i] << ", ";
		}
	}


	Vector Vector::operator * (double c) {
		double *newA = new double[size];
		for (int i = 0; i < this->size; i++) {
			newA[i] = v[i] * c;
		}
		return Vector(newA, size);
	}
	Vector Vector::operator + (Vector V) {
		double *newA = new double[size];
		for (int i = 0; i < size; i++) {
			newA[i] = this->v[i] + V.v[i];
		}
		return Vector(newA, size);
	}
	Vector Vector::operator - (Vector V) {
		return  Vector(v, size) + V * -1;
	}

	double Vector::operator * (Vector V) { //dot product
		double dot = 0;
		for (int i = 0; i < size; i++) {
			dot += v[i] * V.v[i];
		}
		return dot;
	}
	Vector Vector::operator / (Vector V) { //cross product
		double *a = new double[3];
		a[0] = v[1] * V.v[2] - v[2] * V.v[1];
		a[1] = -(v[0] * V.v[2] - v[2] * V.v[0]);
		a[2] = v[0] * V.v[1] - v[1] * V.v[0];
		Vector newV(a, 3);
		return newV;
	}

