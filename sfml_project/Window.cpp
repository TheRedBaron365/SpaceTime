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

	m_Window.clear(sf::Color(200, 100, 80, 255));
	clock.rotateHands(*time);
	drawer(clock.shapes);

	for (int i = 0; i < clock.time_intervals.size(); i++)
		m_Window.draw(clock.time_intervals[i]);

	m_Window.display();
}
