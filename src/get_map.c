/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** read the map
*/

#include "../include/my.h"
#include "../include/project.h"

int count_line(char *file)
{
    char *str;
    int i = 0;
    int fd = open(file, O_RDONLY);
    while (str = get_next_line(fd))
        ++i;
    close(fd);
    return (i);
}

char **take_map(int numberLine, char *file)
{
    char *str;
    char **map = malloc(sizeof(char*) * (numberLine + 1));
    int y = 0;
    int fd = open(file, O_RDONLY);
    int x = 0;

    while (str = get_next_line(fd)) {
        map[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (x = -1; str[++x]; map[y][x] = str[x]);
        map[y][x] = '\0';
        ++y;
    }
    map[y] = NULL;
    close(fd);
    return (map);
}