/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** ..
*/


#include "hunter.h"


static int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    h_t *h = malloc(sizeof(h_t));
    list_t *list = create_list();
    char *d = "-h";

    h->player = malloc(sizeof(p_t));
    h->player->live = 4;
    h->player->score = 0;
    h->music = sfMusic_createFromFile("p/gun.ogg");
    if (argc == 2 && my_strcmp(argv[1], d) == 0)
        my_cat("description.txt");
    else {
    h->clock = sfClock_create();
    create_window(h, list);
    display_window(h, list);
    return 0;
    }
}
