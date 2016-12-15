#include <iostream>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Vector3.h"
#include "Matrix3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;

	int counter = 0;;
	bool scale;
};