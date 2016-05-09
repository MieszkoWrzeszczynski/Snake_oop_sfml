#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Status
{
	 public:
	 	Status(int status_type, RenderWindow & window,std::string window_title,Font & font);
	 	int getStatusType();
	 	virtual void init() = 0;
	 	virtual void render() = 0;
	 	virtual void update() = 0;
	 	virtual	int getEvents(Event&) = 0;

	 protected:
	 	RenderWindow * pnt_window;
	 	std::string title;
	 	Font * pnt_font;
	 	int  type;
};