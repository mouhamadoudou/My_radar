/*
** EPITECH PROJECT, 2022
** remplie objet
** File description:
** remplie objet
*/

#include "include/fichier.h"

void set_sf(air_plan **tab, int len)
{
    for( int i = 0; i < len; i++){
        sfSprite_setPosition(tab[i]->sprite, tab[i]->pos);
        sfSprite_setScale(tab[i]->sprite, (sfVector2f){0.02, 0.02});
	sfSprite_setTexture(tab[i]->sprite, tab[i]->texture, sfTrue);
        sfSprite_setTextureRect(tab[i]->sprite, tab[i]->rect);
    }
}

air_plan **remplie_string(air_plan **tab, int len)
{
    for(int i = 0; i < len; i++) {
        tab[i] = malloc(sizeof(air_plan));
    }
    return tab;
}
