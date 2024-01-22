#pragma once

int get_total_distance(int button_pressed_time, int acceleration,
                       int max_time);
int get_minimum_winning_time(int acceleration,
                             int max_time, int max_distance);
int get_maximum_winning_time(int acceleration,
                             int max_time, int max_distance);
