#include "Snake.h"
#include "Game.h"
#include <iostream>

Snake::Snake()
{
	RectangleShape head;

	head.setFillColor(Color(255,138,0, 255));
	head.setSize(Vector2f(20, 20));
	head.setPosition(300,300);

	snake_body.push_back(head);

	direction = DIR_UP;
}

void Snake::changeDirection(Direction direction)
{
	Direction past_direct = this->direction;

    if(past_direct == DIR_UP && direction != DIR_DOWN)
    	this->direction = direction;

    if(past_direct == DIR_DOWN && direction != DIR_UP)
    	this->direction = direction;

    if(past_direct == DIR_LEFT && direction != DIR_RIGHT)
    	this->direction = direction;

    if(past_direct == DIR_RIGHT && direction != DIR_LEFT)
    	this->direction = direction;

}

Vector2f Snake::getDirection()
{
	Vector2f dir(0.f, 0.f);

	switch (direction)
	{
		case DIR_LEFT:
			dir.x = -1;
			break;

		case DIR_RIGHT:
			dir.x = 1;
			break;

		case DIR_UP:
			dir.y = -1;
			break;

		case DIR_DOWN:
			dir.y = 1;
			break;
	}

	return dir;
}


void Snake::Render(RenderTarget & target)
{
    Snake::draw(target);	
}


void Snake::draw(RenderTarget & target)
{

	for (int i = 0; i < snake_body.size(); i++)
	{
		target.draw(snake_body[i]);
	}

}


void Snake::Move()
{
	Vector2f prevPos = snake_body[0].getPosition();
	Vector2f dir = getDirection();
	Vector2f offset(dir.x * 20, dir.y * 20);
	snake_body[0].move(offset);

	for ( int i = 1; i < snake_body.size(); i++)
	{		
	   Vector2f tmp = snake_body[i].getPosition();
	   snake_body[i].setPosition(prevPos.x,prevPos.y);
	   prevPos = tmp;
	}
}

FloatRect Snake::GetHeadFloatRect() const
{
	return snake_body[0].getGlobalBounds();
}


void Snake::AddBodyPart()
{
	
    Vector2f last_item_position = snake_body.back().getPosition();
	Vector2f dir = getDirection();
	Vector2f offset(dir.x * 20, dir.y * 20);
	RectangleShape bodyPart;
	bodyPart.setOutlineThickness(-2.f);
	bodyPart.setSize(Vector2f(20,20));
	bodyPart.setFillColor(Color(255,138,0, 255));
	bodyPart.setPosition(offset);

	snake_body.push_back(bodyPart);
}


Vector2f Snake::GetHeadPosition()
{
	return  snake_body[0].getPosition();
}

bool Snake::hit_the_wall()
{
	if(snake_body[0].getPosition().x >= Game::SCRN_WIDTH -20 || 
	   snake_body[0].getPosition().x <= 0  ||
	   snake_body[0].getPosition().y <=  0  ||
	   snake_body[0].getPosition().y >= Game::SCRN_HEIGHT - 20 )
		return true;
	else
		return false;

}

bool Snake::eaten()
{
		Vector2f head_position = snake_body[0].getPosition();

		for(int i = 2; i <= snake_body.size() ; i++)
		{
			if(snake_body[i].getPosition() == head_position)
				return true;
		}

		return false;
}

bool Snake::exist()
{
	if(hit_the_wall() || eaten())
		return false;

	return true;
}

bool Snake::contains(const Vector2f& position)
{
	for (unsigned int i = 0; i <= snake_body.size(); i++)
	{
		if (snake_body[i].getPosition() == position)
		{
			
			//debug
			cout<<" we wezu"<<endl;
			return true;
		}
	}
	return false;
}
