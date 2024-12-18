/*
** EPITECH PROJECT, 2024
** My_Linked_List_lib
** File description:
** function to destroy a node passed in parameter
*/

#include "list.h"
#include <stdlib.h>

void destroy_node_data(node_t *current)
{
    sfTexture_destroy(current->texture);
    sfSprite_destroy(current->sprite);
    free(current);
}

void destroy_node(list_t *list, node_t *current)
{
    if (!list)
        return;
    if (current) {
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        if (list->head == current)
            list->head = current->next;
        if (list->tail == current)
            list->tail = current->prev;
        destroy_node_data(current);
        list->size--;
    }
}
