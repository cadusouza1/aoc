#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARDS 205

void part2(FILE *input) {
    size_t n = 0;
    char *line = NULL;
    int i = 0, j = 0, matches;

    Card *cards[NUM_CARDS];
    Card *current_card;
    int num_cards_instances[NUM_CARDS];
    int sum_num_cards_instances = 0;

    while ((getline(&line, &n, input)) > -1) {
        line = strsep(&line, "\n");
        current_card = parse_card_line(line);

        if (current_card == NULL) {
            continue;
        }

        cards[i] = current_card;
        num_cards_instances[i] = 1;
        i++;
    }

    for (i = 0; i < NUM_CARDS - 1; i++) {
        matches = get_num_matches(cards[i]);

        for (j = i + 1; j < i + 1 + matches && j < NUM_CARDS; j++) {
            num_cards_instances[j] += num_cards_instances[i];
        }
    }

    for (i = 0; i < NUM_CARDS; i++) {
        sum_num_cards_instances += num_cards_instances[i];
    }

    printf("sum_num_cards_instances = %d\n", sum_num_cards_instances);
}
