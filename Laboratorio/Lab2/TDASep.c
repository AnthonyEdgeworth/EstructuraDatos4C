#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDASEP.h"

#define MAX_KIDS 100

struct Kid array[MAX_KIDS];
int tam = 0;

int Add(struct Kid *newKid) {
    // Si el arreglo está lleno, no se puede agregar más elementos
    if (tam >= MAX_KIDS) {
        return -1;
    }
    // Encontrar la posición donde se debe insertar el nuevo elemento
    int pos = 0;
    while (pos < tam && strcmp(array[pos].NombreKid, newKid->NombreKid) < 0) {
        pos++;
    }
    // Desplazar los elementos hacia la derecha para insertar el nuevo elemento
    for (int i = tam; i > pos; i--) {
        array[i] = array[i - 1];
    }
    array[pos] = *newKid;
    tam++;
    return 0;
}

int Delete(char *nombre) {
    // Encontrar la posición del elemento a eliminar
    int pos = 0;
    while (pos < tam && strcmp(array[pos].NombreKid, nombre) != 0) {
        pos++;
    }
    if (pos == tam) {
        // No se encontró el elemento a eliminar
        return -1;
    }
    // Desplazar los elementos hacia la izquierda para eliminar el elemento
    for (int i = pos; i < tam - 1; i++) {
        array[i] = array[i + 1];
    }
    tam--;
    return 0;
}

int Find(char *nombre) {
    // Buscar el elemento en el arreglo
    int pos = 0;
    while (pos < tam && strcmp(array[pos].NombreKid, nombre) != 0) {
        pos++;
    }
    if (pos == tam) {
        // No se encontró el elemento
        return -1;
    }
    return pos;
}

void PrintAll() {
    printf("Nombre del niño\tCURP\tNombre del padre\tInstituto anterior\tPromedio anterior\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < tam; i++) {
        printf("%s\t%s\t%s\t%s\t%f\n", array[i].NombreKid, array[i].CURP, array[i].NombrePadre, array[i].InstitutoAnterior, array[i].PromedioAnterior);
    }
}

void WriteToFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: no se pudo abrir el archivo para escritura.\n");
        return;
    }
    fprintf(file, "Nombre del niño,CURP,Nombre del padre,Instituto anterior,Promedio anterior\n");
    for (int i = 0; i < tam; i++) {
        fprintf(file, "%s,%s,%s,%s,%f\n", array[i].NombreKid, array[i].CURP, array[i].NombrePadre, array[i].InstitutoAnterior, array[i].PromedioAnterior);
    }
    fclose(file);
}
