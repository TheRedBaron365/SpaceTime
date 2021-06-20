// Project SpaceTime
#include "Window.h"
#include "Clock.h"


int main()
{
	sf::Clock time;
	Window window(time);				
	while (window.m_Window.isOpen())
	{

		while (window.m_Window.pollEvent(window.m_Event))
		{
			window.pollEvents();
		}

		window.run();
	}

	std::cin.get(); // bcuz cherno
}