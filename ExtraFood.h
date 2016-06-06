#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"

class ExtraFood : public Food
{
	private:
		CircleShape extraFoodBody;

	public:
		ExtraFood(int food_size,Vector2f respawn_position);
	    void respawn(Vector2f respawn_position);
		void draw(RenderTarget & target);
		FloatRect GetFoodBounds();
};