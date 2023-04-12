#include <stdio.h>
#include "menu.h"

int menu() {
    int opcion;
    printf("\n 1. Capturar información de inscripciones\n");
    printf(" 2. Visualizar información\n");
    printf(" 3. Enviar información mediante archivo de texto\n");
    printf(" 4. Salir\n");
    printf("Selecciona una opción: ");
    scanf("%d", &opcion);
    return opcion;
}


