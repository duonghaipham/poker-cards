#include "functions.h"

#define MAXPLAYERS 10
#define MAXROUNDS 50

int main()
{
	std::srand(std::time(0));

	Cards DeckShuffled[CARDS];
	Cards EachPlayer[MAXPLAYERS][KCARDS];
	Rank RankList[MAXPLAYERS];

	int ModeGames = 0;
	std::cout << "-----POKER GAMES-----" << std::endl;
	std::cout << "Mode 1: Multi-players" << std::endl;
	std::cout << "Mode 2: Countervailing" << std::endl << std::endl;
	std::cout << "Choose mode (1/2): ";
	std::cin >> ModeGames;

	if (ModeGames == 2)
	{
		ModeDealer();
	}
	else
	{
		ModeNormal(DeckShuffled, EachPlayer, RankList);
	}

	system("pause");

	return 0;
}