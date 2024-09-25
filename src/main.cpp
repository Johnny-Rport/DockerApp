/*
*	TODO: Start making the menu, Include: Menu that chooses algorithm, amount of rectangle (small medium large), and maybe window size???
*	Looks like if you want a class based program, menu must be able to change from main to control menu
* 
*/
#include "sort_algor.h"
extern RenderWindow window;


// Design the Menu: Algorithm choice, Size of data
// For menu, you must evaluate the position and text itself, maybe a separate class for menu?
int main() 
{ 
	Font font;
	font.loadFromFile("/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf");


	int state = 0;
	menu menu(state);
	menu.AFont = font;
	menu.set_text();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num1) //Change Algorithm
			{
				std::cout << "1 pressed" << std::endl;
				menu.change_text(0);
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num2) //Change Size
			{
				std::cout << "2 pressed" << std::endl;
				menu.change_text(1);
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num3)
			{
				std::cout << "3 pressed" << std::endl;
				algorithm algorithm(menu.size);
				//Then call display with algorithm of choice then make the other algorithms
				algorithm.display();
			}
		}

		window.clear();
		menu.display_text();
		window.display();

	}
}
