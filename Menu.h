#pragma once
#include "Status.h"
#include <SFML/Audio.hpp>

class Menu : public Status
{
	public:
		Menu(int window_type, RenderWindow & window,std::string window_title,Font & font);
 		void init();
		void setTitle(std::string title_window);
	
	private:
		Text header;
		Text menuOptions[2];
		void update();
		void render();
		int getEvents(Event & event);
};