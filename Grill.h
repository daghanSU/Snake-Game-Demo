#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Grill
{
private:
	RectangleShape** grill = nullptr;

	int width, height, cell_size;
public:
	Grill(int width, int height, int cell_size);
	~Grill();

	void grillSetup();
	void drawGrill(RenderWindow& window);
};

