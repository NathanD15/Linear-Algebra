#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;


int main()
{
	double i[][3] = { {1, 0, 0},
					{ 0, 1, 0},
					{ 0, 0, 1} };
	double m[][3] = {{0, 1, 0},
					{ 1, 0, 0},
					{ 0, 0, 0} };

	double m2[][3] ={{-1,2, 0},
					{ 0, 1, 0},
					{ 0, 0, 0} };


	Matrix matrix1(m);
	Matrix matrix2(m2);
	Matrix neo = matrix1 * matrix2;

	double a[3] = { 1, 0, 0 };
	Vector v(a, 3);

	neo.print();
	cout << endl << endl;
	(neo *v).print();
	cout << endl;
	return 0;
}
