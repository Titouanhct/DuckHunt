/*
** EPITECH PROJECT, 2024
** Graphic
** File description:
** frame_buffer
*/

#ifndef HUNTER_H_
    #define HUNTER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>
    #include "list.h"
    #include <stddef.h>
    #include <fcntl.h>



typedef struct p_s {
    sfSprite *s_live;
    sfTexture *t_live;
    sfIntRect live_rect;
    int live;
    int score;
    sfText *txt_score;
    sfSprite *s_aim;
    sfTexture *t_aim;
} p_t;

typedef struct h {
    sfRenderWindow *window;
    sfSprite *sprite_bg;
    sfTexture *bg;
    sfClock *clock;
    sfMusic *music;
    sfColor sky;
    p_t *player;
    int game_status;
    sfVector2f scale_go;
    sfSprite *sprite_go;
    sfTexture *t_go;
    sfText *txt_high_score;
    sfFont *font;
    int high_score;
} h_t;



void analyse_events(sfRenderWindow * window, sfEvent event, h_t *h, list_t *l);
int create_window(h_t *h, list_t *list);
int display_window(h_t *h, list_t *list);
void move_the_pingouin(h_t *h, list_t *list);
char *my_int_str(int nb);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcatdup(char *dest, char *src);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_catchar(char *filepath);
int my_cat(char *filepath);
int my_getnbr(char const *str);
char *my_strdup(char const *str);

#endif /* HUNTER_H_ */
