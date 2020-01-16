/*
** EPITECH PROJECT, 2019
** my sokoban button
** File description:
** witch button are pressed ?
*/

#include "../include/my.h"
#include "../include/project.h"

void key_down(map_t *map);
void key_left(map_t *map);
void key_right(map_t *map);

void key_pressed(int ch, map_t *map)
{
    if (ch == ' ')
        game(map->map_clean);
    else
        key_pad(ch, map);
}

void key_pad(int ch, map_t *map)
{
    if (ch == 'A')
        key_up(map);
    if (ch == 'B')
        key_down(map);
    if (ch == 'C')
        key_right(map);
    if (ch == 'D')
        key_left(map);
}