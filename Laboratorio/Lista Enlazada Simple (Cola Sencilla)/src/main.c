#include <stdio.h>
#include <stdlib.h>

// Estructura para los nodos de la cola
struct Node {
    int value;
    struct Node* next;
};

// Estructura para la cola
struct Queue {
    struct Node* head;
    struct Node* tail;
};

// Función para crear una nueva cola vacía
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Función para verificar si la cola está vacía
int isEmpty(struct Queue* q) {
    return q->head == NULL;
}

// Función para agregar un elemento al final de la cola
void enqueue(struct Queue* q) {
    // Pedir al usuario que ingrese el valor
    int value;
    printf("Ingrese el valor: ");
    scanf("%d", &value);

    // Crear un nuevo nodo con el valor proporcionado
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    // Si la cola está vacía, el nuevo nodo es el frente y la cola
    if (q->head == NULL) {
        q->head = newNode;
        q->tail = newNode;
        return;
    }

    // Agregar el nuevo nodo al final de la cola
    q->tail->next = newNode;
    q->tail = newNode;
}

// Función para eliminar el primer elemento de la cola
int dequeue(struct Queue* q) {
    // Verificar si la cola está vacía
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return -1;
    }

    // Obtener el valor del primer nodo y eliminarlo de la cola
    int value = q->head->value;
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);

    // Si la cola quedó vacía, actualizar el puntero al final de la cola
    if (q->head == NULL) {
        q->tail = NULL;
    }

    return value;
}

// Función para obtener el valor del primer elemento de la cola sin eliminarlo
int peek(struct Queue* q) {
    // Verificar si la cola está vacía
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return -1;
    }

    return q->head->value;
}

// Función para imprimir los elementos de la cola
void printQueue(struct Queue* q) {
    // Verificar si la cola está vacía
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return;
    }

    // Recorrer la cola e imprimir los valores de los nodos
    printf("Elementos de la cola: ");
    struct Node* temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Crear una cola vacía
    struct Queue* q = createQueue();

    // Menú de opciones
    int option;
    do {
        printf("\n-- Cola Sencilla --\n");
        printf("1. Agregar un elemento a la cola\n");
        printf("2. Eliminar el primer elemento de la cola\n");
        printf("3. Ver el primer elemento de la cola\n");
        printf("4. Imprimir los elementos de la cola\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enqueue(q);
                break;
            case 2:
                printf("Elemento eliminado: %d\n", dequeue(q));
                break;
            case 3:
                printf("Primer elemento de la cola: %d\n", peek(q));
                break;
            case 4:
                printQueue(q);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }

    } while (option != 5);

    return 0;
}
