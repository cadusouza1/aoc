#pragma once
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

Seeds *seeds_init(int size);
Seeds *parse_seeds_from_str(char *str);
