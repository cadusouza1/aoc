#include "game.h"
#include <stdio.h>
#include <string.h>

void part2(FILE *input) {
    size_t n = 0;
    char *line = NULL;
    Game g;
    int power = 0;
    int power_sum = 0;

    while (getline(&line, &n, input) > -1) {
        line = strsep(&line, "\n");

        g = parse_game_from_line(line);

        power = power_set(get_minimum_set(g.sets, g.set_count));
        power_sum += power;
    }

    printf("power_sum = %d\n", power_sum);
}
