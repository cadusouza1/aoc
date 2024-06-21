#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEEDS_SIZE 64

typedef struct {
    int len;
    int *seeds;
} Seeds;

typedef struct {
    int start, end;
} SeedsRange;

Seeds *seeds_init(int size) {
    Seeds *map = malloc(sizeof(Seeds));
    if (map == NULL) {
        fprintf(stderr, "Couldn't allocate memory for Seeds structure\n");
        return NULL;
    }

    map->len = 0;
    map->seeds = calloc(size, sizeof(int));

    if (map->seeds == NULL) {
        fprintf(stderr, "Couldn't allocate memory for Map's ranges\n");
        return NULL;
    }

    return map;
}

void seeds_realoc(Seeds *seeds, int new_size) {
    Seeds *new = realloc(seeds, sizeof(Seeds) * new_size);

    if (new == NULL) {
        fprintf(stderr, "Could not reallocate Seeds memory\n");
        return;
    }

    if (new != seeds) {
        seeds = new;
    }
}

Seeds *parse_seeds_from_str(char *str) {
    Seeds *s = seeds_init(MAX_SEEDS_SIZE);
    s->len = 0;
    char *raw_nums;

    if (s == NULL) {
        return NULL;
    }

    raw_nums = strtok(str, ": ");
    while ((raw_nums = strtok(NULL, " ")) != NULL) {
        if (s->len == MAX_SEEDS_SIZE) {
            fprintf(stderr, "Reached max seed size of %d seeds\n",
                    MAX_SEEDS_SIZE);
            break;
        }

        s->seeds[s->len] = atoi(raw_nums);

        s->len++;
    }

    return s;
}

typedef struct {
    int len;
    SeedsRange *ranges;
} ParseSeedsRangeResult;

ParseSeedsRangeResult *parse_seed_range_from_str(char *str, int size) {
    ParseSeedsRangeResult *result = malloc(sizeof(ParseSeedsRangeResult));
    char *raw_nums;

    if (result == NULL) {
        fprintf(stderr,
                "Could not allocate memory from ParseSeedsRangeResult\n");
        return NULL;
    }

    result->ranges = calloc(size, sizeof(SeedsRange));
    result->len = 0;

    if (result->ranges == NULL) {
        fprintf(stderr, "Could not allocate memory from SeedsRange array\n");
        return NULL;
    }

    raw_nums = strtok(str, ": ");
    while (1) {
        if (result->len == size) {
            fprintf(stderr, "Reached max ranges size of %d ranges\n", size);
            return result;
        }

        raw_nums = strtok(NULL, " ");
        if (raw_nums == NULL) {
            break;
        }

        printf("raw_nums = %s\n", raw_nums);
        result->ranges[result->len].start = strtol(raw_nums, NULL, 10);
        printf("r = %d\n", result->ranges[result->len].start);

        raw_nums = strtok(NULL, " ");
        if (raw_nums == NULL) {
            break;
        }

        result->ranges[result->len].end =
            result->ranges[result->len].start + strtol(raw_nums, NULL, 10);

        result->len++;
    }

    return result;
}
