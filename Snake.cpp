#include "Snake.h"
#include "Game.h"

Snake::Snake(int size,Vector2f spawn_position)
{
	this->size = size;
	RectangleShape head;
	direction = DIR_UP;

	head.setFillColor(Color(255,138,0, 255));
	head.setOutlineThickness(-1.f);
	head.setSize(Vector2f(size, size));
	head.setPosition(spawn_position);

	snake_body.push_back(head);
}


Snake::~Snake()
{
	snake_body.clear();
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
   for (int i = 0; i < snake_body.size(); i++)
   {
		target.draw(snake_body[i]);
   }
}

void Snake::Move()
{
	Vector2f prevPos = snake_body[0].getPosition();
	Vector2f dir = getDirection();
	Vector2f offset(dir.x * size, dir.y * size);
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


void Snake::AddBodyPart(Color new_color)
{
	RectangleShape bodyPart;

    Vector2f last_item_position = snake_body.back().getPosition();
	Vector2f dir = getDirection();
	Vector2f offset(dir.x * size, dir.y * size);

	bodyPart.setOutlineThickness(-1.f);
	bodyPart.setSize(Vector2f(size,size));
	bodyPart.setFillColor(new_color);
	bodyPart.setPosition(offset);

	snake_body.push_back(bodyPart);
}


Vector2f Snake::GetHeadPosition()
{
	return  snake_body[0].getPosition();
}

bool Snake::hit_the_wall()
{
	if(GetHeadPosition().x >= Game::SCRN_WIDTH - size || 
	   GetHeadPosition().x <= 0  ||
	   GetHeadPosition().y <= 0  ||
	   GetHeadPosition().y >= Game::SCRN_HEIGHT - size )
		return true;
	else
		return false;

}

bool Snake::selfEaten()
{
	
	for(int i = 1; i < snake_body.size() ; i++)
	{
		if (snake_body[i].getGlobalBounds().intersects(GetHeadFloatRect()))
			return true;
	}

	return false;
}

bool Snake::exist()
{
    return !(hit_the_wall() || selfEaten());
}

bool Snake::contains(Food * food)
{
	for (int i = 1; i < snake_body.size(); i++)
	{
		if (snake_body[i].getGlobalBounds().intersects(food->GetFoodBounds()))
			return true;
	}
	
	return false;
}
