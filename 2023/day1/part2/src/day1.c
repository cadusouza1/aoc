#include "search.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 64

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];

    int right_number = 0, left_number = 0;
    int total_sum = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
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

    printf("%d\n", total_sum);
    return 0;
}
