#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Clock
{

private:
	sf::RectangleShape second_hand;
	sf::RectangleShape minute_hand;
	sf::RectangleShape hour_hand;
	sf::CircleShape clock_face;
	sf::Text twelve;
	sf::Font font;


public:
	int seconds_passed;
	int minutes_passed;
	Clock();
	void drawIncrements();
	void clockInit();
	std::vector<sf::Drawable*> shapes;
	std::vector<sf::Text> time_intervals;
	void rotateHands(sf::Clock &t);
	sf::Transform transformer; 
};


