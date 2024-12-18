/*
** EPITECH PROJECT, 2024
** create_window.c
** File description:
** file with the creation of the window
*/

#include "hunter.h"
#include "list.h"

void create_sprites(h_t *h)
{
    h->sprite_bg = sfSprite_create();
    h->player->s_live = sfSprite_create();
    h->player->live_rect = (sfIntRect) {0, 0, 85, 85};
    h->player->txt_score = sfText_create();
    h->txt_high_score = sfText_create();
    h->sprite_go = sfSprite_create();
    h->player->s_aim = sfSprite_create();
}

int create_textures(h_t *h)
{
    h->bg = sfTexture_createFromFile("p/bg.png", NULL);
    h->player->t_live = sfTexture_createFromFile("p/live.png", NULL);
    h->t_go = sfTexture_createFromFile("p/game_over.png", NULL);
    h->player->t_aim = sfTexture_createFromFile("p/aim.png", NULL);
    sfSprite_scale(h->sprite_go, h->scale_go);
    sfSprite_setTexture(h->sprite_go, h->t_go, sfTrue);
    if (!h->bg)
        return EXIT_FAILURE;
    h->sky.r = 8;
    h->sky.g = 176;
    h->sky.b = 247;
    h->sky.a = 250;
}

void set_textures(h_t *h)
{
    sfVector2f scale_bg = {2.90, 2.87};
    sfVector2f pos_live = {1750, 950};
    sfVector2f pos_txt = {50, 950};
    sfVector2f scale_aim = {0.1, 0.1};

    sfSprite_setScale(h->sprite_bg, scale_bg);
    sfSprite_setScale(h->player->s_aim, scale_aim);
    sfSprite_setTexture(h->sprite_bg, h->bg, sfTrue);
    sfSprite_setTexture(h->player->s_live, h->player->t_live, sfTrue);
    sfSprite_setTexture(h->player->s_aim, h->player->t_aim, sfTrue);
    sfSprite_setTextureRect(h->player->s_live, h->player->live_rect);
    sfSprite_setPosition(h->player->s_live, pos_live);
    h->font = sfFont_createFromFile("p/Radioz.ttf");
    sfText_setFont(h->player->txt_score, h->font);
    sfText_setFont(h->txt_high_score, h->font);
    sfText_setPosition(h->player->txt_score, pos_txt);
    sfText_setCharacterSize(h->player->txt_score, 75);
}

int create_window(h_t *h, list_t *list)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f pos_highscore = {900, 950};

    h->scale_go = (sfVector2f) {1.75, 1.75};
    h->window = sfRenderWindow_create(mode, "My h cracked",
        sfResize | sfClose, NULL);
    if (!h->window)
        return EXIT_FAILURE;
    create_sprites(h);
    create_textures(h);
    set_textures(h);
    sfText_setPosition(h->txt_high_score, pos_highscore);
    sfText_setCharacterSize(h->txt_high_score, 75);
    sfRenderWindow_setMouseCursorVisible(h->window, sfFalse);
    sfRenderWindow_setFramerateLimit(h->window, 60);
}
