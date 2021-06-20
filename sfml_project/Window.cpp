#include "Window.h"
#include "Clock.h"

WIN_DIMEN dims;

Window::Window(sf::Clock &c) : m_Window(sf::VideoMode(dims.WIN_HEIGHT, dims.WIN_WIDTH), "Window")
{
	this->time = &c;
	clock.clockInit();
}



void Window::pollEvents()
{
	if (m_Event.type == sf::Event::Closed)
	{
		m_Window.close();
	}
}


void Window::run()
{
	/*
		Clear
		Draw
		Display
	*/

	m_Window.clear(sf::Color::White);
	clock.rotateHands(*time);
	drawer(clock.shapes);
	m_Window.display();
}
void Window::drawer(std::vector<sf::RectangleShape*> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		m_Window.draw(*v[i]);
	}
}
void Window::create()
{/*
	std::vector<sf::RectangleShape> images = clock.clockInit(*time);
	drawer(images);*/
}

