#include "sort_algor.h"
extern RenderWindow window(VideoMode(800, 600), "Selection Sort");


algorithm::algorithm(int size)
{
	num_data = size;
}

algorithm::~algorithm()
{
	std::cout << "Object dead" << std::endl;
}

// In the following function, allows algorithm switch statement
void algorithm::display()
{
	speed = 0;
	change_string(0);
	rect_array = shuffle(rect_array, num_data);
	render(rect_array);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
			{
				return void();
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space)
			{

				std::cout << "Space Pressed" << std::endl;

				//Selection Sort Algorithm only option that changes
				speed = 5;
				selection_sort(rect_array);
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::R)
			{
				// Restart
				std::cout << "R Pressed" << std::endl;
				render(rect_array);
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::S)
			{
				rect_array = shuffle(rect_array, num_data);
				render(rect_array);
			}
		}
	}
}

VECTOR algorithm::shuffle(VECTOR array, int size)
{
	srand(time(0));
	array = {};
	
	// Horizontalspacing is proportional to the size of array, may need to edit constant for bigger sizes, maybe new variable for other algorithms?
	float horizontalSpacing =  (static_cast<float>(size * 0.6)) / static_cast<float>(window.getSize().x);
	for (int i = 0; i < size; i++)
	{
		int height = rand() % 499 + 15;
		int width = window.getSize().x / size;

		RectangleShape rect(Vector2f(width+horizontalSpacing, -height));
		array.insert(array.end(), rect);
	}
	
	return array;
}

void algorithm::render(VECTOR array)
{
	Font font;
	font.loadFromFile("/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf");
	Text text(Menu_Text, font, 14);
	text.setFillColor(Color::White);

	std::this_thread::sleep_for(std::chrono::milliseconds(speed));
	window.clear();
	window.draw(text);

	// Calculates position with floats instead of integer, prevents empty space between rectangles
	float x = static_cast<float>(window.getSize().x) / static_cast<float>(array.size());
	for (int i = 0; i < array.size(); i++)
	{
		// x * i ties position to index, allows swapping to be easier, i is required
		array[i].setPosition((x * i), window.getSize().y);
		window.draw(array[i]);
	}
	window.display();
}

std::string algorithm::change_string(int state)
{
	switch(state)
	{
		case 1:
			Menu_Text = "1: Fast-Foward | 2: Normal Speed | R : Restart | S : Shuffle |  Esc: Stop/Close";
			return Menu_Text;
			break;

		default:
			Menu_Text = "Space: Start | R : Restart | S : Shuffle | Esc : Exit";
			return Menu_Text;
			break;
	}
};

VECTOR algorithm::selection_sort(VECTOR array)
{
	Event event;
	change_string(1);

	for (int i = 0; i < array.size(); i++)
	{
		int min_index = i;

		for (int j = i + 1; j < array.size(); j++)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num1) { speed = 0; std::cout << speed << std::endl; }
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Num2) { speed = 5; std::cout << speed << std::endl; }
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape) { change_string(0); render(array); return array; }
			}
			array.at(j).setFillColor(Color::Red);
			render(array); // Mark current element

			if (-array.at(j).getSize().y < -array.at(min_index).getSize().y)
			{
				array.at(min_index).setFillColor(Color::White);
				render(array); // Unmark smallest element

				min_index = j;

				array[min_index].setFillColor(Color::Green);
				render(array); // Mark new smallest element
			}
			else
			{
				array.at(j).setFillColor(Color::White);
				render(array); // Unmark current element
			}
		}

		std::swap(array[min_index], array[i]);
		array.at(i).setFillColor(Color::Green);
		render(array); // Sorted
	}

	render(array);
	return array;
}

/*
VECTOR algorithm::bubble_sort(VECTOR array) 
{
	//Nothing in here yet
}

VECTOR algorithm::insertion_sort(VECTOR array) 
{
	//Nothing in here yet
}

VECTOR algorithm::merge_sort(VECTOR array) 
{
	//Nothing in here yet
}

VECTOR algorithm::quick_sort(VECTOR array) 
{
	//Nothing in here yet
}

*/

menu::menu(int choice)
{
	alg_state = choice;
	size_state = choice;
	std::string algorithm = "Selection";
	Text Algorithm[5];
	size = 100;
}

void menu::set_text()
{
		Algorithm[0].setString("Algorithm: Selection Sort");
		Algorithm[1].setString("Size: 100");
		Algorithm[2].setString("Press 1 to change algorithm");
		Algorithm[3].setString("Press 2 to change size");
		Algorithm[4].setString("Press 3 to start");
}

void menu::display_text()
{

	for (int i = 0; i < 5; i++)
	{
		Algorithm[i].setCharacterSize(26);
		Algorithm[i].setFont(AFont);
		Algorithm[i].setPosition(0, 50 * i);
		window.draw(Algorithm[i]);
	}
}

void menu::change_text(int choice)
{
	std::string algorithm_list[2] = { "Selection Sort", "Some New Algorithm" };
	std::string size_list[3] = { "100", "200" , "250" };

	//First has 2 second has 3
	if(choice == 0)
	{
		//temporary solution, what about choices more than one?
		if (alg_state != 0) { --alg_state; }
		else { ++alg_state; }

		std::string Algorithm_string = "Algorithm: " + algorithm_list[alg_state];
		Algorithm[0].setString(Algorithm_string);
		algorithm = algorithm_list[alg_state];
		
	}
	else if (choice == 1)
	{
		if (size_state != 0 && size_state == 2) { size_state = 0; } //Cycles through until it meets the last element, and then resets
		else { ++size_state; }

		std::string Size_string = "Size: " + size_list[size_state];
		Algorithm[1].setString(Size_string);
		size = stoi(size_list[size_state]);
	}

	std::cout << algorithm << std::endl;
	std::cout << size << std::endl;

}
