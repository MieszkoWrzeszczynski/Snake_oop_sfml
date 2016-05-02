#pragma once
#include "Status.h"
#include "Menu.h"
#include "Play.h"
#include <SFML/Audio.hpp>

class Game
{
	private:					
		RenderWindow window;
		Font font;
		Event event;
		Music music;
		Status * game_status;
		int actualGame_status;
		void changeActualGame_status();
		void handleState();

	public:
	 	Game();
	 	~Game();
	 	void start();
	 	enum  { MENU,RUN, PAUSED, END, GAME_OVER };
	 	static const int SCRN_WIDTH = 1280;
		static const int SCRN_HEIGHT = 568;

};