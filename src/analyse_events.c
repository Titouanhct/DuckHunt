/*
** EPITECH PROJECT, 2024
** analyse_events
** File description:
** function that analyse all events that occurs
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <event.h>
#include "hunter.h"

static int check_the_list(sfMouseButtonEvent mouse, h_t *h,
    list_t *l, int killed)
{
    int x_is_good = 0;
    int y_is_good = 0;
    node_t *current = l->tail;

    while (current != NULL) {
        current->pos = sfSprite_getPosition(current->sprite);
        if (mouse.x >= current->pos.x && mouse.x <= current->pos.x + 110)
            x_is_good = 1;
        if (mouse.y >= current->pos.y && mouse.y <= current->pos.y + 110)
            y_is_good = 1;
        if (x_is_good == 1 && y_is_good == 1) {
            destroy_node(l, current);
            killed = 1;
            break;
        }
        x_is_good = 0;
        y_is_good = 0;
        current = current->prev;
    }
    return killed;
}

static void manage_mouse_click(sfMouseButtonEvent mouse, h_t *h,
    list_t *l, p_t *player)
{
    int killed = 0;
    node_t *current = l->tail;

    sfMusic_play(h->music);
    killed = check_the_list(mouse, h, l, killed);
    if (killed != 1){
        player->live--;
        player->live_rect.left += 87;
        sfSprite_setTextureRect(h->player->s_live, h->player->live_rect);
    } else {
        player->score += 100;
    }
}

static void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

static void check_for_end(h_t *h)
{
    if (h->player->live == 0)
        h->game_status = 2;
}

void check_duck_position(h_t *h, list_t *list)
{
    node_t *current = list->head;

    while (current != NULL){
    current->pos = sfSprite_getPosition(current->sprite);
    if (current->pos.x >= 1900) {
        h->player->live--;
        h->player->live_rect.left += 87;
        sfSprite_setTextureRect(h->player->s_live, h->player->live_rect);
        destroy_node(list, current);
    }
    current = current->next;
    }
}

void manage_mouse_moved(h_t *h, sfMouseMoveEvent event)
{
    sfVector2f pos_cursor;
    sfVector2f pos_mouse;

    pos_mouse.x = event.x - 19;
    pos_mouse.y = event.y - 28;
    pos_cursor.x = pos_mouse.x;
    pos_cursor.y = pos_mouse.y;
    sfSprite_setPosition(h->player->s_aim, pos_cursor);
    sfRenderWindow_drawSprite(h->window, h->player->s_aim, NULL);
}

void analyse_events(sfRenderWindow *window, sfEvent event, h_t *h, list_t *l)
{
    p_t *player = h->player;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft) {
            manage_mouse_click(event.mouseButton, h, l, player);
        }
        if (event.type == sfEvtMouseMoved)
            manage_mouse_moved(h, event.mouseMove);
    }
    check_duck_position(h, l);
    check_for_end(h);
}
