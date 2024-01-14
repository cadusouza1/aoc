#include "search.h"
#include <stdio.h>

void part2(FILE *input) {
    /* char *nums = "1zero one two3"; */
    /* int d = lget_int_with_name(nums); */
    /* int d2 = rget_int_with_name(nums); */

    /* printf("d = %d\n", d); */
    /* printf("d2 = %d\n", d2); */
    char *line = NULL;
    size_t n = 0;

    int right_number = 0, left_number = 0;
    int total_sum = 0;

    while (!feof(input)) {
        getline(&line, &n, input);

        left_number = lget_int_with_name(line);
        if (left_number == -1) {
            continue;
        }

        right_number = rget_int_with_name(line);
        if (right_number == -1) {
            continue;
        }

        total_sum += 10 * left_number + right_number;
    }

    // Take care of a duplicate reading of the last line
    total_sum -= 10 * left_number + right_number;

    printf("%d\n", total_sum);
}
