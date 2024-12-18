/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_catchar
*/

#include "hunter.h"

char *my_catchar(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 8);

    if (fd == -1)
        return "failed";
    read(fd, buffer, 7);
    buffer[7] = '\0';
    close(fd);
    return buffer;
}
