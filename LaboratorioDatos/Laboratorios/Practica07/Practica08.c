// Eduardo Antonio Figueroa Salas
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    printf("\n dame el numero de filas: ");
    scanf("%d", &n);
    printf("\n dame el numero de columnas: ");
    scanf("%d", &m);
    int i, j, arreglo[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (j <= i)
            {
                printf("\n arreglo[%d][%d]", i, j);
                scanf("\n %d", &arreglo[i][j]);
            }
            else
                arreglo[i][j] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            printf("\n arreglo[%d][%d]=%d", i, j, arreglo[i][j]);
}
