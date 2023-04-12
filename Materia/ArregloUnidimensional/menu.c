#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TADUnidimensionales.h"
#include <limits.h> //Establece Rango


int opc;

void Menu(int *s)
{
    printf("Implementa las operaciones basicas de un arreglo unidimensional\n");
    fflush(stdin);

    do
    {
        int d;
        fflush(stdin);
        printf("\nOperaciones Arreglo Unidimensional\n");
        printf("1.......Insertar\n");
        printf("2.......Eliminar\n");
        printf("3.......Visualizar\n");
        //printf("4.......Ordenar\n");
        printf("5.......Modificar\n");
        printf("0.......Salir\n Elige una Opcion\n");
        scanf("%d", &opc);

        switch (opc)
        {
            case 1:
                printf("Dame el elemento a insertar ");
                scanf("%d", &d);
                fflush(stdin);

                if (Add(s, d) == 1)
                    printf("El elemento se insertó correctamente\n");
                else
                    printf("El elemento no se insertó\n");

                break;

            case 2:
                printf("\nDame el elemento a eliminar ");
                scanf("%d", &d);
                fflush(stdin);

                if (Remove(s, d) == 1)
                    printf("El elemento se eliminó correctamente\n");
                else
                    printf("El elemento no se eliminó\n");

                break;

            case 3:
                Visualice(s);
                break;

            case 0:
                break;

            //case 4:
            //    Ordenar(s);
            //    break;

            case 5:
                Modificar(s);
                break;

            default:
                printf("Opcion no válida\n");
        }
    } while (opc != 0);
}


