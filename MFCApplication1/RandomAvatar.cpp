#include "stdafx.h"
#include "RandomAvatar.h"
#include "SaveToBMP.h"
#include "Shapes.h"
int Colors[9][3];

void setBitmapPixels(Shapes, SaveToBMP::rgb_data*);
int randomColor(void);
void saveBitmap(SaveToBMP, const char*, Shapes, int, SaveToBMP::rgb_data*);
void _default(Shapes&);
void RandomAvatar::create(const char* filePath) {
	SaveToBMP BMP;
	Shapes sh;

	sh.setAntiAliasing(true);
	int dpi = 256;
	SaveToBMP::rgb_data *pixels = new SaveToBMP::rgb_data[sh.width * sh.height];
	std::srand(time(0));
	_default(sh);
	setBitmapPixels(sh, pixels);
	saveBitmap(BMP, filePath, sh, dpi, pixels);
}
void _default(Shapes&sh) {
	for (int i = 0; i < 9; i++) {
		Colors[i][0] = std::rand() % 256;
		Colors[i][1] = std::rand() % 256;
		Colors[i][2] = std::rand() % 256;
	}
	int blockSize = 20;
	int Arr[9][3];
	int count;
	sh.background(255);

	//   ------1-Top---->
	//   |              |
	//   |              2
	//   |              |
	// Left           Right
	//   4              | 
	//   <----Bottom--3-V   


	//1 Top Side
	count = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = y; x < sh.width / blockSize - 1 - y; x++) {
			sh.fill(Colors[count][0], Colors[count][1], Colors[count][2]);
			sh.rect(x*blockSize, y*blockSize, blockSize, blockSize);
			count++;
		}
	}

	//2 Right Side
	count = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = y; x < sh.width / blockSize - 1 - y; x++) {
			sh.fill(Colors[count][0], Colors[count][1], Colors[count][2]);
			sh.rect(100 - blockSize - y*blockSize, x*blockSize, blockSize, blockSize);
			count++;
		}
	}

	//3 Bottom Side
	count = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = y; x < sh.width / blockSize - 1 - y; x++) {
			sh.fill(Colors[count][0], Colors[count][1], Colors[count][2]);
			sh.rect(100 - blockSize - x * blockSize, 100 - blockSize - y * blockSize, blockSize, blockSize);
			count++;
		}
	}

	//4 Left Side
	count = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = y; x < sh.width / blockSize - 1 - y; x++) {
			sh.fill(Colors[count][0], Colors[count][1], Colors[count][2]);
			sh.rect(y * blockSize, 100 - blockSize - x * blockSize, blockSize, blockSize);
			count++;
		}
	}

}
void setBitmapPixels(Shapes sh, SaveToBMP::rgb_data*pixels) {
	for (int x = 0; x < sh.width; x++) {
		for (int y = 0; y < sh.height; y++) {
			int a = y * sh.width + x;
			pixels[a].r = sh.X[x][sh.height - y - 1][0];
			pixels[a].g = sh.X[x][sh.height - y - 1][1];
			pixels[a].b = sh.X[x][sh.height - y - 1][2];
		}
	}
}

int randomColor() {
	return std::rand() % 256;
}
void saveBitmap(SaveToBMP BMP,const char*filePath, Shapes sh, int dpi, SaveToBMP::rgb_data*pixels) {
	BMP.save_bitmap(filePath, sh.width, sh.height, dpi, pixels);
}