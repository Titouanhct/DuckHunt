/*
** EPITECH PROJECT, 2024
** list.h
** File description:
** .h for my linked list library
*/

#ifndef LIST_H_
    #define LIST_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>

typedef struct node_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int size_sprite;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list(void);
void pushback(list_t *list);
void popfront(list_t *list);
void popback(list_t *list);
void destroy_node(list_t *list, node_t *current);
#endif /* !LIST_H_ */
