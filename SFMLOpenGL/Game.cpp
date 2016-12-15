#include "Game.h"
#include "Matrix3.h"
#include "Vector3.h"

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO") {}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[36];
GLubyte triangles[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	vertex[0].coordinate[0] = -0.5f;
	vertex[0].coordinate[1] = -0.5f;
	vertex[0].coordinate[2] = 0.5f;

	vertex[1].coordinate[0] = -0.5f;
	vertex[1].coordinate[1] = 0.5f;
	vertex[1].coordinate[2] = 0.5f;

	vertex[2].coordinate[0] = 0.5f;
	vertex[2].coordinate[1] = 0.5f;
	vertex[2].coordinate[2] = 0.5f;

	vertex[3].coordinate[0] = 0.5f; 
	vertex[3].coordinate[1] = -0.5f;  
	vertex[3].coordinate[2] = 0.5f;

	vertex[4].coordinate[0] = -0.5f; 
	vertex[4].coordinate[1] = -0.5f;  
	vertex[4].coordinate[2] = -0.5f;

	vertex[5].coordinate[0] = -0.5f; 
	vertex[5].coordinate[1] = 0.5f;  
	vertex[5].coordinate[2] = -0.5f;

	vertex[6].coordinate[0] = 0.5f;
	vertex[6].coordinate[1] = 0.5f;
	vertex[6].coordinate[2] = -0.5f;

	vertex[7].coordinate[0] = 0.5f;
	vertex[7].coordinate[1] = -0.5f;
	vertex[7].coordinate[2] = -0.5f;

	//Color
	vertex[0].color[0] = 0.0f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 1.0f;

	vertex[1].color[0] = 1.0f;
	vertex[1].color[1] = 0.0f;
	vertex[1].color[2] = 1.0f;

	vertex[2].color[0] = 1.0f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 1.0f;
	vertex[3].color[1] = 0.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.0f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.0f;
	vertex[5].color[1] = 0.0f;
	vertex[5].color[2] = 1.0f;

	vertex[6].color[0] = 1.0f;
	vertex[6].color[1] = 1.0f;
	vertex[6].color[2] = 1.0f;

	vertex[7].color[0] = 1.0f;
	vertex[7].color[1] = 1.0f;
	vertex[7].color[2] = 1.0f;




	triangles[0] = 1;   triangles[1] = 0;   triangles[2] = 2;
	triangles[3] = 2;   triangles[4] = 0;   triangles[5] = 3;
	triangles[6] = 1;   triangles[7] = 6;   triangles[8] = 5;
	triangles[9] = 1;   triangles[10] = 2;  triangles[11] = 6;
	triangles[12] = 2;  triangles[13] = 3;  triangles[14] = 6;
	triangles[15] = 3;  triangles[16] = 7;  triangles[17] = 6;
	triangles[18] = 0;  triangles[19] = 1;  triangles[20] = 5;
	triangles[21] = 4;  triangles[22] = 0;  triangles[23] = 5;
	triangles[24] = 4;  triangles[25] = 6;  triangles[26] = 7;
	triangles[27] = 4;  triangles[28] = 5;  triangles[29] = 6;
	triangles[30] = 0;  triangles[31] = 4;  triangles[32] = 7;
	triangles[33] = 0;  triangles[34] = 7;  triangles[35] = 3;


	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glEnable(GL_CULL_FACE);
}

void Game::update()
{
	Matrix3 m;
	MyVector3 v;
	elapsed = clock.getElapsedTime();
	//glRotated(0.01 ,1.0, 0.0, 1.0);
	for (int i = 0; i < 36; i++)
	{
		v = MyVector3(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);
		v = m.RotateAboutZ(m.RotateAboutY(m.RotateAboutX(v, 0.1f), 0.1f), 0.1f);
		
		if (scale)
		{
			v = v.Scale(1.0007);
		}
		else
		{
			v = v.Scale(1 / 1.0007);
		}
		if (counter == 10000)
		{
			if (scale)
			{
				scale = false;
			}
			else
			{
				scale = true;
			}
			counter = 0;
		}
		vertex[i].coordinate[0] = v.GetX();
		vertex[i].coordinate[1] = v.GetY();
		vertex[i].coordinate[2] = v.GetZ();
		counter++;
	}
	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 36);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}