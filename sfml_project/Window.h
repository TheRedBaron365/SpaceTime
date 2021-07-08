#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>


class Window
{
public:

	sf::RenderWindow m_Window;
	sf::ContextSettings set;
	sf::Event m_Event;
	sf::Clock* time;
	Clock clock;
	void pollEvents();
	template <class T>
	void drawer(T& arg)
	{
		for (int i = 0; i < arg.size(); i++)
			m_Window.draw(*arg[i]);
	}
	void run();
	Window(sf::Clock& c);
};

struct WIN_DIMEN
{
	const short int WIN_WIDTH =  650;
	const short int WIN_HEIGHT = 630;
};




