#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

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

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
		glMatrixMode(GL_PROJECTION); 
		glLoadIdentity(); 
		gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
		glMatrixMode(GL_MODELVIEW);

		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
}

void Game::update()
{

}

void Game::draw()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_TRIANGLES);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_POINTS);
		{
			glVertex3f(0.0, 2.0, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_LINES);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
		}

		glEnd();

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_LINE_STRIP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-0.5, 1.0, -5.0);
			glVertex3f(-1.0, -0.0, -5.0);
			glVertex3f(-1.5, -1.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
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
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
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
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
		glBegin(GL_QUADS);
		{
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(1.0, 1.0, -5.0);
			glVertex3f(-1.0, 1.0, -5.0);

		}

		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity;
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
	}

	window.display();
}

void Game::unload()
{

}

