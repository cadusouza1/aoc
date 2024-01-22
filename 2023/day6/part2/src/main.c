#include "race.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_CHARS 128
#define MAX_NUM_LEN 4
#define ACCELERATION 1

int64_t parse_line(char *line) {
    int numbers_start_index = 0;
    char *_line;
    char result[MAX_LINE_CHARS] = {0};

    while (!(isdigit(line[numbers_start_index]))) {
        numbers_start_index++;
    }

    _line = line + numbers_start_index;
    _line = strtok(_line, " ");
    while (_line != NULL) {
        strncat(result, _line, MAX_NUM_LEN);
        _line = strtok(NULL, " ");
    }

    return strtol(result, NULL, 10);
}

int main(int argc, char *argv[]) {
    char line_time[MAX_LINE_CHARS];
    int64_t max_time;

    char line_distance[MAX_LINE_CHARS];
    int64_t max_distance;

    int64_t minimum_winning_time, maximum_winning_time;

    fgets(line_time, MAX_LINE_CHARS, stdin);
    fgets(line_distance, MAX_LINE_CHARS, stdin);

    max_time = parse_line(line_time);
    max_distance = parse_line(line_distance);

    maximum_winning_time =
        get_maximum_winning_time(ACCELERATION, max_time, max_distance);

    minimum_winning_time =
        get_minimum_winning_time(ACCELERATION, max_time, max_distance);

    printf("winnig ways = %ld\n",
           maximum_winning_time - minimum_winning_time + 1);
    return 0;
}
