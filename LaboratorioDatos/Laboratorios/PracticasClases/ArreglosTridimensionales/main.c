#include <stdio.h>
#include <stdlib.h>
#include "Tridimensional.h"

int main()
{
    int opcion, valor;
    int m, n, p;

    do
    {
        printf("\nMenu:\n");
        printf("1. Crear arreglo tridimensional\n");
        printf("2. Insertar elemento\n");
        printf("3. Eliminar elemento\n");
        printf("4. Modificar elemento\n");
        printf("5. Ordenar arreglo\n");
        printf("6. Imprimir arreglo\n");
        printf("0. Salir\n");
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        fflush(stdin);
            printf("Ingrese la dimension m: ");
            scanf("%d", &m);
            fflush(stdin);
            printf("Ingrese la dimension n: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("Ingrese la dimension p: ");
            scanf("%d", &p);
            fflush(stdin);
            Crear(m, n, p);
            printf("Arreglo tridimensional creado exitosamente.\n");
            break;

        case 2:
        fflush(stdin);
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &valor);
            if (InsertarDesordenado(valor))
            {
                printf("Elemento insertado exitosamente.\n");
            }
            else
            {
                printf("No se pudo insertar el elemento.\n");
            }
            break;

        case 3:
        fflush(stdin);
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &valor);
            if (EliminaDesorden(valor))
            {
                printf("Elemento eliminado exitosamente.\n");
            }
            else
            {
                printf("No se pudo eliminar el elemento.\n");
            }
            break;

        case 4:
        fflush(stdin);
            menuModificar();
            break;

        case 5:
        fflush(stdin);
            OrdenaDesordenado();
            printf("Arreglo ordenado exitosamente.\n");
            break;

        case 6:
        fflush(stdin);
           imprimir();
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");
            break;
        }

    } while (opcion != 0);

    return 0;
}
