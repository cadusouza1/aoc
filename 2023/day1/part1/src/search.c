#include <ctype.h>
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

    for (i = strlen(line) - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            return i;
        }
    }

    return -1;
}
