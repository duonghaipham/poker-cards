#include "struct.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define KCARDS 5
#define MAXPLAYERS 10

//Ham xao bai
void DealCards(Cards DeckShuffled[]);	

//Ham chia bai cho tung nguoi mot
void DealHands(Cards DeckShuffled[], Cards EachPlayer[][KCARDS], int NoPlayer);

//Ham show bai cua tung nguoi
void ShowCards(Cards EachPlayer[][KCARDS], int NoPlayer);

//Ham xep hang nguoi choi
void ShowRankList(Cards EachPlayer[][KCARDS], Rank RankList[], int NoPlayer);

//Ham chon che do game la binh thuong
void ModeNormal(Cards DeckShuffled[], Cards EachPlayer[][KCARDS], Rank RankList[]);

//Ham chon che do choi voi nha cai
void ModeDealer();