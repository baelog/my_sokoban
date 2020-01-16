/*
** EPITECH PROJECT, 2019
** error of sokoban
** File description:
** error possible for the sokoban
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "../include/project.h"

void gestion_of_error(char *file)
{
    struct stat sb;
    char *buff;
    int fd;
    int rd;

    if (stat(file, &sb) < -1)
        exit(84);
    if (!(sb.st_size))
        exit(84);
    if ((fd = open(file, O_RDONLY)) < 0)
        exit(84);
    buff = malloc(sizeof(char) * (sb.st_size + 1));
    if ((rd = read(fd, buff, sb.st_size) == -1))
        exit(84);
    close(fd);
    check_map(buff);
}

void check_map(char *map)
{
    int holes = 0;
    int boxes = 0;
    int player = 0;
    for (int i = 0; map[i]; ++i) {
        if (map[i] == 'P')
            ++player;
        if (map[i] == 'X')
            ++boxes;
        if (map[i] == 'O')
            ++holes;
        if (map[i] != 'P' && map[i] != 'O' && map[i] != 'X' && \
        map[i] != ' ' && map[i] != '#' && map[i] != '\n') {
            free(map);
            exit(84);
        }
    }
    if (holes != boxes || holes == 0 || boxes == 0 || player != 1) {
        free(map);
        exit(84);
    }
}