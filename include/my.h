/*
** EPITECH PROJECT, 2019
** myh
** File description:
** myh
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
    struct list_s *prev;
}list_t, *list;

int  my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *tab,int size);
char *my_strcat(char *dest,char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest,char const *src, int nb);
int my_strncmp (char const *s1, char const *s2);
char *my_strncpy (char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
char *my_evil_str(char *str);
char *my_strcat_one(char *dest, char src);
char *int_to_str(int nb);
int my_len_array(char**);
char **my_array_cpy(char**);

int add_node(list *myList, void *data);
void destroy_list(list myList);

void print_list_char(list myList);
void print_list_str(list myList);
void print_list_number(list myList);

#endif