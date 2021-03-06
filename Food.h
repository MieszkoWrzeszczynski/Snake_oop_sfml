#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Food
{
	private:
		RectangleShape body;

	protected:
		Color current_color;

	public:
		Food(int food_size,Vector2f respawn_position);
		Food();
		virtual void respawn(Vector2f respawn_position);
		virtual void draw(RenderTarget & target);
		virtual FloatRect GetFoodBounds();
		virtual Color getCurrentColor();
		Color rand_color();
};