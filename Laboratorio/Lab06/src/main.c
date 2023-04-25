#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUEUE_SIZE 10

// Definición de la estructura de datos para cada documento en la cola de impresión
struct Document {
    char owner[50];
    char name[50];
    char state[20];
    int size;
    time_t date_time;
};

// Definición de la estructura de datos para la cola de impresión
struct Queue {
    int front, rear, count;
    struct Document documents[MAX_QUEUE_SIZE];
};

// Función para inicializar la cola de impresión
void initialize_queue(struct Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Función para verificar si la cola de impresión está vacía
int is_empty(struct Queue *queue) {
    return (queue->count == 0);
}

// Función para verificar si la cola de impresión está llena
int is_full(struct Queue *queue) {
    return (queue->count == MAX_QUEUE_SIZE);
}

// Función para agregar un documento a la cola de impresión
void enqueue(struct Queue *queue, struct Document document) {
    if (!is_full(queue)) {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->documents[queue->rear] = document;
        queue->count++;
        printf("Documento %s agregado a la cola de impresión.\n", document.name);
    }
    else {
        printf("La cola de impresión está llena, no se puede agregar el documento %s.\n", document.name);
    }
}

// Función para retirar un documento de la cola de impresión
void dequeue(struct Queue *queue) {
    if (!is_empty(queue)) {
        struct Document document = queue->documents[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->count--;
        printf("El documento %s ha sido retirado de la cola de impresión.\n", document.name);
    }
    else {
        printf("La cola de impresión está vacía, no se puede retirar ningún documento.\n");
    }
}

// Función para imprimir un documento de la cola de impresión
void print_document(struct Document document) {
    printf("Imprimiendo documento %s de %s...\n", document.name, document.owner);
    sleep(rand() % 10); // Retraso aleatorio para simular la impresión
    printf("El documento %s ha sido impreso.\n", document.name);
}

// Función para reasignar la cola de impresión y enviar los documentos a imprimir
void reassign_queue(struct Queue *queue) {
    int i;
    for (i = 0; i < queue->count; i++) {
        if (strcmp(queue->documents[queue->front].state, "En espera") == 0) {
            // Busca la primera impresora disponible y envía el documento a imprimir
            printf("Buscando impresora disponible para imprimir el documento %s...\n", queue->documents[queue->front].name);
            print_document(queue->documents[queue->front]);
            strcpy(queue->documents[queue->front].state, "Impreso");
        }
        else {
            // Mueve el documento al final de la cola si ya ha sido impreso o
            // si está en proceso de impresión
            queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
            queue->documents[queue->rear] = queue->documents[queue->front];
            queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

// Función principal
int main() {
    struct Queue queue;
    struct Document document;
    srand(time(NULL)); // Inicializa la semilla aleatoria para los retrasos de impresión

    initialize_queue(&queue);

    // Ejemplo de uso: agregar 5 documentos a la cola de impresión
    strcpy(document.owner, "Juan");
    strcpy(document.name, "Documento 1");
    strcpy(document.state, "En espera");
    document.size = 100;
    document.date_time = time(NULL);
    enqueue(&queue, document);

    strcpy(document.owner, "María");
    strcpy(document.name, "Documento 2");
    strcpy(document.state, "En espera");
    document.size = 200;
    document.date_time = time(NULL);
    enqueue(&queue, document);

    strcpy(document.owner, "Pedro");
    strcpy(document.name, "Documento 3");
    strcpy(document.state, "En espera");
    document.size = 150;
    document.date_time = time(NULL);
    enqueue(&queue, document);

    strcpy(document.owner, "Ana");
    strcpy(document.name, "Documento 4");
    strcpy(document.state, "En espera");
    document.size = 300;
    document.date_time = time(NULL);
    enqueue(&queue, document);

    strcpy(document.owner, "Luis");
    strcpy(document.name, "Documento 5");
    strcpy(document.state, "En espera");
    document.size = 250;
    document.date_time = time(NULL);
    enqueue(&queue, document);

    // Simulación de la impresión de documentos de la cola de impresión
    while (!is_empty(&queue)) {
        reassign_queue(&queue);
        sleep(5); // Retraso para simular la reasignación de la cola de impresión
    }

    return 0;
}
