#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<chrono>
#include<thread>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#define VECTOR std::vector<RectangleShape>
using namespace sf;

class algorithm
{
	int num_data;

	private:
		int speed;
		std::string Menu_Text;

		VECTOR rect_array;
		VECTOR shuffle(VECTOR array, int size);
		VECTOR selection_sort(VECTOR array);

		/* Input these later, build the menu and option to pick thme first
		VECTOR bubble_sort(VECTOR array);
		VECTOR insertion_sort(VECTOR array);
		VECTOR merge_sort(VECTOR array);
		VECTOR quick_sort(VECTOR array);
		*/

		std::string change_string(int state);
		void render(VECTOR array);


	public:
		algorithm(int size);
		~algorithm();
		void display();


		
};

class menu
{
	private:
		int alg_state;
		int size_state;
		std::string algorithm_list[2];
		std::string size_list[3];

	public:
		int size;
		std::string algorithm;
		menu(int choice);
		Text Algorithm[5];
		Font AFont;
		void set_text();
		void display_text();
		void change_text(int choice);


};