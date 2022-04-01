/*
** EPITECH PROJECT, 2022
** objet.c
** File description:
** objet.c
*/

#include "include/fichier.h"

void create_music(back_gr *music)
{
    music->gamemusic = sfMusic_createFromFile("msq.ogg");
    sfMusic_setLoop(music->gamemusic, sfTrue);
    sfMusic_setVolume(music->gamemusic, 10);
    sfMusic_play(music->gamemusic);
}

int check_direction(sfVector2f A, sfVector2f B)
{
    int result = 0;
    int a = A.x + A.y;
    int b = B.x + B.y;

    if(a > b)
        return -1;
    if(b > a)
        return 1;
}

back_gr *display_back(back_gr *av)
{
    av->texture = sfTexture_createFromFile("map.png", NULL);
    av->sprite = sfSprite_create();
    av->rect = (sfIntRect){0, 0, 1920, 1080};
    av->pos = (sfVector2f){0, 0};
    sfSprite_setTexture(av->sprite, av->texture, sfTrue);
    sfSprite_setTextureRect(av->sprite, av->rect);

    return av;
}

air_plan *creat_objet(int *script)
{
    air_plan *av = malloc(sizeof(air_plan));

    av->texture = sfTexture_createFromFile("av.png", NULL);
    av->sprite = sfSprite_create();
    av->rect = (sfIntRect){0, 0, 800, 800};
    av->pos = (sfVector2f){script[0], script[1]};
    av->destination = (sfVector2f){script[2], script[3]};
    av->pos_or = check_direction(av->pos, av->destination);
    if(av->pos_or == 1)
        av->vector = av->pos;
    if(av->pos_or == -1) {
        av->pos = (sfVector2f){script[2], script[3]};
        av->destination = (sfVector2f){script[0], script[1]};
        av->vector = av->destination;
    }
    return av;
}

air_plan **reserved(int len, int **script)
{
    air_plan **tab = malloc(sizeof(air_plan*) * len);

    for (int i = 0; i < len; i ++)
        tab[i] = creat_objet(script[i]);
    return tab;
}

void start(sfRenderWindow *window, int len, int **script)
{
    back_gr *back = malloc(sizeof(back_gr));
    air_plan **tab = reserved(len, script);

    back = display_back(back);
    set_sf(tab, len);
    create_music(back);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setPosition(back->sprite, back->pos);
        sfRenderWindow_drawSprite(window, back->sprite, NULL);

        draw_air(window, tab, len);
        close_window(window);
        sfRenderWindow_display(window);
    }
    free(tab);
}
