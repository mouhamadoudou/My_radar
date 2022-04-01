/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib.c
*/

#include<unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int  decompteur = 0;

    while (str[decompteur] != '\0') {
        my_putchar(str[decompteur]);
        decompteur = decompteur + 1;
    }
    return (0);
}

int my_getnbr(char const *str, int *len)
{
    int pos_or = 1;
    int var = 0;
    int comp = *len;
    int check = 0;

    while (str[comp] != '\0') {
        while (str[comp] == '-') {
            pos_or = pos_or * -1;
            comp = comp + 1;
        }
        while (str[comp] - 48 < 10 && str[comp] -48 >= 0) {
            var = var * 10 + str [comp] - 48;
            comp = comp + 1;
            check = 1;
        }
        if (check == 1) {
            var = var * pos_or;
            *len = comp + 1;
            return var;
        }
        comp = comp + 1;
    }
    return (var);
}

int my_strlen(char *str)
{
    int decompteur = 1;
    int compteur = 1;

    while ( str[decompteur] != '\0'){
        compteur = compteur + 1;
        decompteur = decompteur + 1;
    }
    return (compteur);
}
