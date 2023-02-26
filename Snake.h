#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "SnakeNode.h"
using namespace std;
using namespace sf;


class Snake
{
private:
	int cell_size,width,height;
	int vel = 30;

	map<string, bool>dir{
		{"up",false},{"down",false},{"right",false},{"left",false}
	};

	void eat();
	void update_tail();
	void direct_snake();
	void detect_tail();
public:
	vector<SnakeNode*>parts;

	Snake(int width,int height,int cell_size);
	~Snake();

	bool isEaten = false;

	void update_snake();
	void draw_snake(RenderWindow& window);
};

