//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//FlappyAndy.cpp

#include "FlappyAndy.h"

void FlappyAndy::runApp() {

	bool soundSuccess = false, collisionSuccess = false, pointCheck = false;
	int jumpCheck = 0;
	srand(time(NULL));//for random number

	//open window
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flappy Andy");

	//declerations
	sf::Texture Background, Andy, Gameover, pipeT, pipe2T, pointsT;
	sf::Sprite BackgroundSprite, AndySprite, GameoverSprite, pipe, pipe2, pointsS;
	sf::RectangleShape Pipe, PipeTop;
	sf::SoundBuffer SplatBuffer;
	sf::Sound Splat;
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	Points pointClass;

	int i = 0, y = 0, y2 = 0, points = 0;

	//set textures from file
	Background.loadFromFile("pics/background.png");
	Andy.loadFromFile("pics/andy2.png");
	pipeT.loadFromFile("pics/pipe.png");
	pipe2T.loadFromFile("pics/pipe2.png");
	pointsT.loadFromFile("pics/points.png");

	//set sprites from textures
	BackgroundSprite.setTexture(Background);
	BackgroundSprite.scale(adjustX, adjustY);
	AndySprite.setTexture(Andy);
	AndySprite.setScale(0.5, 0.5);
	AndySprite.setPosition(andyX, 300);

	//pipe
	Pipe.setSize(sf::Vector2f(200, 400));
	Pipe.setFillColor(sf::Color::Red);
	Pipe.setOutlineColor(sf::Color::Black);
	Pipe.setOutlineThickness(5);
	Pipe.setPosition(sf::Vector2f(400, 700));

	pipe.setTexture(pipeT);
	pipe.scale(adjustX, adjustY);
	pipe.setPosition(650, 500);

	pipe2.setTexture(pipe2T);
	pipe2.scale(adjustX, adjustY);
	pipe2.setPosition(650, -500);


	//gameover
	Gameover.loadFromFile("pics/gameover.png");
	GameoverSprite.setTexture(Gameover);
	GameoverSprite.scale(adjustX, adjustY);

	//points
	pointsS.setTexture(pointsT);
	pointsS.scale(adjustX, adjustY);
	pointsS.setPosition(0, 0);
	
	//audio

	SplatBuffer.loadFromFile("audio/splat.wav");
	Splat.setBuffer(SplatBuffer);

	//open window section
	while (window.isOpen()) {
		//set framerate
		window.setFramerateLimit(60);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//count time
		elapsed = clock.getElapsedTime();

		//draw
		window.draw(BackgroundSprite);
		window.draw(AndySprite);
		window.draw(pipe2);
		window.draw(pipe);
		
		//window.draw(PipeTop);

		//draw game over
		if (collisionSuccess == true) {
			//display game over
			window.draw(GameoverSprite);
			pointsS.setPosition(-1410, 325);
			pointsS.setScale(1.2, 1.2);
			window.draw(pointsS);
			pointClass.showPointsLarge(window, points, 625, 450);
		}

		if (collisionSuccess == false) {//start movements
			//show points upper right
			window.draw(pointsS);
			pointClass.showPoints(window, points, 1250, 50);


			//constant gravity
			if (AndySprite.getPosition().y < 680) {
				AndySprite.move(0, 10);
				AndySprite.setRotation(10);
			}
			//check for lower bounds
			if (AndySprite.getPosition().y > 680 && soundSuccess == false) {
				Splat.play();
				soundSuccess = true;
				collisionSuccess = true;
				////restarts loop time
				clock.restart();
				elapsed = clock.getElapsedTime();
				//window.clear();
			}

			//flying up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpCheck <= 5){
				if (AndySprite.getPosition().y > -25) {
					AndySprite.setPosition(AndySprite.getPosition().x, AndySprite.getPosition().y - 5);
					AndySprite.move(0, -30);
					AndySprite.setRotation(-10);
					jumpCheck++;
				}
				//check for upper bounds
				if (AndySprite.getPosition().y < -25 && soundSuccess == false) {
					Splat.play();
					soundSuccess = true;
					collisionSuccess = true;
					////restarts loop time
					clock.restart();
					elapsed = clock.getElapsedTime();
					//window.clear();
				}
				jumpCheck = true;
				clock.restart();
				elapsed = clock.getElapsedTime();
			}

			//moving pipe
			pipe.move(-20, 0);
			pipe2.move(-20, 0);

			//random reset pipe
			i = rand() % 3;
			switch (i) {
			case 0:
				y = 500;
				y2 = -500;
				break;
			case 1:
				y = 400;
				y2 = -600;
				break;
			case 2:
				y = 600;
				y2 = -400;
				break;
			}
			if (pipe.getPosition().x < -200) {
				pipe.setPosition(1400, y);
				pointCheck = false;
			}
			if (pipe2.getPosition().x < -200) {
				pipe2.setPosition(1400, y2);
			}


			//points
			if (pipe.getPosition().x < andyX && pointCheck == false) {
				points++;
				pointCheck = true;
			}

			//collision
			//old
			//if ((Pipe.getPosition().x + Pipe.getSize().x - AndySprite.getPosition().x) <=
			//	(AndySprite.getGlobalBounds().width + Pipe.getSize().x) &&
			//	(AndySprite.getPosition().y + AndySprite.getGlobalBounds().height) >=
			//	(Pipe.getPosition().y)
			//	|| (AndySprite.getPosition().y < pipe2.getPosition().y + pipe2.getGlobalBounds().height)
			//	) {
			if ((pipe.getPosition().x + pipe.getGlobalBounds().width - AndySprite.getPosition().x) <=
				(AndySprite.getGlobalBounds().width + pipe.getGlobalBounds().width) &&
				(AndySprite.getPosition().y + AndySprite.getGlobalBounds().height) >=
				(pipe.getPosition().y)
				//|| (AndySprite.getPosition().y < pipe2.getPosition().y + pipe2.getGlobalBounds().height)
				) {
				if (soundSuccess == false) {
          					Splat.play();
					soundSuccess = true;
					collisionSuccess = true;
					////restarts loop time
					clock.restart();
					elapsed = clock.getElapsedTime();
  					//window.clear();
				}

			}
		}//end collision check

		window.display();

		//time checks
		if (jumpCheck >= 5 && elapsed >= sf::milliseconds(200)) {
			jumpCheck = 0;
		}
		
		if (collisionSuccess == true && elapsed >= sf::seconds(3)) {
			window.close();
		}
		

	}//end of open window section

}


