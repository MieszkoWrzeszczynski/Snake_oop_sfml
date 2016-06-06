#include "Game.h"

String getPlayerNameFromArgs(int argc, char * argv[])
{
	return (argc == 2)  ? argv[1] : "Unnamed";
}

int main(int argc, char * argv[])
{
	Game game;
	game.setPlayerName(getPlayerNameFromArgs(argc,argv));
    game.start();

    return 0;
}