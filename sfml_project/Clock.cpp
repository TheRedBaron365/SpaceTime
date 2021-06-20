#include "Clock.h"
#include "Window.h"
WIN_DIMEN d;


Clock::Clock()
{
	this->seconds_passed = 0;
	this->minutes_passed = 0;
	std::cout << "Clock initted" << std::endl;
}
void Clock::clockInit()
{
	/*std::vector<sf::RectangleShape> shapes;*/
	sf::Text hour_time;
	hour_time.setPosition(sf::Vector2f(50.f, d.WIN_WIDTH / 2));
	hour_time.setFillColor(sf::Color::Black);

	second_hand.setSize(sf::Vector2f(2.f, d.WIN_HEIGHT / 2));
	second_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT / 2, d.WIN_WIDTH / 2));

	minute_hand.setSize(sf::Vector2f(10.f, d.WIN_HEIGHT/3));
	minute_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT/2, d.WIN_WIDTH/2));

	hour_hand.setSize(sf::Vector2f(30.f, d.WIN_HEIGHT/4));
	hour_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT/2, 10 + d.WIN_HEIGHT /2));

	minute_hand.setFillColor(sf::Color::Red);
	hour_hand.setFillColor(sf::Color::Blue);
	second_hand.setFillColor(sf::Color::Yellow);

	shapes.push_back(&minute_hand);
	shapes.push_back(&hour_hand);
	shapes.push_back(&second_hand);
	
	
	
	/*return shapes;*/
}


void Clock::rotateHands(sf::Clock &t)
{
	int elapsed = t.getElapsedTime().asMilliseconds();
	if (elapsed >= 1000)
	{
		seconds_passed++;
		t.restart();
		second_hand.rotate(6.f);

		if (seconds_passed % 10 == 0) {
			minute_hand.rotate(360.f / 60.f);
			seconds_passed = 0;
			minutes_passed++;

			if (minutes_passed % 2 == 0) {
				hour_hand.rotate(30.f);
			}
			
		}
		
	}
}


