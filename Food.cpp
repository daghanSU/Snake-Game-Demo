#include "Food.h"

Food::Food(Snake** snake_ref, int width, int height, int cell_size):width(width),height(height),cell_size(cell_size)
{
	this->o_snake = *snake_ref;
	this->e_food = new RectangleShape(Vector2f(cell_size, cell_size));
	this->e_food->setFillColor(Color::Red);

	setFoodPos();
}

Food::~Food()
{
	delete e_food;
}

void Food::drawFood(RenderWindow** win_ref)
{
	update_food();
	(*win_ref)->draw(*e_food);
}

void Food::setFoodPos()
{
	int n_x = width / cell_size;
	int n_y = height / cell_size;

	int random_y = (rand() % n_y) * 30 - 1;
	int random_x = (rand() % n_x) * 30 - 1;

	for (int i = 0; i < o_snake->parts.size(); i++)
	{
		if (o_snake->parts[i]->x == random_x && o_snake->parts[i]->y == random_y)
		{
			setFoodPos();
		}
	}

	e_food->setPosition(random_x, random_y);
}

void Food::update_food()
{
	if (o_snake->parts[0]->x == e_food->getPosition().x && o_snake->parts[0]->y == e_food->getPosition().y)
	{
		o_snake->isEaten = true;
		setFoodPos();
	}
} 