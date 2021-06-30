#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
#include <vector>
class Window
{
public:

	sf::RenderWindow m_Window;
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

	//void drawer(std::vector<sf::RectangleShape*>& v);
	void run();
	
	Window(sf::Clock &c);
	
	

private:
};

struct WIN_DIMEN
{
	const short int WIN_WIDTH =  650;
	const short int WIN_HEIGHT = 630;
};




