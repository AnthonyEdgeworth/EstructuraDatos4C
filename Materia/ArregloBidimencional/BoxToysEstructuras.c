/**
 * @file BoxToysEstructuras.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "BoxToysEstructuras.h"

char input[10];
int value;

void print_array(list_node *array)
{
    printf("Values entered:\n");
    foreach (item, array)
    {
        printf("%d\n", *(int *)item->data);
    }
}

list_node *menu_array(list_node **array)
{
    list_node *current = NULL;

    while (true)
    {
        printf("Enter a number or 'cancel': ");
        scanf("%s", input);
        if (strcmp(input, "CANCEL") == 0 || strcmp(input, "cancel") == 0)
        {
            break;
        }

        value = atoi(input);
        if (value == 0 && strcmp(input, "0") != 0)
        {
            printf("Invalid input. Please enter a number or 'Cancel'\n");
            continue;
        }

        list_node *new_node = malloc(sizeof(list_node));
        new_node->data = malloc(sizeof(int));
        new_node->next = NULL;
        *(int *)new_node->data = value;

        if (!(*array))
        {
            *array = new_node;
            current = *array;
        }
        else
        {
            current->next = new_node;
            current = current->next;
        }
    }

    print_array(*array);

    /*free_list(*array);
    *array = NULL;*/

    return *array;
}

void free_list(list_node *list)
{
    list_node *current = list;
    while (current != NULL)
    {
        list_node *temp = current->next;
        free(current->data);
        free(current);
        current = temp;
    }
}



// TODO: *************** Ejemplo de uso ***************

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BoxToysEstructuras.h"

int main(void)
{
    list_node *array = NULL;
    menu_array(&array);

    // aquí puedes hacer uso de la lista para otras operaciones
    // ...

    free_list(array);
    array = NULL;

    return 0;
}







*/

