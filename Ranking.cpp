#include "Ranking.h"

Ranking::Ranking():DB_NAME("ranking.csv")
{
	getRankingFromFile();
}

void Ranking::getRankingFromFile()
{
	string user_name;
	int score;

	ifstream db(DB_NAME);

    while (db >> score >> user_name)
        user.insert ( pair <int,string> (score,user_name) );

	db.close();

}

void Ranking::saveToRanking(string playerName, int playerScore)
{
	user.insert ( pair <int,string> (playerScore,playerName) );

	ofstream db(DB_NAME);

	for (it = user.begin(); it != user.end(); ++it)
   		 db << it->first << '\t' << it->second << '\n';

	db.close();
}

int Ranking::getTheBestPlayerScore()
{
	it=user.end();

 	return it->first;
}
