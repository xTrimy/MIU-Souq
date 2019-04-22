#pragma once
class Shapes
{
public:
	const int height = 100, width = 100;
	int X[100][100][3];
	int oldX[100][100][3];
	int strokeR = 0;
	int strokeG = 0;
	int strokeB = 0;
	int fillR = 255;
	int fillG = 255;
	int fillB = 255;
	int strokeW = 1;
	bool antialiasing = true;
	void rect(int, int, int, int);
	void rectStroke(int, int, int, int);
	void circle(int, int, int);
	void circleStroke(int, int, int,bool = false);
	void fill(int);
	void fill(int,int,int);
	void stroke(int);
	void stroke(int,int,int);
	void strokeWeight(int);
	void setAntiAliasing(bool);
	void oldCopy();
	void background(int);
	void draw();


};

