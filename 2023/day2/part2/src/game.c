#include <stdlib.h>
#include <string.h>

#define MAX_SET_COUNT 16

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
    ColorCounts counts = {.red = 0, .green = 0, .blue = 0};
    char *color_count;
    char *color;
    int count;

    do {
        color_count = strsep(&raw_color_count, ",");

        // remove useless first whitespace
        strsep(&color_count, " ");

        count = atoi(strsep(&color_count, " "));
        color = color_count;

        if (strcmp(color, "red") == 0) {
            counts.red = count;
        }

        if (strcmp(color, "green") == 0) {
            counts.green = count;
        }

        if (strcmp(color, "blue") == 0) {
            counts.blue = count;
        }
    } while (raw_color_count);

    return counts;
}

Game parse_game_from_line(char *line) {
    Game g;
    g.set_count = 0;

    char *raw_game_id = strsep(&line, ":");
    char *game_str = strsep(&raw_game_id, " ");
    g.id = atoi(raw_game_id);

    char *game_rgb_info;

    while ((game_rgb_info = strsep(&line, ";"))) {
        g.sets[g.set_count] = parse_raw_color_count(game_rgb_info);
        g.set_count++;
    }

    return g;
}

ColorCounts get_minimum_set(ColorCounts counts[], int len) {
    ColorCounts minimum = {.red = 0, .green = 0, .blue = 0};

    for (int i = 0; i < len; i++) {
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
