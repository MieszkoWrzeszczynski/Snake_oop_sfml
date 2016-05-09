#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Food.h"

using namespace sf;
using namespace std;

class Snake 
{
	public:
		Snake(int size,Vector2f spawn_position);
		~Snake();
		enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT , DIR_RIGHT	};
		FloatRect GetHeadFloatRect() const;
		void changeDirection(Direction direction);
		void Render(RenderTarget & target);
		void Move();
		bool contains(Food * food);
		void AddBodyPart();
		bool exist();

	private:
		vector <sf::RectangleShape> snake_body;
		Direction direction;
		bool hit_the_wall();
		bool selfEaten();
		int size;
		Vector2f GetHeadPosition();
		Vector2f getDirection();
};