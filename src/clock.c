/*
** EPITECH PROJECT, 2024
** clock
** File description:
** file with a clock inside
*/

#include "hunter.h"

static void check_sprite(node_t *current)
{
    if (current->rect.left >= 330)
        current->rect.left = 0;
}

void move_the_pingouin(h_t *h, list_t *list)
{
    sfTime time;
    float seconds;
    sfVector2f vector_pingouin = {20, 0};
    node_t *current = list->head;

    time = sfClock_getElapsedTime(h->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.075) {
        while (current != NULL) {
        current->rect.left += 110;
        check_sprite(current);
        sfSprite_move(current->sprite, vector_pingouin);
        current = current->next;
        }
        sfClock_restart(h->clock);
    }
}
