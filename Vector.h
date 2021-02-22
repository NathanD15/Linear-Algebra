#pragma once
class Vector {
public:
	double *v = new double[3];
	int size = 0;
	Vector(double vv[], int s);

	void print();


	Vector operator * (double c);
	Vector operator + (Vector V);
	Vector operator - (Vector V);
	double operator * (Vector V); //dot product
	Vector operator / (Vector V); //cross product

};