/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** 2 map for superposition
*/

#include "../include/my.h"
#include "../include/project.h"

void extrat_player_and_box(map_t *map)
{
    for (int y = 0; map->map[y]; ++y) {
        for (int x = 0; map->map[y][x]; ++x) {
            add_space_map(map, x, y);
        }
    }
}

void add_space_map(map_t *map, int x, int y)
{
    if (map->map[y][x] == 'X' || map->map[y][x] == 'P') {
        gestion_player_and_boxes(map, x, y);
        map->map[y][x] = ' ';
    }
    else {
        map->mapPlayer[y][x] = ' ';
    }
}

void gestion_player_and_boxes(map_t *map, int x, int y)
{
    int pos[] = {x, y, 0};
    if (map->mapPlayer[y][x] != 'X') {
        map->posPlayer = malloc(sizeof(int) * 3);
        map->posPlayer[0] = pos[0];
        map->posPlayer[1] = pos[1];
        map->posPlayer[2] = pos[2];
    }
}