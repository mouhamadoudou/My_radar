/*
** EPITECH PROJECT, 2022
** get_file.c
** File description:
** get_file.c
*/
#include "include/fichier.h"

int check_nb_air(char *scrypte)
{
    int result = 0;
    int len = my_strlen(scrypte);

    for(int i = 0; i < len; i ++) {
	if (scrypte[i] == 'A')
            result ++;
    }
    return result;
}

int check(int argc, char **argv)
{
    if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        helper();
        return 1;
    }
    if(argc == 2)
	return 0;
    else
        return 2;
}

int *get_nb(char *script,int *tab, int *len)
{
    for(int i = 0; i < 6; i++) {
        tab[i] = my_getnbr(script, len);
    }
    return tab;
}

int **my_tab_int(char *script_c, int nb_air)
{
    int len_st = 0;
    int *pt_len = &len_st;
    int **tab= malloc(sizeof(int*) * nb_air + 1);

    for (int i = 0; i < nb_air; i++) {
	tab[i] = malloc(sizeof(int) * 6);
	tab[i] = get_nb(script_c, tab[i] ,pt_len);
    }
    return tab;
}
