/*
** EPITECH PROJECT, 2024
** my_int_str.c
** File description:
** convert an int to and char *
*/

#include "hunter.h"

char *put_inside_str(char *str, int nb)
{
    int i = 0;
    int res;

    for (; nb > 0; i++) {
        res = nb % 10;
        str[i] = res + '0';
        nb /= 10;
    }
    return str;
}

char *fill_zero(char *str, int len)
{
    while (len < 7){
        str[len] = '0';
        len++;
    }
    str[len] = '\0';
    return str;
}

char *my_int_str(int nb)
{
    unsigned long long int res = 0;
    int len;
    int j = 0;
    char *str;

    res = nb;
    for (; res > 0; j++)
        res /= 10;
    str = malloc(sizeof(char) * (8));
    str = put_inside_str(str, nb);
    str[j] = '\0';
    len = (my_strlen(str));
    if (7 - len > 0)
        fill_zero(str, len);
    my_revstr(str);
    return str;
}
