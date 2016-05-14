#include "Food.h"

Food::Food(int food_size,Vector2f respawn_position)
{
	current_color = rand_color();
	body.setFillColor(current_color);
	body.setSize(Vector2f(food_size, food_size));
	body.setPosition(respawn_position);
}

Food::Food()
{
	current_color = rand_color();
	body.setFillColor(current_color);
	body.setSize(Vector2f(20, 20));
	body.setPosition(300,300);
}

void Food::respawn(Vector2f respawn_position)
{
	current_color = rand_color();
	body.setFillColor(current_color);
	body.setPosition(respawn_position);
}

void Food::set_position(Vector2f new_position)
{
	body.setPosition(new_position);
}

Color Food::rand_color()
{
    return Color(rand() % 255, rand() % 255, rand() % 255);
}

Color Food::getCurrentColor()
{
	return this->current_color;
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