#include "tdaColaEntradaRestringida.h"

int main(void)
{

    short int option = 0;
    int insertElement = 0;

    printf("Bienvenido a la estructura Circular Entrada Restringida\n");
    printf("Dame el tamaño de la estructura:_");
    scanf("%d", &maximo);

    Inicializar(maximo);

    do
    {
        printf("\n\n");
        printf("1. Insertar elemento\n");
        printf("2. Eliminar inicio\n");
        printf("3. Eliminar final\n");
        printf("4. Visualizar\n");
        printf("5. Salir\n");

        fflush(stdin);
        printf(":_");
        scanf("%hd", &option);

        switch (option)
        {
        case 1:
            printf("Dame el elemento a insertar: ");
            scanf("%d", &insertElement);
            Inserta(insertElement);
            break;

        case 2:
            if (!esVacia())
            {
                printf("Elemento eliminado: %d", EliminaInicio());
            }
            else
            {
                printf("La cola esta vacia.");
            }
            break;

        case 3:
            if (!esVacia())
            {
                printf("Elemento eliminado: %d", EleminarFinal());
            }
            else
            {
                printf("La cola esta vacia.");
            }
            break;

        case 4:
            VisualizaColaD(maximo);
            break;

        case 5:
            printf("Saliendo...");
            break;

        default:
            printf("Opcion no valida, intente de nuevo.");
            break;
        }

    } while (option != 5);

    return 0;
}
