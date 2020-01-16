/*
** EPITECH PROJECT, 2019
** chain list file
** File description:
** creation and destruction of chain list
*/

#include "my.h"

int add_node(list *myList, void *data)
{
    list newNode = malloc(sizeof(list_t));

    if (!newNode)
        return (84);
    newNode->data = data;
    newNode->next = NULL;
    if (!*myList) {
        newNode->prev = NULL;
        *myList = newNode;
    }
    else {
        newNode->prev = *myList;
        (*myList)->next = newNode;
    }
    return (0);
}

void destroy_list(list myList)
{
    list temp = myList;

    while (myList->prev)
        myList = myList->next;
    while (myList->next) {
        temp = myList;
        myList = myList->next;
        myList->prev = NULL;
        free(temp);
    }
    free(myList);
}

void print_list_char(list myList)
{
    list temp = myList;

    while (temp) {
        write(1, &temp->data, 1);
        write(1, "\n", 1);
        temp = temp->next;
    }

}

void print_list_str(list myList)
{
    list temp = myList;

    while (temp) {
        my_putstr((char*)(temp->data));
        write(1, "\n", 1);
        temp = temp->next;
    }
}

void print_list_number(list myList)
{
    list temp = myList;
    int a;

    while (temp) {
        long a = (long)(temp->data);
        my_put_nbr((int)a);
        write(1, "\n", 1);
        temp = temp->next;
    }
}