#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
using namespace std;
using namespace sf;
class Food
{
private:
	Snake* o_snake = NULL;
	RectangleShape* e_food = NULL;

	int width, height, cell_size;

	void setFoodPos();
	void update_food();
public:
	Food(Snake** snake_ref, int width, int height, int cell_size);
	~Food();

	void drawFood(RenderWindow** win_ref);
};

