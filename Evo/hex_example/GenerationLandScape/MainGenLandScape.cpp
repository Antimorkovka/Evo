#include "GenHeader.h"
#include <random>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
vector <vector <double>> fieldL;

int MainGenLandScape::StartGeneretionLandscape() {
	srand(MainGenLandScape::seed);
	MainGenLandScape::field[0][0] = rand()%5;
	MainGenLandScape::field[length-1][0] = rand()%5;
	MainGenLandScape::field[0][width - 1] = rand()%5;
	MainGenLandScape::field[length - 1][width - 1] = rand()%5;
	fieldL = MainGenLandScape::field;
	MainGenLandScape::Coords beginK = {0,0,MainGenLandScape::length - 1,0,MainGenLandScape::length - 1,MainGenLandScape::width - 1,0,MainGenLandScape::width - 1};
	MainGenLandScape::GenerateHeights(beginK);
	for (int i = 0; i < length;++i) {
		for (int j = 0; j < width;++j) {
			cout << round(fieldL[i][j]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
//calculate the value of related points
// CoordsOfRectangle
void MainGenLandScape::GenerateHeights(MainGenLandScape::Coords cOf�) {
	if ((cOf�.rbX - cOf�.lbX) <= 1 && (cOf�.lbY - cOf�.ltY) <= 1) return;
	MainGenLandScape::ValueOfStep(cOf�.lbX, cOf�.ltX, cOf�.lbY, cOf�.ltY);
	MainGenLandScape::ValueOfStep(cOf�.ltX, cOf�.rtX, cOf�.ltY, cOf�.rtY);
	MainGenLandScape::ValueOfStep(cOf�.rtX, cOf�.rbX, cOf�.rtY, cOf�.rbY);
	MainGenLandScape::ValueOfStep(cOf�.lbX, cOf�.rbX, cOf�.lbY, cOf�.rbY);
	MainGenLandScape::ValueOfStep(cOf�.lbX, cOf�.ltX, cOf�.rbX, cOf�.rtX, cOf�.lbY, cOf�.ltY, cOf�.rbY, cOf�.rtY);
	int xl = MainGenLandScape::Value(cOf�.lbX, cOf�.ltX);
	int yl = MainGenLandScape::Value(cOf�.lbY, cOf�.ltY);
	int xt = MainGenLandScape::Value(cOf�.ltX, cOf�.rtX);
	int yt = MainGenLandScape::Value(cOf�.ltY, cOf�.rtY);
	int xr = MainGenLandScape::Value(cOf�.rtX, cOf�.rbX);
	int yr = MainGenLandScape::Value(cOf�.rtY, cOf�.rbY);
	int xb = MainGenLandScape::Value(cOf�.lbX, cOf�.rbX);
	int yb = MainGenLandScape::Value(cOf�.lbY, cOf�.rbY);
	int xm = MainGenLandScape::Value(cOf�.lbX, cOf�.ltX, cOf�.rbX, cOf�.rtX);
	int ym = MainGenLandScape::Value(cOf�.lbY, cOf�.ltY, cOf�.rbY, cOf�.rtY);
	Coords Lt = { cOf�.ltX, cOf�.ltY, xt, yt, xm, ym, xl, yl };
	Coords Rt = { xt, yt, cOf�.rtX, cOf�.rtY, xr, yr, xm, ym };
	Coords Rb = { xm, ym, xr, yr, cOf�.rbX, cOf�.rbY, xb, yb };
	Coords Lb = { xl, yl, xm, ym, xb, yb, cOf�.lbX, cOf�.lbY };
	MainGenLandScape::GenerateHeights(Lt);
	MainGenLandScape::GenerateHeights(Rt);
	MainGenLandScape::GenerateHeights(Rb);
	MainGenLandScape::GenerateHeights(Lb);
	return;
}

void MainGenLandScape::ValueOfStep(int x1, int x2, int y1, int y2) {
	int difference = max(abs(x1 - x2), abs(y1 - y2));
	double local = rand() % 2;
	double length = 0;
	length += round(MainGenLandScape::length);
	double c = 0;
	c += difference;
	local = 1.2*((rand()%difference)/c);
	if (rand() % 2 == 1) local *= -1;
	//Max Value Of Height
	double localHeight = Value(fieldL[x1][y1], fieldL[x2][y2]);
	if (local + localHeight >= 0) {
		if (local + localHeight <= 4) {
			fieldL[Value(x1, x2)][Value(y1, y2)] = localHeight+local;
		}
		else {
			fieldL[Value(x1, x2)][Value(y1, y2)] = 4;
		}
	}
	else {
		fieldL[Value(x1, x2)][Value(y1, y2)] = 0;
	}
}

void MainGenLandScape::ValueOfStep(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
	fieldL[Value(x1, x2, x3, x4)][Value(y1, y2, y3, y4)] = Value(fieldL[x1][y1], fieldL[x2][y2], fieldL[x3][y3], fieldL[x4][y4]);
}

int MainGenLandScape::Value(int a, int b) {
	return (a + b) / 2;
}
double MainGenLandScape::Value(double a, double b) {
	return (a + b) / 2;
}
int MainGenLandScape::Value(int a, int b, int c, int d) {
	return (a + b + c + d) / 4;
}

double MainGenLandScape::Value(double a, double b, double c, double d) {
	return (a + b + c + d) / 4;
}

/*int main(int argc, char **argv) {
	 int seed=0;
	/*random_device rd;
	seed_seq seq(seed, seed*10);
	mt19937 engine3(seq);
	uniform_int_distribution<int> dist(-5, 5);
	vector<int> v;
	while (seed != -1) {
		cin >> seed;
		
		srand(seed);
		cout << "Randomized with seed equal : " << seed;
		cout << '\n';
		for (int i = 0; i < 10;++i) {
			cout << rand() << ' ';
		}
		cout << '\n';
	}
	
}*/