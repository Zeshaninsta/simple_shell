#include "shell.h"

void free_memory(char **args) {
    int i = 0;
    while (args[i] != NULL) {
        free(args[i]);
        i++;
    }
    free(args);
}

