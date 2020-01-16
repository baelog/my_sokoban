/*
** EPITECH PROJECT, 2019
** project fuction
** File description:
** project.h
*/

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

#define PLAYER map->posPlayer

typedef struct map_s {
    char **map_clean;
    char **map;
    char **mapPlayer;
    int *posPlayer;
}map_t;

char *get_next_line(int);
void reduce_buff(char **str, char *buff);
char *my_strcat_twice(char *str1, char *str2);

map_t *init_main_struct(char **theMap);

void add_space_map(map_t *map, int x, int y);

void gestion_player_and_boxes(map_t *map, int x, int y);
void gestion_hole(map_t *map, int y, int x);

void key_pad(int ch, map_t *map);
void key_up(map_t *map);
void key_down(map_t *map);
void key_left(map_t *map);
void key_right(map_t *map);
void key_pressed(int ch, map_t *map);

int game(char **theMap);
void print_map(char **mapPlayer, char **mapHole);

int find_boxes_number(char **mapPlayerAndBoxes);
int find_holes_number(char **mapHole);

void check_win(char **mapHole, char **mapPlayer);
void check_loose(char **mapHole, char **mapPlayer);
void do_a_boxes_is_lock(char **mapHole, char **mapPlayer, int *value);

void gestion_of_error(char *file);
void check_map(char *map);

void extrat_player_and_box(map_t *);

int count_line(char *file);
char **take_map(int numberLine, char *file);