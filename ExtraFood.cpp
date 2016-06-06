#include "ExtraFood.h"

ExtraFood::ExtraFood(int food_size,Vector2f respawn_position)
{
	current_color = rand_color();
	extraFoodBody.setFillColor(current_color);
	extraFoodBody.setRadius(food_size);
	extraFoodBody.setPosition(respawn_position);
	extraFoodBody.setOutlineThickness(-1.f);
}

void ExtraFood::draw(RenderTarget & target)
{
	target.draw(extraFoodBody);
}

void ExtraFood::respawn(Vector2f respawn_position)
{
	current_color = rand_color();
	extraFoodBody.setFillColor(current_color);
	extraFoodBody.setPosition(respawn_position);
}

FloatRect ExtraFood::GetFoodBounds()
{
	return extraFoodBody.getGlobalBounds();
}