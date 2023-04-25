#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro {
    char categoria[20];
    char fecha[20];
    int cantidad;
};

struct nodo {
    struct registro datos;
    struct nodo* siguiente;
};

typedef struct nodo* lista;

void ordenar_burbuja(struct registro datos[], int n);
lista agregar_nodo(lista lista_original, struct registro datos);
void eliminar_duplicados(lista lista_original);
void imprimir_lista(lista lista_original);
void eliminar_comentarios(char* nombre_archivo);
void liberar_lista(lista lista_original);

int main() {

    FILE* archivo;
    struct registro datos[100];
    lista lista_ordenada = NULL;
    int i = 0;
system("pwd");
    archivo = fopen("datos.tvs", "r");
    if (archivo == NULL) {   
        printf("Error, no se pudo abrir o encontrar el archivo.\n");
        
        exit(1);
    }

    eliminar_comentarios("datos.tvs");

    while (fscanf(archivo, "%s %s %d", datos[i].categoria, datos[i].fecha, &datos[i].cantidad) != EOF) {
        i++;
    }

    ordenar_burbuja(datos, i);

    for (int j = 0; j < i; j++) {
        lista_ordenada = agregar_nodo(lista_ordenada, datos[j]);
    }

    eliminar_duplicados(lista_ordenada);

    imprimir_lista(lista_ordenada);

    liberar_lista(lista_ordenada);

    fclose(archivo);
    printf("\n");

    return 0;
}


void ordenar_burbuja(struct registro datos[], int n) {
    struct registro temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(datos[j].categoria, datos[j + 1].categoria) > 0) {
                temp = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temp;
            }
        }
    }
}

lista agregar_nodo(lista lista_original, struct registro datos) {
    lista nuevo_nodo, actual, anterior;

    nuevo_nodo = (lista)malloc(sizeof(struct nodo));
    nuevo_nodo->datos = datos;
    nuevo_nodo->siguiente = NULL;

    if (lista_original == NULL) {
        lista_original = nuevo_nodo;
    } else {
        actual = lista_original;
        anterior = NULL;

        while (actual != NULL && strcmp(datos.categoria, actual->datos.categoria) > 0) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (anterior == NULL) {
            nuevo_nodo->siguiente = actual;
            lista_original = nuevo_nodo;
        } else {
            anterior->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = actual;
        }
    }

    return lista_original;
}

void eliminar_duplicados(lista lista_original) {
    lista actual, siguiente;

    actual = lista_original;

    while (actual != NULL && actual->siguiente != NULL) {
        if (strcmp(actual->datos.categoria, actual->siguiente->datos.categoria) == 0 &&
            strcmp(actual->datos.fecha, actual->siguiente->datos.fecha) == 0) {
            siguiente = actual->siguiente;
            actual->siguiente = siguiente->siguiente;
            free(siguiente);
        } else {
            actual = actual->siguiente;
        }
    }
}

void liberar_lista(lista lista_original) {
    lista actual = lista_original;
    while (actual != NULL) {
        lista temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

void imprimir_lista(lista lista_original) {
    lista actual;
    printf("CATEGORIA\tFECHA\t\tCANTIDAD\n");

    actual = lista_original;

    while (actual != NULL) {
        printf("%s\t\t%s\t%d\n", actual->datos.categoria, actual->datos.fecha, actual->datos.cantidad);
        actual = actual->siguiente;
    }
}

void eliminar_comentarios(char* nombre_archivo) {
    FILE* archivo_original = fopen(nombre_archivo, "r");
    FILE* archivo_temporal = fopen("temp.txt", "w");

    if (archivo_original == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char linea[100];
    while (fgets(linea, 100, archivo_original) != NULL) {
        if (linea[0] == '/' && linea[1] == '/') {
            continue;  // Ignorar línea de comentario
        }
        fprintf(archivo_temporal, "%s", linea);  // Escribir línea en archivo temporal
    }

    fclose(archivo_original);
    fclose(archivo_temporal);

    remove(nombre_archivo);
    rename("temp.txt", nombre_archivo);
}

