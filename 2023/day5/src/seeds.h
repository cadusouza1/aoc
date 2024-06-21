#pragma once
#define MAX_SEEDS_SIZE 64

typedef struct {
    int len;
    int *seeds;
} Seeds;

typedef struct {
    int start, len;
} SeedsRange;

Seeds *seeds_init(int size);
Seeds *parse_seeds_from_str(char *str);

typedef struct {
    int len;
    SeedsRange *ranges;
} ParseSeedsRangeResult;
ParseSeedsRangeResult *parse_seed_range_from_str(char *str, int size);
