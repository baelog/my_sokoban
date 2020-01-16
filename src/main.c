/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main.c
*/

#define USAGE1 "USAGE\n"
#define USAGE2 "     ./my_sokoban map\n"
#define USAGE3 "DESCRIPTION\n"
#define USAGE4 "     map file representing the warehouse map, \
containing ‘#’ for walls,\n"
#define USAGE5 "         ‘P’ for the player, ‘X’ for boxes and \
‘O’ for storage locations.\n"
#include "../include/my.h"
#include "../include/project.h"

void print_map(char **mapHole, char **mapPlayer)
{
    for (int y = 0; mapPlayer[y]; ++y) {
        for (int x = 0; mapPlayer[y][x]; ++x)
            (mapPlayer[y][x] == 'P' || mapPlayer[y][x] == 'X') ? \
            (printw("%c", mapPlayer[y][x])) : (printw("%c", mapHole[y][x]));
        printw("\n");
    }
}

int game(char **theMap)
{
    map_t *map = init_main_struct(theMap);
    initscr();
    curs_set(0);
    while (1) {
        clear();
        print_map(map->map, map->mapPlayer);
        key_pressed(getch(), map);
        refresh();
        check_win(map->map, map->mapPlayer);
        check_loose(map->map, map->mapPlayer);
    }
    return (0);
}

void display_usage(void)
{
    write(1, USAGE1, 7);
    write(1, USAGE2, 23);
    write(1, USAGE3, 13);
    write(1, USAGE4, 77);
    write(1, USAGE5, 87);
}

int main(int ac, char **av)
{
    char **map;
    if (ac != 2 || !av[1])
        return 84;
    if (my_strcmp(av[1], "-h")) {
        display_usage();
        return (0);
    }
    gestion_of_error(av[1]);
    map = take_map(count_line(av[1]), av[1]);
    game(map);
    return 0;
}

map_t *init_main_struct(char **theMap)
{
    map_t *map = malloc(sizeof(map_t));

    map->map = theMap;
    map->mapPlayer = my_array_cpy(theMap);
    map->map_clean = my_array_cpy(theMap);
    extrat_player_and_box(map);
    return (map);
}