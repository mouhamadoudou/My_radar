/*
** EPITECH PROJECT, 2022
** open.helper.c
** File description:
** help
*/
#include "include/fichier.h"

int fs_open_file(const char *filepath)
{
    int result = 0;

    result = open(filepath, O_RDONLY);
    if (result > 2) {
    }
    else{
        return(84);
    }
    return result;
}

char *gestion_open(int argc, char **argv)
{
    struct stat buf;
    int sizz;
    ssize_t rd;
    int result;

    if (argc > 2 || argc < 2)
        return NULL;
    stat(argv[1], &buf);
    sizz = buf.st_size;
    char *buffer = malloc(sizeof(char) * sizz + 1);
    if (sizz == -1 || sizz == 0)
        return NULL;
    result = fs_open_file(argv[1]);
    rd = read(result, buffer, sizz);
    buffer[rd] = '\0';
    close(result);
    return buffer;
}

void helper(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("   path_to_script The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h               print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key       enable/disable hitboxes and areas.\n");
    my_putstr("  'S' key       enable/disable sprites.\n");
}

