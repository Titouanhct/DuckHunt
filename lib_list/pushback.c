/*
** EPITECH PROJECT, 2024
** pushback
** File description:
** pushback
*/

#include "list.h"
#include <stdlib.h>
#include <time.h>

static int rand_pos(int max, int min)
{
    return rand() % (max - min + 1) + min;
}

static node_t *fill_node(node_t *node, node_t *prev)
{
    sfVector2f position = {rand_pos(-200, -500), rand_pos(800, 0)};

    node->prev = prev;
    node->next = NULL;
    node->rect = (sfIntRect) {0, 0, 110, 110};
    node->texture = sfTexture_createFromFile("p/s_pingouin.png", NULL);
    node->sprite = sfSprite_create();
    sfSprite_setPosition(node->sprite, position);
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    node->size_sprite = 330;
    node->pos = position;
    return node;
}

void pushback(list_t *list)
{
    node_t *to_add = malloc(sizeof(node_t));

    if (!list)
        return;
    to_add = fill_node(to_add, list->tail);
    if (list->tail)
        list->tail->next = to_add;
    list->tail = to_add;
    if (!list->head)
        list->head = to_add;
    list->size++;
}
