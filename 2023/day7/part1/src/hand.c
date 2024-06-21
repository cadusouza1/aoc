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
    int bid;
    HandType type;
    Card cards[CARD_COUNT];
} Hand;

HandType get_hand_type(Card cards[]) { return -1; }

Hand *hand_new(Card cards[], int bid) {
    Hand *h = malloc(sizeof(Hand));

    if (h == NULL) {
        fprintf(stderr, "Couldn't allocate Hand'\n");
        return NULL;
    }

    memcpy(h->cards, cards, sizeof(Card) * CARD_COUNT);
    h->type = get_hand_type(h->cards);
    h->bid = bid;
    return h;
}
