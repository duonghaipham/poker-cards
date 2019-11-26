#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "struct.h"

#define SUITS 4
#define FACES 13
#define CARDS 52

void _ShuffleVector(std::vector<int> &VectorIndex) //khoi tao va tron vector
{
	VectorIndex.clear();

	for (int i = 1; i <= 52; i++)
		VectorIndex.push_back(i);

	std::random_shuffle(VectorIndex.begin(), VectorIndex.end());

	//ham tron cac phan tu cua vector
}

void ShuffleCards(int Deck[][FACES]) //tron nguyen bo bai
{
	std::vector<int> VectorIndex;

	_ShuffleVector(VectorIndex);

	for (int i = 0; i < SUITS; i++)
	for (int j = 0; j < FACES; j++)
	{
		Deck[i][j] = VectorIndex.back();
		VectorIndex.pop_back();
	}
}

void DealCards(Cards DeckShuffled[])
{
	int Deck[SUITS][FACES] = { 0 };

	ShuffleCards(Deck);

	int RightOrder = 1;

	do
	{
		bool Found = false;

		for (int i = 0; i < SUITS; i++)
		{
			for (int j = 0; j < FACES; j++)
			if (Deck[i][j] == RightOrder)
			{
				DeckShuffled[RightOrder - 1].Suits = i;
				DeckShuffled[RightOrder - 1].Faces = j;
				Found = true;
				RightOrder++;
				break;
			}
			if (Found)
				break;
		}
	} while (RightOrder <= CARDS);
}