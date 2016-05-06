#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;


class Snake 
{

public:
	Snake(int size,Vector2f respawn_position);
	~Snake();
	enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT , DIR_RIGHT	};
	Vector2f GetHeadPosition();
	Vector2f getDirection();
	FloatRect GetHeadFloatRect() const;
	void changeDirection(Direction direction);
	void draw(RenderTarget & target);
	void Move();
	bool contains( const Vector2f& position);
	void AddBodyPart();
	void Render(RenderTarget & target);
	bool exist();

private:
	vector <sf::RectangleShape> snake_body;
	Direction direction;
	bool hit_the_wall();
	bool eaten();
	int size;


};