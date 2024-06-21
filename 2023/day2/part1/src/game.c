#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SET_COUNT 16
#define MAX_COLORNAME_LEN 5

typedef struct {
    int red;
    int blue;
    int green;
} ColorCounts;

typedef struct {
    int id;
    int set_count;
    ColorCounts sets[MAX_SET_COUNT];
} Game;

ColorCounts parse_raw_color_count(char *raw_color_count) {
    ColorCounts counts;
    char *color_and_count;
    char color[MAX_COLORNAME_LEN];
    int count;

    counts.red = 0;
    counts.green = 0;
    counts.blue = 0;

    /* printf("raw_color_count = %s\n", raw_color_count); */
    color_and_count = strtok(raw_color_count, ",");
    do {
        /* Removing the first whitespace character from the str */
        color_and_count++;

        sscanf(color_and_count, "%d %s", &count, color);
        /* printf("color_and_count = %s\n", color_and_count); */
        /* printf("(color, count) = (%s, %d)\n", color, count); */

        if (strcmp(color, "red") == 0) {
            counts.red = count;
        }

        if (strcmp(color, "green") == 0) {
            counts.green = count;
        }

        if (strcmp(color, "blue") == 0) {
            counts.blue = count;
        }
    } while ((color_and_count = strtok(NULL, ",")));
    /* printf("counts.red = %d\n", counts.red); */
    /* printf("counts.green = %d\n", counts.green); */
    /* printf("counts.blue = %d\n", counts.blue); */
    /* printf("\n"); */

    return counts;
}

Game parse_game_from_line(char *line) {
    Game g;
    char *game_rgb_info;
    char *game_cards_start = strstr(line, ": ") + 1;
    int game_id_start_index = strlen("Game ");

    g.id = strtol(line + game_id_start_index, NULL, 10);
    g.set_count = 0;

    for (game_rgb_info = strtok(game_cards_start, ";"); game_rgb_info != NULL;
         game_rgb_info = strtok(NULL, ";")) {
        printf("game_rgb_info = %s\n", game_rgb_info);
        g.sets[g.set_count] = parse_raw_color_count(game_rgb_info);
        g.set_count++;
    }
    printf("g.set_count = %d\n", g.set_count);

    return g;
}

ColorCounts get_minimum_set(ColorCounts counts[], int len) {
    ColorCounts minimum;
    int i;
    minimum.red = 0;
    minimum.green = 0;
    minimum.blue = 0;

    for (i = 0; i < len; i++) {
        if (counts[i].red > minimum.red) {
            minimum.red = counts[i].red;
        }

        if (counts[i].green > minimum.green) {
            minimum.green = counts[i].green;
        }

        if (counts[i].blue > minimum.blue) {
            minimum.blue = counts[i].blue;
        }
    }

    return minimum;
}

int power_set(ColorCounts count) {
    return count.red * count.green * count.blue;
}
