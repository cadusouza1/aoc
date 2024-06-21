#include <stdio.h>

#define DIRECTIONS_LEN 256

int main(int argc, char *argv[]) {
    char diretions[DIRECTIONS_LEN];
    fgets(diretions, DIRECTIONS_LEN, stdin);

    printf("diretions = %s\n", diretions);
    return 0;
}
