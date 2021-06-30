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
	//Clock face settings
	clock_face.setRadius(300.f);
	clock_face.setOrigin(150.f, 150.f);
	clock_face.setFillColor(sf::Color(55, 63, 30));
	clock_face.setPosition(315 - 150, 325 - 150);

	

	//Hand settings
	second_hand.setSize(sf::Vector2f(2.f, d.WIN_HEIGHT / 2));
	second_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT / 2, d.WIN_WIDTH / 2));
	second_hand.rotate(180.f);
	minute_hand.setSize(sf::Vector2f(10.f, d.WIN_HEIGHT/3));
	minute_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT/2, d.WIN_WIDTH/2));
	minute_hand.rotate(180.f);
	hour_hand.setSize(sf::Vector2f(30.f, d.WIN_HEIGHT/4));
	hour_hand.setPosition(sf::Vector2f(d.WIN_HEIGHT/2, 10 + d.WIN_HEIGHT /2));
	hour_hand.rotate(180.f);
	 
	//Color settings
	minute_hand.setFillColor(sf::Color(200, 10, 30));
	hour_hand.setFillColor(sf::Color(25, 100, 200));
	second_hand.setFillColor(sf::Color::Yellow);


	//Push to draw
	shapes.push_back(&clock_face);
	shapes.push_back(&minute_hand);
	shapes.push_back(&hour_hand);
	shapes.push_back(&second_hand);

	
	
	
	
}



//Temporary for debug
void Clock::rotateHands(sf::Clock &t)
{
	int elapsed = t.getElapsedTime().asMilliseconds();
	if (elapsed >= 1000)
	{
		seconds_passed++;
		t.restart();
		second_hand.rotate(6.f);

		if (seconds_passed % 60 == 0) {
			minute_hand.rotate(360.f / 60.f);
			seconds_passed = 0;
			minutes_passed++;

			if (minutes_passed % 60 == 0) {
				hour_hand.rotate(30.f);
			}
			
		}
		
	}
}


