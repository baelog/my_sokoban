/*
** EPITECH PROJECT, 2019
** sokoban getkey
** File description:
** event with pad
*/

#include "../include/my.h"
#include "../include/project.h"

void key_up(map_t *map)
{
    if (map->mapPlayer[PLAYER[1] - 1][PLAYER[0]] == 'X' && \
    (map->map[PLAYER[1] - 2][PLAYER[0]] != '#' && \
    map->mapPlayer[PLAYER[1] - 2][PLAYER[0]] != 'X')) {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[--PLAYER[1]][PLAYER[0]] = 'P';
        map->mapPlayer[PLAYER[1] - 1][PLAYER[0]] = 'X';
    }
    if (map->map[PLAYER[1] - 1][PLAYER[0]] != '#' && \
    map->mapPlayer[PLAYER[1] - 1][PLAYER[0]] != 'X') {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[--PLAYER[1]][PLAYER[0]] = 'P';
    }
}

void key_down(map_t *map)
{
    if (map->mapPlayer[PLAYER[1] + 1][PLAYER[0]] == 'X' && \
    (map->map[PLAYER[1] + 2][PLAYER[0]] != '#' && \
    map->mapPlayer[PLAYER[1] + 2][PLAYER[0]] != 'X')) {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[++PLAYER[1]][PLAYER[0]] = 'P';
        map->mapPlayer[PLAYER[1] + 1][PLAYER[0]] = 'X';
    }
    if (map->map[PLAYER[1] + 1][PLAYER[0]] != '#' && \
    map->mapPlayer[PLAYER[1] + 1][PLAYER[0]] != 'X') {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[++PLAYER[1]][PLAYER[0]] = 'P';
    }
}

void key_left(map_t *map)
{
    if (map->mapPlayer[PLAYER[1]][PLAYER[0] - 1] == 'X' && \
    (map->map[PLAYER[1]][PLAYER[0] - 2] != '#' && \
    map->mapPlayer[PLAYER[1]][PLAYER[0] - 2] != 'X')) {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[PLAYER[1]][--PLAYER[0]] = 'P';
        map->mapPlayer[PLAYER[1]][PLAYER[0] - 1] = 'X';
    }
    if (map->map[PLAYER[1]][PLAYER[0] - 1] != '#' && \
    map->mapPlayer[PLAYER[1]][PLAYER[0] - 1] != 'X') {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[PLAYER[1]][--PLAYER[0]] = 'P';
    }
}

void key_right(map_t *map)
{
    if (map->mapPlayer[PLAYER[1]][PLAYER[0] + 1] == 'X' && \
    (map->map[PLAYER[1]][PLAYER[0] + 2] != '#' && \
    map->mapPlayer[PLAYER[1]][PLAYER[0] + 2] != 'X')) {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[PLAYER[1]][++PLAYER[0]] = 'P';
        map->mapPlayer[PLAYER[1]][PLAYER[0] + 1] = 'X';
    }
    if (map->map[PLAYER[1]][PLAYER[0] + 1] != '#' && \
    map->mapPlayer[PLAYER[1]][PLAYER[0] + 1] != 'X') {
        map->mapPlayer[PLAYER[1]][PLAYER[0]] = ' ';
        map->mapPlayer[PLAYER[1]][++PLAYER[0]] = 'P';
    }
}