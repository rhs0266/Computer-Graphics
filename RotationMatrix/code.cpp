#include <stdio.h>
#include <iostream>
#include <math.h>
const double M_PI = atan2(0, -1);
using namespace std;
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
void id(double mat[3][3]) {
	FOR(i, 0, 2) FOR(j, 0, 2) mat[i][j] = 0;
	FOR(i, 0, 2) mat[i][i] = 1;
}
void rotateT(double t,double mat[3][3]) { // t : degree
	id(mat);
	t = t * M_PI / 180.0;
	mat[0][0] = cos(t);
	mat[0][1] = -sin(t);
	mat[1][0] = sin(t);
	mat[1][1] = cos(t);
}
void translate(double x, double y, double mat[3][3]) {
	id(mat);
	mat[0][2] = x;
	mat[1][2] = y;
}
void multRR(double A[3][3], double B[3][3], double C[3][3]) {
	double res[3][3];
	FOR(i, 0, 2) FOR(j, 0, 2) res[i][j] = 0;
	FOR(i, 0, 2) FOR(j, 0, 2) FOR(k, 0, 2) res[i][j] += A[i][k] * B[k][j];
	FOR(i, 0, 2) FOR(j, 0, 2) C[i][j] = res[i][j];
}
void multRP(double A[3][3], double B[3][1], double C[3][1]) {
	double res[3][1];
	FOR(i, 0, 2) FOR(j, 0, 0) res[i][j] = 0;
	FOR(i, 0, 2) FOR(j, 0, 0) FOR(k, 0, 2) res[i][j] += A[i][k] * B[k][j];
	FOR(i, 0, 2) FOR(j, 0, 0) C[i][j] = res[i][j];
}
void printR(double a[3][3]) {
	FOR(i, 0, 2) {
		FOR(j, 0, 2) cout << a[i][j] << " ";
		cout << endl;
	}
}
void pro() {
	double R[3][3], res[3][3];
	double P[3][1];
	id(res);
	translate(10, 0, R);
	multRR(R, res, res);
	rotateT(30, R);
	multRR(R, res, res);
	translate(20, 0, R);
	multRR(R, res, res);
	rotateT(60, R);
	multRR(R, res, res);
	printR(res);

	// result : (10, 27.3205)
}
int main() {
	pro();
	return 0;
}