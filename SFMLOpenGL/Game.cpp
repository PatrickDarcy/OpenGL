#include "Game.h"

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}

		update();
		draw();


	}

}

void Game::initialize()
{
	isRunning = true;

	// Uncomment for Part 2
	// ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.0, 2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-0.5, 1.0, -5.0);
		glVertex3f(-1.0, -0.0, -5.0);
		glVertex3f(-1.5, -1.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();


	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(-2.0, 1.0, -5.0);
		glVertex3f(0.0, 1.0, -5.0);

		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);

		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(2.0, 1.0, -5.0);
	}
	glEnd();
	glEndList();


	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-1.0, 1.0, -5.0);
		glVertex3f(1.0, 1.0, -5.0);

		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(2.0, -1.0, -5.0);

		glVertex3f(-1.0, 1.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();


	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(-1.0, 1.0, -5.0);

	}
	glEnd();
	glEndList();


	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(-2.0, -1.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-2.0, 1.0, -5.0);
		glVertex3f(0.0, 1.0, -5.0);

		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(2.0, 0.0, -5.0);

	}
	glEnd();
	glEndList();


	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(1.0, 0.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-1.0, 0.0, -5.0);
	}
	glEnd();
	glEndList();


	// Uncomment for Part 2
	// ***********
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
		{
			flip = false;
		}
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	// // ********************

	//cout << "Update up" << endl;

}

void Game::draw()
{
	// Uncomment for Part 2
	// ********************
	//cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Investigate Here!!!!!

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	// Uncomment for Part 2
	// ********************

	window.display();
}

void Game::unload()
{

}

