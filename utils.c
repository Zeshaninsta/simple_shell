#include "shell.h"
#define READ_BUF_SIZE 1024
/**
 * read_buf - Reads a buffer from a file descriptor.
 *
 * This function reads a buffer from the specified file descriptor
 * and updates the index parameter accordingly.
 *
 * @info: parameter struct containing the file descriptor.
 * @buf: buffer to read into.
 * @i: pointer to the index parameter.
 *
 * Return: The number of bytes read, or 0 if no bytes were read.
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i) {
    ssize_t r = 0;

    if (*i)
        return 0;

    r = read(info->readfd, buf, READ_BUF_SIZE);
    if (r >= 0)
        *i = r;

    return r;
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character c
 * in the string pointed to by s.
 *
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If the character c is found, a pointer to the first occurrence is returned.
 *         If the character c is not found, NULL is returned.
 */
char *_strchr(const char *s, int c) {
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }

    return NULL;
}

/**
 * _realloc - Reallocates a block of memory.
 *
 * This function changes the size of the memory block pointed to by ptr to new_size bytes.
 *
 * @ptr: The pointer to the memory block to be reallocated.
 * @old_size: The current size of the memory block.
 * @new_size: The new size for the memory block.
 *
 * Return: A pointer to the newly allocated memory block.
 */
char *_realloc(void *ptr, size_t old_size, size_t new_size) {
    char *new_ptr = malloc(new_size);
    if (!new_ptr) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (ptr) {
        memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }

    return new_ptr;
}

/**
 * _strncat - Concatenates two strings, but no more than n bytes are copied.
 *
 * This function appends the src string to the dest string, overwriting the
 * terminating null byte ('\0') at the end of dest, and then adds a terminating null byte.
 * The strings may not overlap, and the dest string must have enough space for the result.
 *
 * @dest: The destination buffer.
 * @src: The source buffer.
 * @n: The maximum number of bytes to be appended.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';
    return dest;
}

/**
 * _strncpy - Copies up to n characters from the source string to the destination buffer.
 *
 * This function copies up to n characters from the source string src to the destination buffer dest.
 * If there are not enough source characters, null bytes are used to pad the remaining characters.
 *
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return dest;
}
