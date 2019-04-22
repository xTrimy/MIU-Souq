#include "stdafx.h"
#include "Shapes.h"
std::ofstream file("img.pgm");

void Shapes::rect(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i >= x && i < x + sx && j >= y && j < y + sy) {
				X[i][j][0] = fillR;
				X[i][j][1] = fillG;
				X[i][j][2] = fillB;
			}
		}
	}
}
void Shapes::rectStroke(int x, int y, int sx, int sy) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

		}
	}
}
void Shapes::circle(int x, int y, int r) {
	if (antialiasing) {
		oldCopy();
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float cr = sqrt(pow((i - x), 2) + pow((j - y), 2));
			if (cr <= (r)) {
				X[j][i][0] = fillR;
				X[j][i][1] = fillG;
				X[j][i][2] = fillB;
			}
		}
	}
	circleStroke(x, y, r,true);
	circleStroke(x, y, r);
}
void Shapes::circleStroke(int x, int y, int r,bool aa) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float cr = sqrt(pow((i - x), 2) + pow((j - y), 2));
			if (r - cr >= 0 && r - cr <= strokeW) {
				X[j][i][0] = ((aa) ? fillR : strokeR) +((antialiasing) ? ((oldX[j][i][0] - 255 * (r - cr) <= 0) ? 0 : oldX[j][i][0] - 255 * (r - cr)) : 0);
				X[j][i][1] = ((aa) ? fillG : strokeG) + ((antialiasing) ? ((oldX[j][i][1] - 255 * (r - cr) <= 0) ? 0 : oldX[j][i][1] - 255 * (r - cr)) : 0);
				X[j][i][2] = ((aa) ? fillB : strokeB) + ((antialiasing) ? ((oldX[j][i][2] - 255 * (r - cr) <= 0) ? 0 : oldX[j][i][2] - 255 * (r - cr)) : 0);
			}
		}
	}
}
void Shapes::background(int x) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			X[j][i][0] = x;
			X[j][i][1] = x;
			X[j][i][2] = x;
		}
	}
}
void Shapes::draw() {
	file << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			file << X[j][i][0] << " " << X[j][i][1] << " " << X[j][i][2] << " ";
		}
		file << std::endl;
	}
	file.close();
	system("img.ppm");

}
void Shapes::stroke(int x) {
	strokeR = x;
	strokeG = x;
	strokeB = x;
}
void Shapes::stroke(int r,int g,int b) {
	strokeR = r;
	strokeG = g;
	strokeB = b;
}
void Shapes::fill(int x) {
	fillR = x;
	fillG = x;
	fillB = x;
}
void Shapes::fill(int r,int b,int g) {
	fillR = r;
	fillG = g;
	fillB = b;
}
void Shapes::strokeWeight(int x) {
	x = (x <= 0) ? 1 : x;
	strokeW = x;
}
void Shapes::setAntiAliasing(bool x) {
	antialiasing = x;
}

void Shapes::oldCopy() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			oldX[j][i][0] = X[j][i][0];
			oldX[j][i][1] = X[j][i][1];
			oldX[j][i][2] = X[j][i][2];
		}
	}
}