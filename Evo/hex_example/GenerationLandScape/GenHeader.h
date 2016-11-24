#ifndef _GEN
#define _GEN
#include <vector>;
class MainGenLandScape {
public:
	int StartGeneretionLandscape();
	
	MainGenLandScape(int seed, int length, int width, int settingOfHeight, int settingOfHumidity) {
		this->seed = seed;
		this->length = length;
		this->width = width;
		this->settingOfHeight = settingOfHeight;
		this->settingOfHumidity = settingOfHumidity;
		std::vector <double> local;
		local.resize(width, 0);
		this->field.resize(length, local);
	}
	
protected:
	struct Coords {
		int ltX;
		int ltY;
		int rtX;
		int rtY;
		int rbX;
		int rbY;
		int lbX;
		int lbY;
	};
	void ValueOfStep(int x1, int x2, int y1, int y2);
	void ValueOfStep(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
	void GenerateHeights(Coords cOf );
	int Value(int a, int b);
	double Value(double a, double b);
	int Value(int a, int b, int c, int d);
	double Value(double a, double b, double c, double d);
	int seed;
	int length;
	int width;
	int settingOfHeight;
	int settingOfHumidity;
	std::vector <std::vector <double>> field;
};
#endif _GEN