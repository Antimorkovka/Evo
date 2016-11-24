#ifndef _GEN
#define _GEN
#include <vector>;
class MainGenLandScape {
public:
	MainGenLandScape(int length, int width, int settingOfHeight, int settingOfHumidity) {
		this->length = length;
		this->width = width;
		this->settingOfHeight = settingOfHeight;
		this->settingOfHumidity = settingOfHumidity;
		field = new std::vector <std::vector <int>> (length, std::vector<int>(width, 0));
	}
	int kek();
private:
	int length;
	int width;
	int settingOfHeight;
	int settingOfHumidity;
	std::vector <std::vector <int>> *field;
};
#endif _GEN