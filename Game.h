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
		static string playerName;
		int actualGame_status;
		void changeActualGame_status();
		void handleState();

	public:
	 	Game();
	 	~Game();
	 	void start();
	 	void setPlayerName(string playerName);
	 	static string getPlayerName();
	 	enum  { MENU,RUN, PAUSED, END, GAME_OVER };
	 	static const int SCRN_WIDTH = 1280;
		static const int SCRN_HEIGHT = 568;

};