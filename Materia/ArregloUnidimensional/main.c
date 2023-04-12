/**
 * @file Principal.c
 * @author Eduardo Antonio Figueroa Salas (you@domain.com)
 * @brief Hacer un arreglo Unidimensional que guarde n numero de elementos
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Archivo Fuente principal*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TADUnidimensionales.h"
#include <limits.h> //Establece Rango

int main(void)
{
    TADcadena cad = (int *)calloc(MAX, sizeof(int)); // asignar memoria a cad

    Menu(cad);

    free(cad); // liberar memoria antes de salir de main

    return 0;
}
