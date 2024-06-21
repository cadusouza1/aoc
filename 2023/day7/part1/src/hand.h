#pragma once 

#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FIVE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD
} HandType;

typedef struct {
    Card cards[CARD_COUNT];
    HandType type;
} Hand;

HandType get_hand_type(Card cards[]);
Hand *hand_new(Card cards[], int bid);
