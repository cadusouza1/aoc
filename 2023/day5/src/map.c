#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RANGE_LEN 36

typedef struct {
    int destination_start;
    int source_start;
    int len;
} Range;

typedef struct {
    int len;
    Range **ranges;
} Map;

int max(int x, int y) {
    if (x > y) {
        return x;
    }

    return y;
}

int min(int x, int y) {
    if (x < y) {
        return x;
    }

    return y;
}

Map *map_init(int size) {
    Map *map = malloc(sizeof(Map));
    if (map == NULL) {
        fprintf(stderr, "Couldn't allocate memory for Map structure\n");
        return NULL;
    }

    map->len = 0;
    map->ranges = calloc(size, sizeof(Range *));

    if (map->ranges == NULL) {
        fprintf(stderr, "Couldn't allocate memory for Map's ranges\n");
        return NULL;
    }

    return map;
}

Range *parse_range_from_line(char *line) {
    Range *r = malloc(sizeof(Range));

    if (r == NULL) {
        fprintf(stderr, "Couldn't allocate memory for Range struct'\n");
        return NULL;
    }

    r->destination_start = atoi(strtok(line, " "));
    r->source_start = atoi(strtok(NULL, " "));
    r->len = atoi(strtok(NULL, " "));
    return r;
}

Map *parse_map_from_lines(char **lines, int start, int end) {
    Map *map = map_init(MAX_RANGE_LEN);
    int i;

    for (i = start; i < end; i++) {
        map->ranges[map->len] = parse_range_from_line(lines[i]);
        if (map->ranges[map->len] == NULL) {
            return NULL;
        }

        map->len++;
    }

    return map;
}

int convert_source_to_destination(int src, Map *map) {
    int i, j, map_src, src_dest_diff, dest = src, max_num, min_num;

    for (i = 0; i < map->len; i++) {
        map_src = map->ranges[i]->source_start + map->ranges[i]->len - src;
        /* printf("map->ranges[%d].source_start = %d\n", i, */
        /*        map->ranges[i].source_start); */
        /* printf("map->ranges[%d].destination_start = %d\n", i, */
        /*        map->ranges[i].destination_start); */
        /* printf("map->ranges[%d].len = %d\n", i, map->ranges[i].len); */
        /* printf("map_src = %d\n", map_src); */

        if (map_src < 0) {
            continue;
        }

        if (map_src <= map->ranges[i]->len) {
            /* max_num = max(map->ranges[i]->source_start, */
            /*               map->ranges[i]->destination_start); */
            /* min_num = min(map->ranges[i]->source_start, */
            /*               map->ranges[i]->destination_start); */
            /* printf("max_num = %d\n", max_num); */
            /* printf("min_num = %d\n", min_num); */
            src_dest_diff = map->ranges[i]->destination_start -
                            map->ranges[i]->source_start;
            return src + src_dest_diff;
        }
    }

    return dest;
}
