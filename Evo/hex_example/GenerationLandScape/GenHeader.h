#ifndef _GEN
#define _GEN
#include <vector>;
class MainGenLandScape {
public:
	int StartGeneretionLandscape();
	MainGenLandScape(int length, int width, int settingOfHeight, int settingOfHumidity) {
		this->length = length;
		this->width = width;
		this->settingOfHeight = settingOfHeight;
		this->settingOfHumidity = settingOfHumidity;
		field = new std::vector <std::vector <int>> (length, std::vector<int>(width, 0));
	}
	
protected:
	int length;
	int width;
	int settingOfHeight;
	int settingOfHumidity;
	std::vector <std::vector <int>> *field;
};
#endif _GEN