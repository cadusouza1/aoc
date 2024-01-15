#pragma once

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

Game parse_game_from_line(char *line);
