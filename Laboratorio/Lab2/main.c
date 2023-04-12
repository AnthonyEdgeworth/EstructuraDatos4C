#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "TDASEP.h"

#define MAX_INSCRIPCIONES 100

int main() {
    struct Inscripcion inscripciones[MAX_INSCRIPCIONES];
    int opcion, num_inscripciones = 0;
    char nombre_archivo[50];
    
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                capturar_inscripcion(inscripciones, &num_inscripciones);
                break;
            case 2:
                mostrar_inscripciones(inscripciones, num_inscripciones);
                break;
            case 3:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre_archivo);
                enviar_inscripciones(nombre_archivo, inscripciones, num_inscripciones);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);
    
    return 0;
}

