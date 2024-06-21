#include <stdio.h>
#include <stdlib.h>
#define CARD_COUNT 5

typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    T,
    J,
    Q,
    K,
    A
} Card;

Card *parse_cards_from_string(char *str) {
    int i;
    Card *cards = calloc(CARD_COUNT, sizeof(Card));

    if (cards == NULL) {
        fprintf(stderr, "Couldn't allocate memory for cards'\n");
        return NULL;
    }

    for (i = 0; i < CARD_COUNT; i++) {
        switch (str[i]) {
        case '2':
            cards[i] = TWO;
            break;
        case '3':
            cards[i] = THREE;
            break;
        case '4':
            cards[i] = FOUR;
            break;
        case '5':
            cards[i] = FIVE;
            break;
        case '6':
            cards[i] = SIX;
            break;
        case '7':
            cards[i] = SEVEN;
            break;
        case '8':
            cards[i] = EIGHT;
            break;
        case '9':
            cards[i] = NINE;
            break;
        case 'T':
            cards[i] = T;
            break;
        case 'J':
            cards[i] = J;
            break;
        case 'Q':
            cards[i] = Q;
            break;
        case 'K':
            cards[i] = K;
            break;
        case 'A':
            cards[i] = A;
            break;
        default:
            fprintf(stderr, "Unrecognized char %c\n", str[i]);
            return NULL;
        }
    }

    return cards;
}
