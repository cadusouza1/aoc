#include "card.h"
#include "hand.h"
#include <stdio.h>

#define MAX_LINE_LEN 64
#define MAX_HAND_COUNT 8

int main(int argc, char *argv[]) {
    char raw_card[6];
    int bid, i, j;
    Hand *hands[MAX_HAND_COUNT];
    Card *card;

    for (i = 0;
         fscanf(stdin, "%s %d\n", raw_card, &bid) != EOF && i < MAX_HAND_COUNT;
         i++) {
        card = parse_cards_from_string(raw_card);
        if (card == NULL) {
            break;
        }

        hands[i] = hand_new(card, bid);
    }

    return 0;
}
