/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Reverse a string
*/
#include <stdio.h>

char *my_revstr(char *str)
{
    char temp;
    int j = -1;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++){
        j++;
    }
    for (; k <= j; k++){
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
        j--;
    }
    return str;
}
