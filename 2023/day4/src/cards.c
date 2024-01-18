#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBERS_SIZE 25
#define WINNING_NUMBERS_SIZE 10

typedef struct {
    int winning_numbers_size;
    int *winning_numbers;
    int numbers_size;
    int *numbers;
} Card;

typedef struct {
    int *nums;
    int size;
} RawNumbersResult;

Card *card_init(int size) {
    Card *card = malloc(sizeof(Card));

    if (card == NULL) {
        fprintf(stderr, "Could not allocate memory for Card \n");
    }

    card->numbers_size = 0;
    card->winning_numbers_size = 0;

    return card;
}

RawNumbersResult *raw_numbers_init(int size) {
    RawNumbersResult *result = malloc(sizeof(RawNumbersResult));
    if (result == NULL) {
        fprintf(stderr, "Could not allocate memory to parse numbers\n");
        return NULL;
    }

    result->size = 0;
    result->nums = calloc(size, sizeof(int));
    if (result->nums == NULL) {
        fprintf(stderr, "Could not allocate memory to store parsed numbers\n");
        return NULL;
    }

    return result;
}

RawNumbersResult *parse_raw_numbers(char *raw_numbers, int size, char *sep) {
    RawNumbersResult *result = raw_numbers_init(size);
    int parsed_number;
    char *number;

    while ((number = strsep(&raw_numbers, sep))) {
        parsed_number = atoi(number);

        /* There are no single 0s in the input. */
        if (parsed_number == 0) {
            continue;
        }

        result->nums[result->size] = parsed_number;
        result->size++;
    }

    return result;
}

Card *parse_card_line(char *line) {
    Card *card = card_init(32);
    RawNumbersResult *parsed_numbers_result, *parsed_winning_numbers_result;

    // Removing the Card %d: part of the input, since it is not needed
    strsep(&line, ":");
    char *winning_numbers = strsep(&line, "|");
    char *numbers = line;

    parsed_numbers_result = parse_raw_numbers(numbers, NUMBERS_SIZE, " ");
    parsed_winning_numbers_result =
        parse_raw_numbers(winning_numbers, WINNING_NUMBERS_SIZE, " ");

    if (parsed_numbers_result == NULL ||
        parsed_winning_numbers_result == NULL) {
        return NULL;
    }

    card->winning_numbers = parsed_winning_numbers_result->nums;
    card->winning_numbers_size = parsed_winning_numbers_result->size;

    card->numbers = parsed_numbers_result->nums;
    card->numbers_size = parsed_numbers_result->size;

    return card;
}

int get_num_matches(Card *card) {
    int matches = 0, i, j;

    for (i = 0; i < card->numbers_size; i++) {
        for (j = 0; j < card->winning_numbers_size; j++) {
            if (card->numbers[i] == card->winning_numbers[j]) {
                matches++;
            }
        }
    }

    return matches;
}

int get_total_points(Card *card) {
    int matches = get_num_matches(card);
    int points = 1;
    int i;

    if (matches == 0) {
        return 0;
    }

    for (i = 0; i < matches - 1; i++) {
        points *= 2;
    }

    return points;
}
