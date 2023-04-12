#include "ColaDobleSalidaR.h"


int main()
{
    int opcion, dato, elemento;

    printf("Ingrese el tamaño máximo de la cola doble de salida restringida: ");
    scanf("%d", &maximo);

    CrearCDSR(maximo);

    do {
        printf("\n\n--- MENU DE OPCIONES ---\n");
        printf("1. Insertar elemento al inicio\n");
        printf("2. Insertar elemento al final\n");
        printf("3. Eliminar elemento\n");
        printf("4. Mostrar elementos\n");
        printf("0. Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 0:
                printf("Saliendo...\n");
                break;

            case 1:
                printf("Ingrese el elemento a insertar al inicio: ");
                scanf("%d", &dato);

                InsertaInicio(dato);

                printf("Elemento %d insertado correctamente al inicio.\n", dato);
                break;

            case 2:
                printf("Ingrese el elemento a insertar al final: ");
                scanf("%d", &dato);

                InsertarFinal(dato);

                printf("Elemento %d insertado correctamente al final.\n", dato);
                break;

            case 3:
                elemento = Eliminar();

                if (elemento == 0) {
                    printf("No se pudo eliminar el elemento de la cola doble de salida restringida.\n");
                } else {
                    printf("Elemento %d eliminado correctamente de la cola doble de salida restringida.\n", elemento);
                }
                break;

            case 4:
                printf("Elementos en la cola doble de salida restringida:\n");
                muestraColaDoble();
                break;

            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}