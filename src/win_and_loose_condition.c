/*
** EPITECH PROJECT, 2019
** sokoban win/loose
** File description:
** check if you are loosing or winning
*/

#define Y value[2]
#define X value[3]
#include "../include/my.h"
#include "../include/project.h"

void check_win(char **mapHole, char **mapPlayer)
{
    int numberOfHoles = find_holes_number(mapHole);
    for (int y = 0; mapHole[y]; ++y) {
        for (int x = 0; mapHole[y][x]; ++x) {
            (mapHole[y][x] == 'O' && mapPlayer[y][x] == 'X') ? \
            (numberOfHoles -= 1) : (numberOfHoles);
        }
    }
    if (!numberOfHoles) {
        clear();
        print_map(mapHole, mapPlayer);
        refresh();
        endwin();
        exit(0);
    }
}

void check_loose(char **mapHole, char **mapPlayer)
{
    int numberOfHoles = find_holes_number(mapHole);
    int numberOfBoxes = find_boxes_number(mapPlayer);
    int *value = malloc(sizeof(int) * 5);

    value[0] = numberOfHoles;
    value[1] = numberOfBoxes;
    value[2] = 0;
    value[3] = 0;
    value[4] = 0;
    for (value[2] = 0; mapHole[value[2]]; ++value[2]) {
        for (value[3] = 0; mapHole[value[2]][value[3]]; ++value[3]) {
            do_a_boxes_is_lock(mapHole, mapPlayer, value);
        }
    }
}

void do_a_boxes_is_lock(char **mapHole, char **mapPlayer, int *value)
{
    if (mapPlayer[Y][X] == 'X') {
        if (((mapHole[Y - 1][X] == '#' || mapPlayer[Y - 1][X] == 'X') && \
        (mapHole[Y][X + 1] == '#' || mapPlayer[Y][X + 1] == 'X')) || \
        ((mapHole[Y - 1][X] == '#' || mapPlayer[Y - 1][X] == 'X') && \
        (mapHole[Y][X - 1] == '#' || mapPlayer[Y][X - 1] == 'X')) || \
        ((mapHole[Y + 1][X] == '#' || mapPlayer[Y + 1][X] == 'X') && \
        (mapHole[Y][X + 1] == '#' || mapPlayer[Y][X + 1] == 'X')) || \
        ((mapHole[Y + 1][X] == '#' || mapPlayer[Y + 1][X] == 'X') && \
        (mapHole[Y][X - 1] == '#' || mapPlayer[Y][X - 1] == 'X')))
            --value[1];
    }
    if (!value[1]) {
        clear();
        print_map(mapHole, mapPlayer);
        refresh();
        endwin();
        exit(1);
    }
}