#include "prospect.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FACES 13
#define KCARDS 5
#define MAXPLAYERS 10

bool _CompareFaces(Cards lhs, Cards rhs)
{
	return lhs.Faces > rhs.Faces;
}

char _ConvertChar(int Value)
{
	if (Value >= 0 && Value <= 9)
		return (char)Value + 48;
	else if (Value == 10)
		return 'A';		//A dai dien cho J, mang ma 65
	else if (Value == 11)
		return 'B';		//B dai dien cho Q
	else if (Value == 12)
		return 'C';		//C dai dien cho K
	else				//co the Value == 13
		return 'D';		//D dai dien cho Ace
}

//Prototype de tai su dung ham
void RankListThreeOfAKind(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexThreeOfAKind, int &IndexStart, int NoPlayer);
void RankListNormal(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexNormal, int &IndexStart, int NoPlayer);
//Ket thuc prototype

//Xep hang nhung hand la cai sanh va cung chat
void RankListStraightFlush(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexStraightFlush, int &IndexStart, int NoPlayer)
{
	std::vector<std::string> StringHand;

	for (int i = 0; i < IndexStraightFlush.size(); i++)
	{
		std::string CurrentStringHand = "";

		CurrentStringHand += _ConvertChar(EachPlayer[IndexStraightFlush.at(i)][0].Faces);
		CurrentStringHand += _ConvertChar(IndexStraightFlush.at(i));
		StringHand.push_back(CurrentStringHand);
	}
	std::sort(StringHand.begin(), StringHand.end());

	int Count = 0;
	while (Count < IndexStraightFlush.size())
	{
		RankList[StringHand[Count].at(1) - 48].Ranks = IndexStart;
		RankList[StringHand[Count].at(1) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand la tu qui
void RankListFourOfAKind(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexFourOfAKind, int &IndexStart, int NoPlayer)
{
	int CountFace[MAXPLAYERS][FACES + 1] = { 0 };//FACES + 1 vi luu them so 13 <=> Ace

	for (int i = 0; i < IndexFourOfAKind.size(); i++)
	for (int j = 0; j < KCARDS; j++)
		CountFace[i][EachPlayer[IndexFourOfAKind.at(i)][j].Faces]++;

	std::vector<std::string> StringThree;

	for (int i = 0; i < IndexFourOfAKind.size(); i++)
	{
		std::string CurrentStringHand = "";

		for (int j = FACES - 1 + 1; j >= 0; j--)//FACES + 1 vi luu them so 13 <=> Ace
		if (CountFace[i][j] == 4)
		{
			CurrentStringHand += _ConvertChar(j);
			break;
		}
		CurrentStringHand += _ConvertChar(IndexFourOfAKind.at(i));
		StringThree.push_back(CurrentStringHand);
	}

	std::sort(StringThree.rbegin(), StringThree.rend());

	int Count = 0;
	while (Count < IndexFourOfAKind.size())
	{
		RankList[StringThree[Count].at(1) - 48].Ranks = IndexStart;
		RankList[StringThree[Count].at(1) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand gom mot sam co va mot doi
void RankListFullHouse(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexFullHouse, int &IndexStart, int NoPlayer)
{
	RankListThreeOfAKind(RankList, EachPlayer, IndexFullHouse, IndexStart, NoPlayer);
}

//Xep hang nhung hand co cung chat
void RankListFlush(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexFlush, int &IndexStart, int NoPlayer)
{
	RankListNormal(RankList, EachPlayer, IndexFlush, IndexStart, NoPlayer);
}

//Xep hang nhung hand la nhung cai sanh
void RankListStraight(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexStraight, int &IndexStart, int NoPlayer)
{
	std::vector<std::string> StringMaxCard;

	for (int i = 0; i < IndexStraight.size(); i++)
	{
		std::string CurrentStringHand = "";

		CurrentStringHand += _ConvertChar(EachPlayer[IndexStraight.at(i)][0].Faces);
		CurrentStringHand += _ConvertChar(IndexStraight.at(i));
		StringMaxCard.push_back(CurrentStringHand);
	}

	std::sort(StringMaxCard.rbegin(), StringMaxCard.rend());

	int Count = 0;
	while (Count < IndexStraight.size())
	{
		RankList[StringMaxCard[Count].at(1) - 48].Ranks = IndexStart;
		RankList[StringMaxCard[Count].at(1) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand chi la sam co
void RankListThreeOfAKind(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexThreeOfAKind, int &IndexStart, int NoPlayer)
{
	int CountFace[MAXPLAYERS][FACES + 1] = { 0 };//FACES + 1 vi luu them so 13 <=> Ace

	for (int i = 0; i < IndexThreeOfAKind.size(); i++)
	for (int j = 0; j < KCARDS; j++)
		CountFace[i][EachPlayer[IndexThreeOfAKind.at(i)][j].Faces]++;

	std::vector<std::string> StringThree;

	for (int i = 0; i < IndexThreeOfAKind.size(); i++)
	{
		std::string CurrentStringHand = "";

		for (int j = FACES - 1 + 1; j >= 0; j--)//FACES + 1 vi luu them so 13 <=> Ace
		if (CountFace[i][j] == 3)
		{
			CurrentStringHand += _ConvertChar(j);
			break;
		}
		CurrentStringHand += _ConvertChar(IndexThreeOfAKind.at(i));
		StringThree.push_back(CurrentStringHand);
	}

	std::sort(StringThree.rbegin(), StringThree.rend());

	int Count = 0;
	while (Count < IndexThreeOfAKind.size())
	{
		RankList[StringThree[Count].at(1) - 48].Ranks = IndexStart;
		RankList[StringThree[Count].at(1) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand gom hai doi
void RankListTwoPairs(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexTwoPairs, int &IndexStart, int NoPlayer)
{
	int CountFace[MAXPLAYERS][FACES + 1] = { 0 };

	for (int i = 0; i < IndexTwoPairs.size(); i++)
	for (int j = 0; j < KCARDS; j++)
		CountFace[i][EachPlayer[IndexTwoPairs.at(i)][j].Faces]++;

	std::vector<std::string> StringHand;

	for (int i = 0; i < IndexTwoPairs.size(); i++)
	{
		std::string CurrentStringHand = "";

		for (int j = FACES - 1 + 1; j >= 0; j--)
		if (CountFace[i][j] == 2)
			CurrentStringHand += _ConvertChar(j);

		for (int j = 0; j < FACES + 1; j++)
		if (CountFace[i][j] == 1)
		{
			CurrentStringHand += _ConvertChar(j);
			CurrentStringHand += _ConvertChar(IndexTwoPairs.at(i));
			break;
		}

		StringHand.push_back(CurrentStringHand);
	}

	std::sort(StringHand.rbegin(), StringHand.rend());

	int Count = 0;
	while (Count < IndexTwoPairs.size())
	{
		RankList[StringHand[Count].at(KCARDS - 2) - 48].Ranks = IndexStart;
		RankList[StringHand[Count].at(KCARDS - 2) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand chi mot doi
void RankListPair(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexPair, int &IndexStart, int NoPlayer)
{
	int CountFace[MAXPLAYERS][FACES + 1] = { 0 };//FACES + 1 vi luu them so 13 <=> Ace

	for (int i = 0; i < IndexPair.size(); i++)
	for (int j = 0; j < KCARDS; j++)
		CountFace[i][EachPlayer[IndexPair.at(i)][j].Faces]++;

	std::vector<std::string> StringHand;

	for (int i = 0; i < IndexPair.size(); i++)
	{	
		std::string CurrentStringHand = "";
		for (int j = 0; j < FACES + 1; j++)//FACES + 1 vi luu them so 13 <=> Ace
		if (CountFace[i][j] == 2)
		{
			CurrentStringHand += _ConvertChar(j);
			break;
		}
		for (int j = FACES - 1 + 1; j >= 0; j--)//FACES + 1 vi luu them so 13 <=> Ace
		if (CountFace[i][j] == 1)
			CurrentStringHand += _ConvertChar(j);
		CurrentStringHand += _ConvertChar(IndexPair.at(i));

		StringHand.push_back(CurrentStringHand);
	}

	std::sort(StringHand.rbegin(), StringHand.rend());

	int Count = 0;
	while (Count < IndexPair.size())
	{
		RankList[StringHand[Count].at(KCARDS - 1) - 48].Ranks = IndexStart;
		RankList[StringHand[Count].at(KCARDS - 1) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

//Xep hang nhung hand la dan den
void RankListNormal(Rank RankList[], Cards EachPlayer[][KCARDS], std::vector<int> IndexNormal, int &IndexStart, int NoPlayer)
{
	std::vector<std::string> StringHand;

	for (int i = 0; i < IndexNormal.size(); i++)
	{
		std::string CurrentStringHand = "";

		for (int j = 0; j < KCARDS; j++)
			CurrentStringHand += _ConvertChar(EachPlayer[i][j].Faces);
		CurrentStringHand += _ConvertChar(IndexNormal.at(i));

		StringHand.push_back(CurrentStringHand);
	}

	std::sort(StringHand.rbegin(), StringHand.rend());

	int Count = 0;
	while (Count < IndexNormal.size())
	{
		RankList[StringHand[Count].at(KCARDS) - 48].Ranks = IndexStart;
		RankList[StringHand[Count].at(KCARDS) - 48].Scores = NoPlayer - IndexStart - 1;
		IndexStart++;
		Count++;
	}
}

void StatisticStatus(Cards EachPlayer[][KCARDS], Rank RankList[], int NoPlayer)
{
	std::vector<int> IndexStraightFlush;
	std::vector<int> IndexFourOfAKind;
	std::vector<int> IndexFullHouse;
	std::vector<int> IndexFlush;
	std::vector<int> IndexStraight;
	std::vector<int> IndexThreeOfAKind;
	std::vector<int> IndexTwoPairs;
	std::vector<int> IndexPair;
	std::vector<int> IndexNormal;

	for (int i = 0; i < NoPlayer; i++)
	if (IsStraightFlush(EachPlayer[i]))
		IndexStraightFlush.push_back(i);
	else if (IsFourOfAKind(EachPlayer[i]))
		IndexFourOfAKind.push_back(i);
	else if (IsFullHouse(EachPlayer[i]))
		IndexFullHouse.push_back(i);
	else if (IsFlush(EachPlayer[i]))
		IndexFlush.push_back(i);
	else if (IsStraight(EachPlayer[i]))
		IndexStraight.push_back(i);
	else if (IsThreeOfAKind(EachPlayer[i]))
		IndexThreeOfAKind.push_back(i);
	else if (IsTwoPairs(EachPlayer[i]))
		IndexTwoPairs.push_back(i);
	else if (IsPair(EachPlayer[i]))
		IndexPair.push_back(i);
	else
		IndexNormal.push_back(i);

	for (int i = 0; i < NoPlayer; i++)
	{
		for (int j = 0; j < KCARDS; j++)
		if (EachPlayer[i][j].Faces == 0)
			EachPlayer[i][j].Faces = 13;
		std::sort(EachPlayer[i], EachPlayer[i] + KCARDS, _CompareFaces);
	}

	int IndexStart = 0;

	RankListStraightFlush(RankList, EachPlayer, IndexStraightFlush, IndexStart, NoPlayer);
	RankListFourOfAKind(RankList, EachPlayer, IndexFourOfAKind, IndexStart, NoPlayer);
	RankListFullHouse(RankList, EachPlayer, IndexFullHouse, IndexStart, NoPlayer);
	RankListFlush(RankList, EachPlayer, IndexFlush, IndexStart, NoPlayer);
	RankListStraight(RankList, EachPlayer, IndexStraight, IndexStart, NoPlayer);
	RankListThreeOfAKind(RankList, EachPlayer, IndexThreeOfAKind, IndexStart, NoPlayer);
	RankListTwoPairs(RankList, EachPlayer, IndexTwoPairs, IndexStart, NoPlayer);
	RankListPair(RankList, EachPlayer, IndexPair, IndexStart, NoPlayer);
	RankListNormal(RankList, EachPlayer, IndexNormal, IndexStart, NoPlayer);
}

void ShowRankList(Cards EachPlayer[][KCARDS], Rank RankList[], int NoPlayer)
{
	StatisticStatus(EachPlayer, RankList, NoPlayer);

	std::cout << "Player\tScores\tRank" << std::endl;

	for (int i = 0; i < NoPlayer; i++)
		std::cout << i + 1 << "\t" << RankList[i].Scores << "\t" << RankList[i].Ranks + 1 << std::endl;
	std::cout << std::endl;
}