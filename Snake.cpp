#include "Snake.h"

void Snake::eat()
{
	if (isEaten == true)
	{
		parts.push_back(new SnakeNode());

		isEaten = false;
	}
	
}

void Snake::update_tail()
{
	for (int i = parts.size() - 1; i > 0; i--) {
		parts[i]->x = parts[i - 1]->x;
		parts[i]->y = parts[i - 1]->y;
	}
}

void Snake::direct_snake()
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		dir["up"] = true;
		dir["down"] = false;
		dir["right"] = false;
		dir["left"] = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		dir["up"] = false;
		dir["down"] = true;
		dir["right"] = false;
		dir["left"] = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		dir["up"] = false;
		dir["down"] = false;
		dir["right"] = false;
		dir["left"] = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		dir["up"] = false;
		dir["down"] = false;
		dir["right"] = true;
		dir["left"] = false;
	}

	if (dir["up"] == true)
		parts[0]->y -= vel;
	if (dir["down"] == true)
		parts[0]->y += vel;
	if (dir["right"] == true)
		parts[0]->x += vel;
	if (dir["left"] == true)
		parts[0]->x -= vel;
}

void Snake::detect_tail()
{
	for (int i = 1; i < parts.size(); i++) {
		if (parts[0]->x == parts[i]->x && parts[0]->y == parts[i]->y) {
			parts.erase(parts.begin() + 1, parts.end());
		}
	}
}

Snake::Snake(int width, int height, int cell_size) :cell_size(cell_size), width(width), height(height)
{
	parts.push_back(new SnakeNode());
	parts[0]->x = this->width / 2 / this->cell_size * this->cell_size - 1;
	parts[0]->y = this->height / 2 / this->cell_size * this->cell_size - 1;
}

Snake::~Snake()
{
	for (int i = 0; i < parts.size(); i++) {
		delete parts[i];
	}
}

void Snake::update_snake()
{
	update_tail();
	direct_snake();
	eat();
	detect_tail();
}

void Snake::draw_snake(RenderWindow& window)
{
	for (int i = 0; i < parts.size(); i++) {
		RectangleShape rect(Vector2f(this->cell_size, this->cell_size));
		rect.setFillColor(Color::Green);
		rect.setPosition(parts[i]->x, parts[i]->y);
		window.draw(rect);
	}
}
