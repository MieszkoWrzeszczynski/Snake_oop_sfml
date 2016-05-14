#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"

using namespace sf;

class ExtraFood : public Food
{
	private:
		CircleShape extraFoodBody;

	public:
		ExtraFood(int food_size,Vector2f respawn_position);
	    void respawn(Vector2f respawn_position);
		void draw(RenderTarget & target);
		void set_position(Vector2f new_position);
		Vector2f get_position();
		FloatRect GetFoodBounds();
		int getBonus();
};