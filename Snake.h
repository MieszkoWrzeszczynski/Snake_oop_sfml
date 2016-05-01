#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;


class Snake
{

public:
	Snake();
	enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT , DIR_RIGHT	};
	Vector2f GetHeadPosition();
	Vector2f getDirection();
	FloatRect GetHeadFloatRect() const;
	void changeDirection(Direction direction);
	void draw(RenderTarget & target);
	void Move();
	void AddBodyPart();
	void Render(RenderTarget & target);
	bool hit_the_wall();
	bool exist();
	bool eaten();
	bool contains( const Vector2f& position);
private:
	vector <sf::RectangleShape> snake_body;
	Direction direction;


};