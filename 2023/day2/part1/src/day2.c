#include "game.h"
#include <stdio.h>

#define MAX_RED_COUNT 12
#define MAX_GREEN_COUNT 13
#define MAX_BLUE_COUNT 14
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    Game g;
    int id_sum = 0, is_valid_game, i;

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        is_valid_game = 1;
        g = parse_game_from_line(line);

        for (i = 0; i < g.set_count; i++) {
            if (g.sets[i].red > MAX_RED_COUNT ||
                g.sets[i].green > MAX_GREEN_COUNT ||
                g.sets[i].blue > MAX_BLUE_COUNT) {
                is_valid_game = 0;
                break;
            }

            /* printf("g.sets[%d].red = %d (%d)\n", i, g.sets[i].red, */
            /*        MAX_RED_COUNT); */
            /* printf("g.sets[%d].green = %d (%d)\n", i, g.sets[i].green, */
            /*        MAX_GREEN_COUNT); */
            /* printf("g.sets[%d].blue = %d (%d)\n", i, g.sets[i].blue, */
            /*        MAX_BLUE_COUNT); */
            /* printf("\n"); */
        }

        if (is_valid_game) {
            id_sum += g.id;
        }
    }

    printf("id_sum = %d\n", id_sum);
    return 0;
}
