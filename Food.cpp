#include "Food.h"
#include <iostream>

using namespace std;

Food::Food()
{
	body.setFillColor(Color(255, 255, 255, 255));
	body.setSize(Vector2f(20, 20));
	body.setPosition(500,400);
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