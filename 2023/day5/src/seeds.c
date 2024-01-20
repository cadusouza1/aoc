#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEEDS_SIZE 32

typedef struct {
    int seed;
    int soil;
    int fertilizer;
    int water;
    int light;
    int temperature;
    int humidity;
    int location;
} SeedData;

typedef struct {
    int len;
    int *seeds;
} Seeds;

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
