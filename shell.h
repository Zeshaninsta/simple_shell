#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*Define the info_t type*/
typedef struct {
    /*Add members as needed for your shell's functionality*/
    int linecount_flag;
    char **cmd_buf;
    int cmd_buf_type;
    int histcount;
    int readfd;
} info_t;


/* Function declarations */
int execute_command(char **command);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
char *_strchr(const char *s, int c);
char *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_strncat(char *dest, const char *src, size_t n);
char *_strncpy(char *dest, const char *src, size_t n);

/* Function to parse the command entered by the user */
char **parse_command(char *input);

/* Function to free the memory allocated for command parsing */
void free_memory(char **args);

/* Function to display the shell prompt */
void display_prompt(void);

/* Function to read a line from the user */
char *read_line(void);

#endif /* SHELL_H */

