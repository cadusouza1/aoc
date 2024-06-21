#include "game.h"
#include <stdio.h>
#include <string.h>

#define MAX_RED_COUNT 12
#define MAX_GREEN_COUNT 13
#define MAX_BLUE_COUNT 14

void part1(FILE *input) {
    size_t n = 0;
    char *line = NULL;
    Game g;
    int id_sum = 0;
    int is_valid_game;

    while (getline(&line, &n, input) > -1) {
        line = strsep(&line, "\n");

        is_valid_game = 1;
        g = parse_game_from_line(line);

        for (int i = 0; i < g.set_count; i++) {
            if (g.sets[i].red > MAX_RED_COUNT ||
                g.sets[i].green > MAX_GREEN_COUNT ||
                g.sets[i].blue > MAX_BLUE_COUNT) {
                is_valid_game = 0;
                break;
            }
        }

        if (is_valid_game) {
            id_sum += g.id;
        }
    }

    printf("id_sum = %d\n", id_sum);
}
