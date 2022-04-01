/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** test.c
*/

#include "include/fichier.h"

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    int verif = check(argc, argv);

    if (verif == 1)
        return 0;
    if (argc != 2)
        return 84;
    if (verif == 2)
        return 84;
    if (verif == 0) {
    char *script = gestion_open(argc, argv);
    int nb_a = check_nb_air(script);
    int **script_int = my_tab_int(script, nb_a);
    window = gestion_window();
    start(window, nb_a, script_int);
    free(script_int);
    free(window);
    }
    return 0;
}
