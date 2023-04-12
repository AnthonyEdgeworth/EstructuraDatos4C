#include <stdio.h>
#include <stdlib.h>

int ejemplo() {
    int n = 5;
 int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    // imprimir el valor de cada elemento
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
