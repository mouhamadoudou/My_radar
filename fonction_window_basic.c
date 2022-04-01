/*
** EPITECH PROJECT, 2022
** basic.c
** File description:
** basic.c
*/

#include "include/fichier.h"


framebuffer_t *framebuffer_create(framebuffer_t *framebuffer, unsigned int bpp,unsigned int width,  unsigned int hight)
{
    framebuffer->width = width;
    framebuffer->height = hight;
    framebuffer->pixels = malloc(width * hight * (bpp / 8));
    return (framebuffer);
}

sfEvent close_window(sfRenderWindow* window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

sfRenderWindow *gestion_window(void)
{
    framebuffer_t framebuffer;
    unsigned int bits_per_pixel = 32;
    sfVideoMode mode = {1900, 1000, 32};
    sfRenderWindow *window;
    
    window = sfRenderWindow_create(mode, "My_radar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window,  30);
    framebuffer_create(&framebuffer, bits_per_pixel, 1920, 1080);
    return window;
}
