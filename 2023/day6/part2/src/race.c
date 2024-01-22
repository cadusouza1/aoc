#include <stdint.h>

int64_t get_total_distance(int64_t button_pressed_time, int64_t acceleration,
                           int64_t max_time) {
    int64_t velocity = button_pressed_time * acceleration;
    if (button_pressed_time >= max_time || button_pressed_time == 0) {
        return 0;
    }

    return (max_time - button_pressed_time) * velocity;
}

int64_t get_minimum_winning_time(int64_t acceleration, int64_t max_time,
                                 int64_t max_distance) {
    int64_t distance, i;

    for (i = 0; i < max_time; i++) {
        distance = get_total_distance(i, acceleration, max_time);

        if (distance > max_distance) {
            return i;
        }
    }

    return -1;
}

int64_t get_maximum_winning_time(int64_t acceleration, int64_t max_time,
                                 int64_t max_distance) {
    int64_t distance, i;

    for (i = max_time - 1; i >= 0; i--) {
        distance = get_total_distance(i, acceleration, max_time);

        if (distance > max_distance) {
            return i;
        }
    }

    return -1;
}
