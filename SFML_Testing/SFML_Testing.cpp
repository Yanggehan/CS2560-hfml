// SFML_Testing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <SFML/Graphics.hpp>   //using namespace sf 
#include<SFML/Audio.hpp>
#include<iostream>
#include <sstream>
#include <time.h> 



//dimensions for window size and background 

//sf::Text gamescore;
float timer1 = 0.0f, delay1 = 0.1f;
float timer2 = 0.0f, delay2 = 0.1f;
int num_vertBox = 50, num_horzBox =50;

int size = 16; //number of pixels 

int w = size * (num_horzBox);  //background number of pixels in width 

int h = size * (num_vertBox+8);    //background number of pixels in height 



//Snake variables to dertermine length and direction 

int direction1;    //direction the snake is moving  
int direction2;    //direction the snake is moving  

int snake_length1 = 4; //initial size is 4  
int snake_length2 = 4; //initial size is 4  
int score1 = 0;
int score2 = 0;


//Actual Snake in game is an array of x,y coordinates of sprite2 

struct Snake1

{

	int x, y;        //each sprite of snake needs an x,y coordinate 

}s1[100];
struct Snake2

{

	int x, y;        //each sprite of snake needs an x,y coordinate 

}s2[100];



//***NEW*** this is the fruit or food that the snake will eat 

struct Fruit

{

	int x, y;    // only need one sprite needed for one food item 

}food;


struct Fruit2

{

	int x, y;    // only need one sprite needed for one food item 

}food2;

//move snake head based on user input and body by incrementing  

//forward by iterating through arrays previous position 

void move1() {



	//1st update body so everything updates in proper order 

	//move the body only!  s[0] = head will not be changed here 

	for (int i = snake_length1; i > 0; i--)

	{

		s1[i].x = s1[i - 1].x;

		s1[i].y = s1[i - 1].y;

	}

	//2nd update the head 

	//Head of snake, s[0] depends on direction user inputs  

	//if user presses up 

	if (direction1 == 0)

		s1[0].y -= 1;



	//if user presses down 

	if (direction1 == 1)

		s1[0].y += 1;



	//if user presses left 

	if (direction1 == 2)

		s1[0].x -= 1;



	//if user presses right 

	if (direction1 == 3)

		s1[0].x += 1;





	//***NEW*** If Snake eats food it should grow 

	//check if snake head = food location 

	if (((s1[0].x) == food.x) && ((s1[0].y) == food.y))

	{

		//increment snake 
		delay1 -= 0.009;
		snake_length1++;
		score1+=1;
		


		//Randomly place food somewhere else 

		food.x = rand() % num_horzBox;

		food.y = rand() % num_vertBox;

	}
	if (((s1[0].x) == food2.x) && ((s1[0].y) == food2.y))

	{

		//increment snake 
		//delay1 -= 0.009;
		snake_length1+=2;
		score1 += 2;



		//Randomly place food somewhere else 

		food2.x = rand() % num_horzBox;

		food2.y = rand() % num_vertBox;

	}


	//***NEW*** Boundary Checking snake as is hits screen end 

	//loop snake back on other side 

	//LEFT and RIGHT 

	if (s1[0].x > num_horzBox-1)

		s1[0].x = 0;

	if (s1[0].x < 0)

		s1[0].x = num_horzBox;

	//TOP and BOTTOM 

	if (s1[0].y > num_vertBox-1)

		s1[0].y = 0;

	if (s1[0].y < 0)

		s1[0].y = num_vertBox;



	//***NEW*** Check if you eat body of snake 

	for (int i = 1; i < snake_length1; i++)

	{

		//Cut Snake body from place eaten 

		if (s1[0].x == s1[i].x && s1[0].y == s1[i].y)

			snake_length1 = i;

	}

}

void move2() {



	//1st update body so everything updates in proper order 

	//move the body only!  s[0] = head will not be changed here 

	for (int i = snake_length2; i > 0; i--)

	{

		s2[i].x = s2[i - 1].x;

		s2[i].y = s2[i - 1].y;

	}

	//2nd update the head 

	//Head of snake, s[0] depends on direction user inputs  

	//if user presses up 

	if (direction2 == 0)

		s2[0].y -= 1;



	//if user presses down 

	if (direction2 == 1)

		s2[0].y += 1;



	//if user presses left 

	if (direction2 == 2)

		s2[0].x -= 1;



	//if user presses right 

	if (direction2 == 3)

		s2[0].x += 1;





	//***NEW*** If Snake eats food it should grow 

	//check if snake head = food location 

	if (((s2[0].x) == food.x) && ((s2[0].y) == food.y))

	{

		//increment snake 
		delay2 -= 0.009;
		snake_length2++;
		score2++;



		//Randomly place food somewhere else 

		food.x = rand() % num_horzBox;

		food.y = rand() % num_vertBox;

	}
	if (((s2[0].x) == food2.x) && ((s2[0].y) == food2.y))

	{

		//increment snake 
		//delay2 -= 0.009;
		snake_length2 +=2;
		score2 +=2;



		//Randomly place food somewhere else 

		food2.x = rand() % num_horzBox;

		food2.y = rand() % num_vertBox;

	}



	//***NEW*** Boundary Checking snake as is hits screen end 

	//loop snake back on other side 

	//LEFT and RIGHT 

	if (s2[0].x > num_horzBox - 1)

		s2[0].x = 0;

	if (s2[0].x < 0)

		s2[0].x = num_horzBox;

	//TOP and BOTTOM 

	if (s2[0].y > num_vertBox - 1)

		s2[0].y = 0;

	if (s2[0].y < 0)

		s2[0].y = num_vertBox;



	//***NEW*** Check if you eat body of snake 

	for (int i = 1; i < snake_length2; i++)

	{

		//Cut Snake body from place eaten 

		if (s2[0].x == s2[i].x && s2[0].y == s2[i].y)

			snake_length2 = i;

	}

}

int main()

{

	//Setting pseudorandom time, TODO:discuss true random vs pseudorandom  

	srand(time(0));



	//Window that we can play the game in  

	sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game");

	sf::Texture t1, t2, t3,t4,t5,t6,t7;
	//sf::Music music;
	//Textures load an image into the GPU Memory 
	sf::Music music;
		music.openFromFile("BGM.ogg");
		music.setVolume(50);
		music.play();
	
	t1.loadFromFile("image/white.png");
	t2.loadFromFile("image/red.png");
	t3.loadFromFile("image/blue2.png");
	t4.loadFromFile("image/green.png");
	t5.loadFromFile("image/yellow.png");
	t6.loadFromFile("image/purple.png");
	t7.loadFromFile("image/black.png");


	//Sprite has physical dimmensions that can be set in  

	//coordinate system, setPosition(x,y), and drawn on screen 

	sf::Sprite sprite1(t1);

	sf::Sprite sprite2(t2);

	sf::Sprite sprite3(t3);
	sf::Sprite sprite4(t4);
	sf::Sprite sprite5(t5);
	sf::Sprite sprite6(t6);
	sf::Sprite sprite7(t7);
	//***NEW*** initially place food somewhere on screen 

	food.x = 10;

	food.y = 10;



	sf::Clock clock;
	
	
	//float timer1 = 0.0f, delay1 = 0.1f;

	//float timer2 = 0.0f, delay2 = 0.1f;

	while (window.isOpen())

	{

		//Error in class I placed this before the while loop 

		//Should be placed in while loop as shown here to update 

		//timer  

		float time1 = clock.getElapsedTime().asSeconds();
		float time2 = clock.getElapsedTime().asSeconds();

		clock.restart();

		timer1 += time1;
		timer2 += time2;



		//Allow us to check when a user does something 

		sf::Event e;



		//Check when the window is closed 

		while (window.pollEvent(e))

		{

			//If user presses x in the top right, Windows, top left, Mac,  close the window 

			if (e.type == sf::Event::Closed)

			{

				window.close();

			}

		}



		//Control for Snake by User 

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction2 = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction2 = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction2 = 2;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction2 = 3;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction1 = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction1 = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction1 = 2;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction1 = 3;



		if (timer1 > delay1)

		{

			timer1 = 0; //reset timer 

			move1();  
			//move2();    //move Snake one sprite forward 
		   //move Snake one sprite forward 

		}

		if (timer2 > delay2)

		{

			timer2 = 0; //reset timer 

		   //move Snake one sprite forward 
			move2();    //move Snake one sprite forward 

		}

		/*****************

		//Draw in window

		*****************/

		window.clear();    //clear the window so new frame can be drawn in 



		//NOTE: Order matters as we will draw over items listed first.  

		//Hence the background should be the first thing you will always do 

		//1st: Draw Background first 
	
		for (int i = 0; i < num_horzBox; i++)

		{

			for (int j = 0; j < num_vertBox; j++)

			{

				//Set position of sprite1 one at a time 

				sprite1.setPosition(i*size, j*size);

				//Draw sprite1 but, do not show it on screen.  

				window.draw(sprite1);

			}

		}
		

		//2nd: Then Draw snake otherwise background will be drawn over snake if order was reversed with background 
		
			for (int i = 0; i < snake_length1; i++)

			{

				//position sprite2 one at a time 

				sprite2.setPosition(s1[i].x*size, s1[i].y*size);
				sprite6.setPosition(s1[i].x*size, s1[i].y*size);
				//Draw sprite2 one at a time by drawing over background 
				 if(score1 >= 5) {
					window.draw(sprite6);
				}
				else
				window.draw(sprite2);

			}
		
		
		for (int i = 0; i < snake_length2; i++)

		{

			//position sprite2 one at a time 

			sprite4.setPosition(s2[i].x*size, s2[i].y*size);
			sprite7.setPosition(s2[i].x*size, s2[i].y*size);
			//Draw sprite2 one at a time by drawing over background 
			if (score2 >= 5) {
				window.draw(sprite7);
			}
			else
			window.draw(sprite4);

		}

	
		//***NEW*** 3rd: Draw Fruit 

		sprite3.setPosition(food.x*size, food.y*size);

		window.draw(sprite3);
		sprite5.setPosition(food2.x*size, food2.y*size);

		window.draw(sprite5);
		sf::Font arial;

		arial.loadFromFile("arial.ttf");
		std::ostringstream ss;
		ss << "play1(red) score: " << score1;



		sf::Text gamescore1;
		gamescore1.setCharacterSize(30);
		gamescore1.setPosition({ 10,800 });
		gamescore1.setFont(arial);
		gamescore1.setString(ss.str());
		window.draw(gamescore1);
		std::ostringstream ss2, ss3,ss4;

		ss2 << "play2(green) score: " << score2;
		ss3 << "when the score more than 5. The play1 change to purple, the play 2 change to black " ;
		ss4 << "(blue friut 1 point / yellow friut 2 points(bonus point not increase speed).)";
		sf::Text gamescore2, text,text2;
		gamescore2.setCharacterSize(30);
		gamescore2.setPosition({ 10, 830 });
		gamescore2.setFont(arial);
		gamescore2.setString(ss2.str());
		window.draw(gamescore2);
		text.setCharacterSize(15);
		text.setPosition({ 10, 860 });
		text.setFont(arial);
		text.setString(ss3.str());
		window.draw(text);
		text2.setCharacterSize(20);
		text2.setPosition({ 10, 890 });
		text2.setFont(arial);
		text2.setString(ss4.str());
		window.draw(text2);



		//Show everything we have drawn on the screen 
		/*sf::Music music;
		music.openFromFile("BGM.ogg");
		music.setVolume(50);
		music.play();*/
		window.display();

	}

	return 0;

}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
