#include "Status.h"
#include <vector>
#include <SFML/Graphics.hpp>
#pragma once


using namespace sf;
using namespace std;

class Game
{
	private:					
		RenderWindow window;
		Font font;
		Event event;
		Status * game_status;
		int actualGame_status;
		void changeActualGame_status();
		void handleState();

	public:
	 	Game();
	 	void start();
	 	enum  { MENU,RUN, PAUSED, END, GAME_OVER };
	 	static const int SCRN_WIDTH = 1280;
		static const int SCRN_HEIGHT = 568;

};