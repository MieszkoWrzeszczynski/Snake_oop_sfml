#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class Ranking
{
	public:
		Ranking();
		int getTheBestPlayerScore();
		void saveToRanking(string playerName, int playerScore);
		void getRankingFromFile();

	private:
		multimap <int,string> user;
		multimap <int,string>::iterator it;
		static string db_name;
};