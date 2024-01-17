#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part1(FILE *input) {
    size_t n = 0;
    int i;
    char *line = NULL;
    Card *card;
    int total_points = 0;

    while ((getline(&line, &n, input)) > -1) {
        line = strsep(&line, "\n");
        card = parse_card_line(line);

        if (card == NULL) {
            continue;
        }

        total_points += get_total_points(card);
    }

    printf("total_points = %d\n", total_points);
}
