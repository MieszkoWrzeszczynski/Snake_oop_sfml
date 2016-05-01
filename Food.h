#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Food
{
	private:
		RectangleShape body;

	public:
		Food();
		void set_position(Vector2f new_position);
		Vector2f get_position();
		void draw(RenderTarget & target);
		FloatRect GetFoodBounds();
};

