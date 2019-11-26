#include <string>
#include <iostream>
#include "struct.h"

#define SUITS 4
#define FACES 13
#define CARDS 52
#define KCARDS 5

//Ham chia bai cho NoPlayer nguoi choi
void DealHands(Cards DeckShuffled[], Cards EachPlayer[][KCARDS],int NoPlayer)
{
	int i = 0;
	int CurrentCard = 0;

	while (i < KCARDS)	//chia lan luot tung la cho tung nguoi mot theo vong tron
	{
		for (int j = 0; j < NoPlayer; j++)
		{
			EachPlayer[j][i].Suits = DeckShuffled[CurrentCard].Suits;
			EachPlayer[j][i].Faces = DeckShuffled[CurrentCard].Faces;
			CurrentCard++;
		}
		i++;
	}
}

//Ham chuyen tu gia tri Faces sang string lan in ra ngoai
std::string _ConvertFaces(int Faces)
{
	switch (Faces)
	{
	case 0:
		return "Ace";
	case 1:
		return "Deuce";
	case 2:
		return "Three";
	case 3:
		return "Four";
	case 4:
		return "Five";
	case 5:
		return "Six";
	case 6:
		return "Seven";
	case 7:
		return "Eight";
	case 8:
		return "Nine";
	case 9:
		return "Ten";
	case 10:
		return "Jack";
	case 11:
		return "Queen";
	default:
		return "King";
	}
}

//Ham chuyen tu gia tri Suits sang string de in ra ngoai
std::string _ConvertSuits(int Suits)
{
	switch (Suits)
	{
	case 0:
		return "Hearts";
	case 1:
		return "Diamond";
	case 2:
		return "Clubs";
	default:
		return "Spades";
	}
}

//Ham show ra bai cua tat ca NoPlayer nguoi choi
void ShowCards(Cards EachPlayer[][KCARDS], int NoPlayer)
{
	Cards tmpCard[KCARDS] = { 0, 0 };

	for (int i = 0; i < NoPlayer; i++)
	{
		std::cout << "* PLAYER " << i + 1 << ":" << std::endl;
		for (int j = 0; j < KCARDS; j++)
		{
			std::cout << _ConvertSuits(EachPlayer[i][j].Suits) << (char)32;
			std::cout << _ConvertFaces(EachPlayer[i][j].Faces) << std::endl;
		}
		std::cout << std::endl;
	}
}