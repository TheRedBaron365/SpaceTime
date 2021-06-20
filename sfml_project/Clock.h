#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Clock
{

private:
	sf::RectangleShape second_hand;
	sf::RectangleShape minute_hand;
	sf::RectangleShape hour_hand;

public:
	int seconds_passed;
	int minutes_passed;
	Clock();
	void clockInit();
	std::vector<sf::RectangleShape*> shapes;
	std::vector<sf::Time*> time_intervals;
	void rotateHands(sf::Clock &t);


};


