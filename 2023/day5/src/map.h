#define MAX_RANGE_LEN 16

typedef struct {
    int destination_start;
    int source_start;
    int len;
} Range;

typedef struct {
    int len;
    Range *ranges;
} Map;

Map *map_init(int size);
Map *parse_map_from_lines(char **lines, int start, int end);
int convert_source_to_destination(int src, Map *map);
