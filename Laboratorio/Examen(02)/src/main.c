#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para cada nodo de la lista doblemente enlazada
typedef struct Node {
    int clave;
    char descripcion[50];
    float precio;
    float descuento;
    int existencias;
    struct Node *prev;
    struct Node *next;
} Node;

// Función para crear un nuevo nodo de la lista doblemente enlazada
Node* crear_nodo(int clave, char descripcion[], float precio, float descuento, int existencias) {
    Node* nuevo_nodo = (Node*) malloc(sizeof(Node));
    nuevo_nodo->clave = clave;
    strcpy(nuevo_nodo->descripcion, descripcion);
    nuevo_nodo->precio = precio;
    nuevo_nodo->descuento = descuento;
    nuevo_nodo->existencias = existencias;
    nuevo_nodo->prev = NULL;
    nuevo_nodo->next = NULL;
    return nuevo_nodo;
}

// Función para insertar un nuevo nodo al final de la lista doblemente enlazada
void insertar_nodo_al_final(Node **head_ref, int clave, char descripcion[], float precio, float descuento, int existencias) {
    Node* nuevo_nodo = crear_nodo(clave, descripcion, precio, descuento, existencias);
    if (*head_ref == NULL) {
        *head_ref = nuevo_nodo;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = nuevo_nodo;
    nuevo_nodo->prev = last;
}

// Función para imprimir la lista doblemente enlazada
void imprimir_lista(Node *node) {
    while (node != NULL) {
        printf("Clave: %d, Descripción: %s, Precio: %.2f, Descuento: %.2f, Existencias: %d\n",
               node->clave, node->descripcion, node->precio, node->descuento, node->existencias);
        node = node->next;
    }
    printf("\n");
}

// Función para eliminar los nodos de la lista doblemente enlazada que tienen existencias 0
void eliminar_nodos_existencias_cero(Node **head_ref) {
    Node *current = *head_ref;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        if (current->existencias == 0) {
            if (current == *head_ref) {
                *head_ref = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            free(current);
        }
        current = next_node;
    }
}

int main() {
    Node *head = NULL;
    int clave, existencias;
    char descripcion[50];
    float precio, descuento;
    int opcion;
    do {
        printf("Seleccione una opción:\n");
        printf("1 - Agregar un nuevo producto\n");
        printf("2 - Mostrar la lista de productos\n");
        printf("3 - Eliminar los productos con existencias 0\n");
        printf("4 - Salir\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese la clave del producto: ");
                scanf("%d", &clave);
                printf("Ingrese la descripción del producto: ");
                scanf(" %[^\n]s", descripcion);
                printf("Ingrese el precio del producto: ");
                scanf("%f", &precio);
                printf("Ingrese el descuento del producto: ");
                scanf("%f", &descuento);
                printf("Ingrese las existencias del producto: ");
                scanf("%d", &existencias);
                insertar_nodo_al_final(&head, clave, descripcion, precio, descuento, existencias);
                break;
            case 2:
                imprimir_lista(head);
                break;
            case 3:
                eliminar_nodos_existencias_cero(&head);
                break;
            case 4:
                break;
            default:
                printf("Opción inválida. Seleccione una opción válida.\n");
        }
    } while (opcion != 4);
    return 0;
}
