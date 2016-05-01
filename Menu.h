#pragma once
#include "Status.h"
#include "Game.h"

using namespace sf;

class Menu : public Status
{
	public:
		Menu(int status_type, RenderWindow & window,Font & font);
 		void init();

	private:
		Text title;
		Text menuOptions[2];
		void update();
		void render();
		int getEvents(Event & event);
};