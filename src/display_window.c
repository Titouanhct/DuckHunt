/*
** EPITECH PROJECT, 2024
** display_window
** File description:
** file to display the window and keep it open
*/

#include "hunter.h"

void clean_by_free(h_t *h, list_t *list)
{
    node_t *current = list->head;
    node_t *tmp;

    free(h->player);
    free(h);
    while (current != NULL){
        tmp = current->next;
        destroy_node(list, current);
        current = tmp;
    }
    free(list);
}

void clean(h_t *h, list_t *list)
{
    sfSprite_destroy(h->sprite_bg);
    sfTexture_destroy(h->bg);
    sfText_destroy(h->player->txt_score);
    sfText_destroy(h->txt_high_score);
    sfTexture_destroy(h->player->t_live);
    sfSprite_destroy(h->player->s_live);
    sfRenderWindow_destroy(h->window);
    sfSprite_destroy(h->player->s_aim);
    sfTexture_destroy(h->player->t_aim);
    sfTexture_destroy(h->t_go);
    sfMusic_destroy(h->music);
    sfClock_destroy(h->clock);
    sfFont_destroy(h->font);
    sfSprite_destroy(h->sprite_go);
    clean_by_free(h, list);
}

static void create_ducks(h_t *h, list_t *list, int *nb_duck)
{
    for (int i = 0; i < *nb_duck; i++)
        pushback(list);
}

static void draw(h_t *h, list_t *list)
{
    node_t *current = list->head;

    while (current != NULL){
        sfSprite_setTextureRect(current->sprite, current->rect);
        sfRenderWindow_drawSprite(h->window, current->sprite, NULL);
        current = current->next;
    }
    sfRenderWindow_drawSprite(h->window, h->sprite_bg, NULL);
    sfRenderWindow_drawSprite(h->window, h->player->s_live, NULL);
    sfRenderWindow_drawSprite(h->window, h->player->s_aim, NULL);
}

static void draw_game_over(h_t *h)
{
    sfRenderWindow_clear(h->window, sfBlack);
    sfRenderWindow_drawSprite(h->window, h->sprite_go, NULL);
    sfRenderWindow_drawText(h->window, h->player->txt_score, NULL);
    sfRenderWindow_drawText(h->window, h->txt_high_score, NULL);
    sfRenderWindow_display(h->window);
}

void game_over(h_t *h)
{
    sfVector2f scale_go = {0.75, 0.75};
    sfEvent event;
    char high_score[] = "High Score = ";
    char *str = my_int_str(h->player->score);
    char *tmp = my_int_str(h->high_score);
    char *h_score;

    h_score = my_strcatdup(high_score, tmp);
    draw_game_over(h);
    sfText_setString(h->txt_high_score, h_score);
    sfText_setString(h->player->txt_score, str);
    while (sfRenderWindow_pollEvent(h->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(h->window);
    }
    free(str);
    free(tmp);
    free(h_score);
}

void game_on(h_t *h, list_t *list, int *nbduck)
{
    sfEvent event;
    char *str = my_int_str(h->player->score);

    sfRenderWindow_clear(h->window, h->sky);
    draw(h, list);
    sfText_setString(h->player->txt_score, str);
    sfRenderWindow_drawText(h->window, h->player->txt_score, NULL);
    analyse_events(h->window, event, h, list);
    if (list->size == 0) {
        (*nbduck)++;
        create_ducks(h, list, nbduck);
    }
    move_the_pingouin(h, list);
    sfRenderWindow_display(h->window);
    free(str);
}

static void handle_highscore(h_t *h)
{
    int fd;
    char *str = my_catchar("src/score.txt");

    h->high_score = my_getnbr(str);
    if (h->player->score > h->high_score){
        fd = open("src/score.txt", O_WRONLY);
        if (fd == -1)
            return;
        write(fd, my_int_str(h->player->score),
            my_strlen(my_int_str(h->player->score)));
        close(fd);
        h->high_score = h->player->score;
    }
    free(str);
}

int display_window(h_t *h, list_t *list)
{
    int nbduck = 1;

    create_ducks(h, list, &nbduck);
    h->game_status = 1;
    while (sfRenderWindow_isOpen(h->window)) {
        if (h->game_status == 1)
            game_on(h, list, &nbduck);
        if (h->game_status == 2){
            handle_highscore(h);
            game_over(h);
        }
    }
    clean(h, list);
    return EXIT_SUCCESS;
}
