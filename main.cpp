#include "Game.h"

int main(int argc, char * argv[])
{
    string playerName;

	if (argc == 2)
		 playerName = argv[1];
	else
		playerName = "unnamed";

	Game game;
	game.setPlayerName(playerName);
    game.start();

    return 0;
}