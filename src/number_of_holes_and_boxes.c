/*
** EPITECH PROJECT, 2019
** sokoban number of holes and boxes
** File description:
** find the number of holes and boxes
*/

#include "../include/my.h"
#include "../include/project.h"

int find_holes_number(char **mapHole)
{
    int numberOfHole = 0;
    for (int y = 0; mapHole[y]; ++y) {
        for (int x = 0; mapHole[y][x]; ++x) {
            (mapHole[y][x] == 'O') ? (numberOfHole += 1) : (numberOfHole);
        }
    }
    return (numberOfHole);
}

int find_boxes_number(char **mapPlayerAndBoxes)
{
    int numberOfBoxes = 0;
    for (int y = 0; mapPlayerAndBoxes[y]; ++y) {
        for (int x = 0; mapPlayerAndBoxes[y][x]; ++x) {
            (mapPlayerAndBoxes[y][x] == 'X') ? \
            (numberOfBoxes += 1) : (numberOfBoxes);
        }
    }
    return (numberOfBoxes);
}
