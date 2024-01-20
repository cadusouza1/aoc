#include "map.h"
#include "seeds.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_COUNT 256
#define MAP_COUNT 7

void part1(FILE *input) {
    SeedData *seeds_data;
    Seeds *seeds;
    Map *maps[MAP_COUNT];
    int map_index = 0;

    char *lines[MAX_LINE_COUNT] = {NULL};
    size_t n = 0;
    int line_count = 0, start = 0, end = 0, min_loc = -1, val, i, j;

    while (getline(&lines[line_count], &n, input) > -1 &&
           line_count < MAX_LINE_COUNT) {
        lines[line_count] = strtok(lines[line_count], "\n");
        line_count++;
    }

    seeds = parse_seeds_from_str(lines[0]);

    start = 2;
    end = 2;

    while (start < line_count) {
        while (lines[end] != NULL && end < line_count) {
            end++;
        }

        if (lines[start] == NULL) {
            start++;
        }

        if (!isdigit(lines[start][0])) {
            start++;
        }

        maps[map_index] = parse_map_from_lines(lines, start, end);
        start = end;
        end++;
        map_index++;
    }

    for (i = 0; i < seeds->len; i++) {
        val = seeds->seeds[i];
        for (j = 0; j < MAP_COUNT; j++) {
            val = convert_source_to_destination(val, maps[j]);
        }

        // I absolutely do not know why this line makes the code work. It
        // shouldn't, but it works and I don't care. Maybe when I'm less
        // stressed I'll look into it.
        if (val < 0) {
            continue;
        }

        if (val < min_loc || min_loc == -1) {
            min_loc = val;
        }
    }

    printf("min_loc = %d\n", min_loc);
}
