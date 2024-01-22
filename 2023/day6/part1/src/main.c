#include "race.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_CHARS 128
#define MAX_NUMS_LEN 4
#define ACCELERATION 1

void parse_line(char *line, int *result, int *size) {
    int numbers_start_index = 0, _size = 0;
    char *_line;

    while (!(isdigit(line[numbers_start_index]))) {
        numbers_start_index++;
    }

    _line = line + numbers_start_index;
    _line = strtok(_line, " ");
    while (_line != NULL) {
        result[_size] = strtol(_line, NULL, 10);

        _line = strtok(NULL, " ");
        _size++;
    }

    *size = _size;
}

int main(int argc, char *argv[]) {
    char line_time[MAX_LINE_CHARS];
    int time_result[MAX_NUMS_LEN], time_size, time_start_index = 0;

    char line_distance[MAX_LINE_CHARS];
    int distance_result[MAX_NUMS_LEN], distance_size, distance_start_index = 0;

    int minimum_winning_time, maximum_winning_time;

    int winning_ways_count = 1, i;
    fgets(line_time, MAX_LINE_CHARS, stdin);
    fgets(line_distance, MAX_LINE_CHARS, stdin);

    parse_line(line_time, time_result, &time_size);
    parse_line(line_distance, distance_result, &distance_size);

    for (i = 0; i < time_size; i++) {
        minimum_winning_time = get_minimum_winning_time(
            ACCELERATION, time_result[i], distance_result[i]);
        maximum_winning_time = get_maximum_winning_time(
            ACCELERATION, time_result[i], distance_result[i]);

        winning_ways_count *= maximum_winning_time - minimum_winning_time + 1;
    }

    printf("winning_ways_count = %d\n", winning_ways_count);
    /* minimum_winning_time = */
    /*     get_minimun_winning_time(1, time_result[0], distance_result[0]); */

    /* maximum_winning_time = */
    /*     get_maximun_winning_time(1, time_result[0], distance_result[0]); */

    /* printf("minimum_winning_time = %d\n", minimum_winning_time); */
    /* printf("maximum_winning_time = %d\n", maximum_winning_time); */
    return 0;
}
