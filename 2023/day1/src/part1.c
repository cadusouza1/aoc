#include "search.h"
#include <stdio.h>

void part1(FILE *input) {
    char *line = NULL;
    size_t n = 0;

    int right_number_index, right_number;
    int left_number_index, left_number;
    int total_sum = 0;

    while (!feof(input)) {
        getline(&line, &n, input);

        left_number_index = lsearch_int(line);
        if (left_number_index == -1) {
            continue;
        }

        right_number_index = rsearch_int(line);
        if (right_number_index == -1) {
            continue;
        }

        left_number = line[left_number_index] - '0';
        right_number = line[right_number_index] - '0';

        total_sum += 10 * left_number + right_number;
    }

    // Take care of a duplicate reading of the last line
    total_sum -= 10 * left_number + right_number;

    printf("%d\n", total_sum);
}
