#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

void insertRear(Deque* deque, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if (deque->rear == NULL) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

void insertFront(Deque* deque, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (deque->front == NULL) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

char deleteFront(Deque* deque) {
    if (deque->front == NULL) {
        return '\0';
    }
    Node* temp = deque->front;
    char data = temp->data;
    deque->front = temp->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

char deleteRear(Deque* deque) {
    if (deque->rear == NULL) {
        return '\0';
    }
    Node* temp = deque->rear;
    char data = temp->data;
    deque->rear = temp->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

void printDeque(Deque deque) {
    printf("Cola doble: ");
    Node* current = deque.front;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);
    
    insertRear(&deque, 'A');
    insertRear(&deque, 'B');
    insertRear(&deque, 'C');
    
    printf("Después de insertar A, B, C al final:\n");
    printDeque(deque);
    
    deleteFront(&deque);
    
    printf("Después de eliminar por el frente:\n");
    printDeque(deque);
    
    insertFront(&deque, 'D');
    insertFront(&deque, 'E');
    
    printf("Después de insertar D, E al frente:\n");
    printDeque(deque);
    
    deleteRear(&deque);
    
    printf("Después de eliminar por el final:\n");
    printDeque(deque);
    
    deleteRear(&deque);
    
    printf("Después de eliminar por el final de nuevo:\n");
    printDeque(deque);
    
    deleteFront(&deque);
    
    printf("Después de eliminar por el frente de nuevo:\n");
    printDeque(deque);
    
    return 0;
}
