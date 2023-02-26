#include "Grill.h"

void Grill::grillSetup()
{
	for (int i = 0; i < width / cell_size; i++) {
		grill[i] = new RectangleShape[height / cell_size];
		for (int j = 0; j < height / cell_size; j++) {
			RectangleShape cell(Vector2f(cell_size, cell_size));
			cell.setOutlineThickness(1);
			cell.setOutlineColor(Color::Green);
			cell.setFillColor(Color::Black);
			cell.setPosition(i * cell_size, j * cell_size);
			grill[i][j] = cell;
		}
	}
}

void Grill::drawGrill(RenderWindow& window)
{
	for (int i = 0; i < width / cell_size; i++) {
		for (int j = 0; j < height / cell_size; j++) {
			window.draw(grill[i][j]);
		}
	}
}

Grill::Grill(int width, int height, int cell_size):width(width),height(height),cell_size(cell_size)
{
	grill = new RectangleShape * [width / cell_size];
}

Grill::~Grill()
{
	delete[] grill;
}

