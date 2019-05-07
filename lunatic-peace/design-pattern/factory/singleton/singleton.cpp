#include <iostream>

using namespace std;

class GameSettings{
    static GameSettings *_instance;
    int _brightness;
    int _height;
    int _width;
    GameSettings():_brightness(200), _height(150), _width(100) {}

    public:
        static GameSettings* getInstance() {
            if (_instance == NULL) {
                _instance = new GameSettings();
            }
            return _instance;
        }

        void setWidth(int width) {
            _width = width;

        }
        void setHeight(int height) {
            _height = height;
        }
        void setBrightness(int brightness) {
            _brightness = brightness;
        }

        int getWidth() { 
            return _width;
        }

        int getBrightness() {
            return _brightness;
        }
        int getHeight() {
            return _height;
        }

        void displaySettings() {
            cout << "brightness: " << _brightness << endl;
		    cout << "height: " << _height << endl;
		    cout << "width: " << _width << endl << endl;
        }

};
GameSettings * GameSettings::_instance = NULL;
 
void someFunction () {
	GameSettings *setting = GameSettings::getInstance();
	setting->displaySettings();
}
 
int main() {
 
	GameSettings *setting = GameSettings::getInstance();
	setting->displaySettings();
	setting->setBrightness(100);
	
	someFunction();
	return 0;
}