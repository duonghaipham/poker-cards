#include "functions.h"
#include <iostream>
#include <algorithm>

#define KCARDS 5
#define MAXROUNDS 50

bool _CompareScores(RankIndex lhs, RankIndex rhs)
{
	return lhs.Scores > rhs.Scores;
}

void ModeNormal(Cards DeckShuffled[], Cards EachPlayer[][KCARDS], Rank RankList[])
{
	int NoPlayer;
	std::cout << "Number of players: ";
	std::cin >> NoPlayer;

	int TimesPlay;
	std::cout << "Number of times: ";
	std::cin >> TimesPlay;

	std::cout << std::endl;

	int Count = 0;
	Rank RankListConclused[MAXPLAYERS][MAXROUNDS];
	RankIndex FinalRank[MAXPLAYERS + 1] = {};

	while (Count < TimesPlay)
	{
		std::cout << "$ ROUND " << Count + 1 << std::endl << std::endl;

		DealCards(DeckShuffled);
		DealHands(DeckShuffled, EachPlayer, NoPlayer);
		ShowCards(EachPlayer, NoPlayer);
		ShowRankList(EachPlayer, RankList, NoPlayer);

		for (int i = 0; i < NoPlayer; i++)
			RankListConclused[i][Count].Scores = RankList[i].Scores;
		Count++;
	}

	for (int i = 0; i < NoPlayer; i++)
	{
		for (int j = 0; j < TimesPlay; j++)
			FinalRank[i].Scores += RankListConclused[i][j].Scores;
		FinalRank[i].Index = i;
	}

	FinalRank[NoPlayer].Scores = 0; //Gan bang 0 de so sanh ngoai vung gia tri

	std::sort(FinalRank, FinalRank + NoPlayer, _CompareScores);

	for (int i = 0, Count = 0; i < NoPlayer; i++)
	{
		FinalRank[i].Ranks = Count;
		if (FinalRank[i].Scores != FinalRank[i + 1].Scores)
			Count++;
	}

	std::cout << "-----CONCLUSION-----" << std::endl << std::endl;
	std::cout << "Player\t";
	for (int j = 0; j < TimesPlay; j++)
		std::cout << "#" << j + 1 << "\t";
	std::cout << "SUM\tRANK" << std::endl;

	for (int i = 0; i < NoPlayer; i++)
	{
		std::cout << i + 1 << "\t";
		for (int j = 0; j < TimesPlay; j++)
			std::cout << RankListConclused[i][j].Scores << "\t";
		
		for (int j = 0; j < NoPlayer; j++)
		if (FinalRank[j].Index == i)
		{
			std::cout << FinalRank[j].Scores << "\t";
			std::cout << FinalRank[j].Ranks + 1 << std::endl;
			break;
		}
	}
	std::cout << std::endl;
}

void ModeDealer()
{

}