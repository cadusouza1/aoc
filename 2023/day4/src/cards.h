#pragma once

typedef struct {
    int winning_numbers_size;
    int *winning_numbers;
    int numbers_size;
    int *numbers;
} Card;

Card *parse_card_line(char *line);
int get_total_points(Card *card);
