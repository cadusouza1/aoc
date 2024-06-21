#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(char *s, int start, int end) {
    int len = end - start;
    char *subst = malloc(sizeof(char) * (len + 1));

    if (subst == NULL) {
        fprintf(stderr, "Could not allocate memory for substr of %s creation\n",
                s);
        return NULL;
    }

    memcpy(subst, s, len);
    subst[len + 1] = '\0';

    return subst;
}

int spelled_digit_to_digit(char *s) {
    char *spelled_numbers[] = {"zero", "one", "two",   "three", "four",
                               "five", "six", "seven", "eight", "nine"};
    int num_len = 0, possible_number_index = 0, i;
    char *subst;

    for (i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
        case 'z':
            possible_number_index = 0;
            break;
        case 'o':
            possible_number_index = 1;
            break;
        case 't':
            switch (s[i + 1]) {
            case 'w':
                possible_number_index = 2;
                break;
            case 'h':
                possible_number_index = 3;
                break;
            }
            break;
        case 'f':
            switch (s[i + 1]) {
            case 'o':
                possible_number_index = 4;
                break;
            case 'i':
                possible_number_index = 5;
                break;
            }
            break;
        case 's':
            switch (s[i + 1]) {
            case 'i':
                possible_number_index = 6;
                break;
            case 'e':
                possible_number_index = 7;
                break;
            }
            break;
        case 'e':
            possible_number_index = 8;
            break;
        case 'n':
            possible_number_index = 9;
            break;
        }

        num_len = strlen(spelled_numbers[possible_number_index]);
        subst = substr(s, i, i + num_len);

        if (possible_number_index != -1) {
            if (strcmp(subst, spelled_numbers[possible_number_index]) == 0) {
                return possible_number_index;
            }
        }
    }

    return -1;
}

int lget_int_with_name(char *line) {
    int i;
    int digit;

    for (i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        }

        digit = spelled_digit_to_digit(line + i);

        if (digit != -1) {
            return digit;
        }
    }

    return -1;
}

int rget_int_with_name(char *line) {
    int i;
    int digit;

    for (i = strlen(line) - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        }

        digit = spelled_digit_to_digit(line + i);

        if (digit != -1) {
            return digit;
        }
    }

    return -1;
}
