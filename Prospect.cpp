#include <algorithm>
#include "struct.h"

#define SUITS 4
#define FACES 13
#define CARDS 52
#define KCARDS 5

bool _CompareStruct(Cards lhs, Cards rhs)
{
	return lhs.Faces < rhs.Faces;
}

bool IsFlush(Cards CurrentPlayer[])
{
	for (int i = 0; i < KCARDS - 1; i++)
	if (CurrentPlayer[i].Suits != CurrentPlayer[i + 1].Suits)
		return 0;
	return 1;
}

bool IsStraight(Cards CurrentPlayer[])//Can sua lai
{
	std::sort(CurrentPlayer, CurrentPlayer + KCARDS, _CompareStruct);

	int Face = CurrentPlayer[0].Faces;

	for (int i = 1; i < KCARDS; i++)
	if (Face == CurrentPlayer[i].Faces - 1)
		Face++;
	else
		return false;
	return true;
}

bool IsStraightFlush(Cards CurrentPlayer[])
{
	return IsStraight(CurrentPlayer) && IsFlush(CurrentPlayer);
}

bool IsFourOfAKind(Cards CurrentPlayer[])
{
	int CountFace[FACES] = { 0 };

	for (int i = 0; i < KCARDS; i++)
		CountFace[CurrentPlayer[i].Faces]++;	//dung mang danh dau de tim tan so

	for (int i = 0; i < FACES; i++)
	if (CountFace[i] == 4)
		return 1;
	return 0;
}

bool IsFullHouse(Cards CurrentPlayer[])
{
	int CountFace[FACES] = { 0 };

	for (int i = 0; i < KCARDS; i++)
		CountFace[CurrentPlayer[i].Faces]++;

	bool Flag2 = false, Flag3 = false;

	for (int i = 0; i < FACES; i++)
	if (CountFace[i] == 3)
		Flag3 = true;
	else if (CountFace[i] == 2)
		Flag2 = true;

	return (Flag2 && Flag3) ? true : false;
}

bool IsThreeOfAKind(Cards CurrentPlayer[])
{
	int CountFace[FACES] = { 0 };

	for (int i = 0; i < KCARDS; i++)
		CountFace[CurrentPlayer[i].Faces]++;

	for (int i = 0; i < FACES; i++)
	if (CountFace[i] == 3)
		return 1;
	return 0;
}

bool IsTwoPairs(Cards CurrentPlayer[])
{
	int CountFace[FACES] = { 0 };

	for (int i = 0; i < KCARDS; i++)
		CountFace[CurrentPlayer[i].Faces]++;

	int Found = 0;
	int Face = 0;

	for (int i = 0; i < FACES; i++)
	if (CountFace[i] == 2)
	{
		Found++;
		Face = i;
	}

	return (Found == 2) ? true : false;
}

bool IsPair(Cards CurrentPlayer[])
{
	int CountFace[FACES] = { 0 };

	for (int i = 0; i < KCARDS; i++)
		CountFace[CurrentPlayer[i].Faces]++;

	int Found = 0;
	int Face = 0;

	for (int i = 0; i < FACES; i++)
	if (CountFace[i] == 2)
		return true;
	return false;
}