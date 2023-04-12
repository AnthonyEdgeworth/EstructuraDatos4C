/**
 * @file BoxToysEstructuras.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BOXTOYSESTRUCTURAS_H
#define BOXTOYSESTRUCTURAS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

// TODO: *************** Implementacion de un forearch ***************

typedef struct list_node list_node;
struct list_node
{
    list_node *next;
    void *data;
};

#define Mayor(valorA, valorB) ((valorA > valorB) ? valorA : valorB)


#define foreach(item, list) \
    for (list_node * (item) = (list); (item); (item) = (item)->next)



void print_array(list_node *array);
list_node *menu_array(list_node **array);
void free_list(list_node *list);
//! codigo fuente: https://stackoverflow.com/questions/400951/does-c-have-a-foreach-loop-construct/1236910#1236910

// TODO *************** Implementacion de la busqueda de un número mayor, Mayor o Igual ***************

#define Mayor(valorA, valorB) ((valorA > valorB) ? valorA : valorB)
#define MayorEqual(valorA, valorB) ((valorA >= valorB) ? valorA : valorB)


#endif