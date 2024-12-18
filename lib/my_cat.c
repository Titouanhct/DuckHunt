/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_cat
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "hunter.h"

int my_cat(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 512);

    if (fd == -1)
        return 84;
    read(fd, buffer, 511);
    write(1, buffer, my_strlen(buffer));
    close(fd);
    return 0;
}
