#pragma once
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

Card *parse_cards_from_string(char *str);
