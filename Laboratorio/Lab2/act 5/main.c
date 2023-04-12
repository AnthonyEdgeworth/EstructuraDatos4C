#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void obtener_subcadena(char *cadena);

int main() {
    char cadena[MAX_SIZE];
    
    printf("Ingrese una cadena de texto: ");
    fgets(cadena, MAX_SIZE, stdin);
    
    obtener_subcadena(cadena);
    
    return 0;
}

void obtener_subcadena(char *cadena) {
    int tamano = strlen(cadena);
    int inicio = 0, fin = 0, max_inicio = 0, max_fin = 0, max_tamano = 0;
    
    for (int i = 0; i < tamano; i++) {
        if (cadena[i] == ' ' || cadena[i] == '\n') {
            fin = i - 1;
            if (fin - inicio + 1 > max_tamano) {
                max_inicio = inicio;
                max_fin = fin;
                max_tamano = fin - inicio + 1;
            }
            inicio = i + 1;
        }
    }
    
    printf("La subcadena mas grande es: ");
    for (int i = max_inicio; i <= max_fin; i++) {
        printf("%c", cadena[i]);
    }
    printf("\n");
    
    printf("El TDA arreglo es: ");
    for (int i = 0; i < tamano; i++) {
        printf("%c", cadena[i]);
    }
    printf("\n");
    
    printf("Caracteres y sus direcciones de memoria: \n");
    for (int i = 0; i < tamano; i++) {
        printf("Caracter: %c - Direccion de memoria: %p\n", cadena[i], (void *)&cadena[i]);
    }
}

