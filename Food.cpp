#include "Food.h"
#include <iostream>

using namespace std;

Food::Food(int food_size,Vector2f respawn_position)
{
	body.setFillColor(Color(178,30,0, 255));
	body.setSize(Vector2f(food_size, food_size));
	body.setPosition(respawn_position);
}

void Food::set_position(Vector2f new_position)
{
	body.setPosition(new_position);
}


void Food::draw(RenderTarget & target)
{
	target.draw(body);
}


Vector2f Food::get_position()
{
	return body.getPosition();
}

FloatRect Food::GetFoodBounds()
{
	return body.getGlobalBounds();
}