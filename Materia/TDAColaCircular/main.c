#include "TDAColaCircular.h"

int main()
{
    int tamano, opcion, ele;
    ColaCircular cola;
    
    printf("Ingrese el tamaño de la cola: ");
    scanf("%d", &tamano);

    cola = crearCc(tamano);

    do
    {
        printf("\nMenu de Opciones\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Visualizar\n");
        printf("4. Salir\n");

        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (isFull(cola))
            {
                printf("Desbordamiento\n");
            }
            else
            {
                printf("Ingrese un elemento: ");
                scanf("%d", &ele);
                QueueCc(&cola, ele);
                printf("Elemento %d encolado con éxito\n", ele);
            }
            break;
        case 2:
            ele = DequeueCc(&cola);
            if (ele == 0)
            {
                printf("Subdesbordeamiento\n");
            }
            else
            {
                printf("Elemento %d desencolado con éxito\n", ele);
            }
            break;
        case 3:
            VisualiceCc(&cola);
            break;
        case 4:
            printf("Programa finalizado\n");
            break;
        default:
            printf("Opción inválida\n");
            break;
        }

    } while (opcion != 4);

    free(cola.datos);

    return 0;
}
