#include "struct.h"

//Ham kiem tra xem co cung chat hay khong
bool IsFlush(Cards CurrentPlayer[]);

//Ham kiem tra coi no phai cai sanh hay khong
bool IsStraight(Cards CurrentPlayer[]);

//Ham kiem tra xem no phai cai sanh va cung chat hay khong
bool IsStraightFlush(Cards CurrentPlayer[]);

//Ham kiem tra xem hand phai tu qui hay khong
bool IsFourOfAKind(Cards CurrentPlayer[]);

//Ham kiem tra xem hand co gom mot sam co va mot doi
bool IsFullHouse(Cards CurrentPlayer[]);

//Ham kiem tra xem no co la sam co hay khong
bool IsThreeOfAKind(Cards CurrentPlayer[]);

//Ham kiem tra xem no co phai la hai doi hay khong
bool IsTwoPairs(Cards CurrentPlayer[]);

//Ham kiem tra xem no chi co mot doi hay khong
bool IsPair(Cards CurrentPlayer[]);