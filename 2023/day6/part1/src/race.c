int get_total_distance(int button_pressed_time, int acceleration,
                       int max_time) {
    int velocity = button_pressed_time * acceleration;
    if (button_pressed_time >= max_time || button_pressed_time == 0) {
        return 0;
    }

    return (max_time - button_pressed_time) * velocity;
}

int get_minimum_winning_time(int acceleration, int max_time, int max_distance) {
    int distance, i;

    for (i = 0; i < max_time; i++) {
        distance = get_total_distance(i, acceleration, max_time);

        if (distance > max_distance) {
            return i;
        }
    }

    return -1;
}

int get_maximum_winning_time(int acceleration, int max_time, int max_distance) {
    int distance, i;

    for (i = max_time - 1; i >= 0; i--) {
        distance = get_total_distance(i, acceleration, max_time);

        if (distance > max_distance) {
            return i;
        }
    }

    return -1;
}
