#include "map.h"
#include "seeds.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINE_COUNT 256
#define MAP_COUNT 7

void part2(FILE *input) {
    ParseSeedsRangeResult *result;
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

    result = parse_seed_range_from_str(lines[0], MAX_SEEDS_SIZE);

    for (i = 0; i < result->len; i++) {
        printf("(result->ranges[%d].start, result->ranges[%d].len) = (%d, "
               "%d)\n",
               i, i, result->ranges[i].start, result->ranges[i].len);
    }

    /* start = 2; */
    /* end = 2; */

    /* while (start < line_count) { */
    /*     while (lines[end] != NULL && end < line_count) { */
    /*         end++; */
    /*     } */

    /*     if (lines[start] == NULL) { */
    /*         start++; */
    /*     } */

    /*     if (!isdigit(lines[start][0])) { */
    /*         start++; */
    /*     } */

    /*     maps[map_index] = parse_map_from_lines(lines, start, end); */
    /*     start = end; */
    /*     end++; */
    /*     map_index++; */
    /* } */

    /* printf("min_loc = %d\n", min_loc); */
}
