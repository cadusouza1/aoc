#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lsearch_int(char *line) {
    int i;

    for (i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            return i;
        }
    }

    return -1;
}

int rsearch_int(char *line) {
    int i;

    for (i = strlen(line) - 1; line[i] != '\0'; i--) {
        if (isdigit(line[i])) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    FILE *f = fopen("input/input.txt", "r");
    char *line = NULL;
    size_t n = 0;

    int right_number_index, right_number;
    int left_number_index, left_number;
    int total_sum = 0;

    while (!feof(f)) {
        getline(&line, &n, f);

        left_number_index = lsearch_int(line);
        if (left_number_index == -1) {
            continue;
        }

        right_number_index = rsearch_int(line);
        if (right_number_index == -1) {
            continue;
        }

        printf("left_number_index = %d\n", left_number_index);
        printf("right_number_index = %d\n", right_number_index);

        left_number = line[left_number_index] - '0';
        right_number = line[right_number_index] - '0';

        int value = 10 * left_number + right_number;
        printf("value = %d\n", value);

        total_sum += 10 * left_number + right_number;
    }

    // Take care of a duplicate reading of the last line
    total_sum -= 10 * left_number + right_number;

    printf("%d\n", total_sum);
    return 0;
}
