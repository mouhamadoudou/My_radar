/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/

#include "include/fichier.h"

void  draw_line (air_plan *air, sfVector2f A, sfVector2f B, char check)
{
    int a = (A.y - B.y) / (A.x - B.x);
    int b = A.y - a * A.x;

    if (check == 'y' && air->vector.x <= air->destination.x){
        air->vector.x = air->vector.x + air->pos_or;
        air->vector.y = a * air->vector.x + b;
    }
    if (check == 'x' && air->vector.y <= air->destination.y){
        air->vector.y = air->vector.y + air->pos_or;
        air->vector.x = (air->vector.y - b)/ a;
    }
    if (air->vector.x == air->destination.x){
        air->vector.x = 2000;
        air->vector.y = 2000;
    }
    }

void  display_air_plane(sfRenderWindow *window, sfSprite *sprite, sfVector2f *pt_pos, air_plan *air)
{
    draw_line(air, air->pos, air->destination, 'y');
    sfSprite_setPosition(sprite, air->vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_air(sfRenderWindow *window, air_plan **tab, int len)
{
    for (int i = 0; i < len; i++) {
        display_air_plane(window, tab[i]->sprite, &tab[i]->pos, tab[i]);
    }
}
