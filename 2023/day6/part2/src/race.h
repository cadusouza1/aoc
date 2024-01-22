#pragma once
#include <stdint.h>

int64_t get_total_distance(int64_t button_pressed_time, int64_t acceleration, int64_t max_time);
int64_t get_minimum_winning_time(int64_t acceleration, int64_t max_time, int64_t max_distance);
int64_t get_maximum_winning_time(int64_t acceleration, int64_t max_time, int64_t max_distance);
