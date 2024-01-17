#include "part1.h"
#include "part2.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("input/input.txt", "r");
    part1(f);
    rewind(f);
    part2(f);
    fclose(f);

    return 0;
}
