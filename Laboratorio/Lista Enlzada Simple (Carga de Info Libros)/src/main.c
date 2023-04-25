#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de nodo
struct Node {
    char bookType[50];
    int serialNo;
    struct Node* next;
};

// Función para agregar un nuevo nodo al inicio de la lista
void insertAtBeginning(struct Node** headRef, char bookType[], int serialNo) {
    // Crear un nuevo nodo
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Asignar los valores de los datos
    strcpy(newNode->bookType, bookType);
    newNode->serialNo = serialNo;

    // Establecer el siguiente nodo como el actual encabezado
    newNode->next = *headRef;

    // Establecer el nuevo nodo como el encabezado
    *headRef = newNode;
}

// Función para imprimir la lista enlazada
void printList(struct Node* node) {
    while (node != NULL) {
        printf("Tipo de libro: %s, No. de serie: %d\n", node->bookType, node->serialNo);
        node = node->next;
    }
}

int main() {
    // Inicializar la lista vacía
    struct Node* head = NULL;

    // Solicitar al usuario que ingrese los valores para los nodos
    char bookType[50];
    int serialNo;
    int numNodes;

    printf("Ingrese el número de nodos que desea agregar a la lista: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("\nIngrese el tipo de libro para el nodo %d: ", i+1);
        scanf("%s", bookType);

        printf("Ingrese el número de serie para el nodo %d: ", i+1);
        scanf("%d", &serialNo);

        // Agregar el nodo a la lista
        insertAtBeginning(&head, bookType, serialNo);
    }

    // Imprimir la lista
    printf("\nLista de libros:\n");
    printList(head);

    return 0;
}
