/*
** EPITECH PROJECT, 2021
** fichier.h
** File description:
** fichier.h
*/

#ifndef _DISPLAY_FRAMEBUFFER_H_
    #define  _DISPLAY_FRAMEBUFFER_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stddef.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/Export.h>


typedef struct framebuffer_t
{
    sfUint8 *pixels;
    int width;
    int height;
} framebuffer_t;

typedef struct back_gr
{
    sfMusic *gamemusic;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} back_gr;


struct air_plan
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f destination;
    sfVector2f vector;
    int pos_or;
};

typedef struct air_plan air_plan;

void helper(void);
char *gestion_open(int argc, char **argv);
int fs_open_file(const char *filepath);
char *gestion_open(int argc, char **argv);
int check_nb_air(char *scrypte);
int check(int argc, char **argv);
int *get_nb(char *script,int *tab, int *len);
int **my_tab_int(char *script_c, int nb_air);
int my_getnbr(char const *str, int *len);
int my_strlen(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
framebuffer_t *framebuffer_create(framebuffer_t *framebuffer, unsigned int bpp,unsigned int width,  unsigned int hight);
sfEvent close_window(sfRenderWindow* window);
framebuffer_t *framebuffer_create(framebuffer_t *framebuffer, unsigned int bpp,unsigned int width,  unsigned int hight);
void draw_air(sfRenderWindow *window, air_plan **tab, int len);
sfEvent close_window(sfRenderWindow* window);
sfRenderWindow *gestion_window(void);
air_plan *creat_objet(int *script);
air_plan **reserved(int len, int **script);
void start(sfRenderWindow *window, int len, int **script);
void set_sf(air_plan **tab, int len);
air_plan **remplie_string(air_plan **tab, int len);
//void create_music(back_gr *music)

#endif
