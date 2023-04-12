#include "Tridimensional.h"

int cntelem = 0, m = 0, n = 0, pl = 0;
int ***tridi;
int dato = 0;
Indrcp indrcp;


bool Crear(int m1, int n1, int p) {
    m = m1;
    n = n1;
    pl = p;

    // Asignar memoria dinámica para el arreglo tridimensional
    tridi = (int ***)malloc(p * sizeof(int **));
    for (int i = 0; i < p; i++) {
        tridi[i] = (int **)malloc(m * sizeof(int *));
        for (int j = 0; j < m; j++) {
            tridi[i][j] = (int *)malloc(n * sizeof(int));
        }
    }

    // Inicializar el índice de posición actual
    indrcp.p = 0;
    indrcp.r = 0;
    indrcp.c = 0;

    cntelem = 0;
    return true;
}



bool EsVacia()
{

    return cntelem == 0;
}

bool EsLlena()
{

    return cntelem >= (pl * m * n);
}

bool InsertarDesordenado(int dato){
    if(tridi == NULL){ // Verificar si la estructura está vacía
        printf("Error: la estructura no ha sido creada.\n");
        return false;
    }
    
    if(cntelem >= (m*n*pl)){ // Verificar si la estructura está llena
        printf("Error: la estructura está llena, no se puede insertar más elementos.\n");
        return false;
    }
    
    // Buscar espacio disponible para la inserción
    int i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(k=0;k<pl;k++){
                if(tridi[i][j][k] == INT_MIN){ // Verificar si el espacio está vacío
                    tridi[i][j][k] = dato;
                    cntelem++;
                    return true;
                }
            }
        }
    }
    
    // Si no se encontró espacio vacío, se aumenta la capacidad de la estructura
    int newm = m+1;
    int ***newtridi = (int***)malloc(sizeof(int**) * newm);
    if(newtridi == NULL){
        printf("Error: no se pudo aumentar la capacidad de la estructura.\n");
        return false;
    }
    
    for(i=0;i<newm;i++){
        newtridi[i] = (int**)malloc(sizeof(int*) * n);
        if(newtridi[i] == NULL){
            printf("Error: no se pudo aumentar la capacidad de la estructura.\n");
            return false;
        }
        for(j=0;j<n;j++){
            newtridi[i][j] = (int*)malloc(sizeof(int) * pl);
            if(newtridi[i][j] == NULL){
                printf("Error: no se pudo aumentar la capacidad de la estructura.\n");
                return false;
            }
            memset(newtridi[i][j], INT_MIN, pl*sizeof(int)); // Inicializar nuevos elementos en INT_MIN
        }
    }
    
    // Copiar elementos de la estructura original a la nueva estructura
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            memcpy(newtridi[i][j], tridi[i][j], pl*sizeof(int));
        }
    }
    
    // Insertar elemento en el nuevo espacio disponible
    newtridi[m][0][0] = dato;
    cntelem++;
    
    // Liberar memoria de la estructura original y actualizar variables globales
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            free(tridi[i][j]);
        }
        free(tridi[i]);
    }
    free(tridi);
    tridi = newtridi;
    m = newm;
    indrcp.p = m-1;
    indrcp.r = 0;
    indrcp.c = 0;
    
    return true;
}

Indrcp BuscaSec(int d)
{
    Indrcp pos;
    pos.p = 0;
    pos.r = 0;
    pos.c = 0;
    int cont = 1;

    if (EsVacia())
    {
        pos.p = -1;
        pos.r = -1;
        pos.c = -1;
        return pos;
    }

    while (cont <= cntelem && tridi[pos.p][pos.r][pos.c] != d)
    {
        cont++;
        if (pos.c >= n - 1 && pos.r <= m - 1)
        {
            pos.r++;
            pos.c = 0;
            if (pos.r > m - 1)
            {
                pos.p++;
                pos.r = 0;
                pos.c = 0;
            }
        }
        else
            pos.c++;
    }

    if (cont > cntelem) 
    {
        // Element not found
        pos.p = -1;
        pos.r = -1;
        pos.c = -1; 
    }

    return pos; 
}

bool EliminaDesorden(int d)
{
    // Buscar la posición del elemento a eliminar
    Indrcp pos;
    pos = BuscaSec(d);

    // Verificar si el elemento no se encontró
    if (pos.p == -1 && pos.r == -1 && pos.c == -1)
    {
        return false;
    }

    // Copiar el elemento final al lugar del elemento a eliminar
    int last_p = pl - 1;
    int last_r = m - 1;
    int last_c = n - 1;
    int last_val = tridi[last_p][last_r][last_c];

    tridi[pos.p][pos.r][pos.c] = last_val;

    // Eliminar el último elemento
    tridi[last_p][last_r][last_c] = 0;

    // Decrementar el contador de elementos
    cntelem--;

    return true;
}

bool ModificaDesordenado(Indrcp pos, int dato)
{
    int i = pos.r;
    int j = pos.c;
    int l = pos.p;
    if (i >= m || j >= n || l >= pl)
    {
        return false;
    }
    tridi[l][i][j] = dato;
    return true;
}

int cmpfunc(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return (*p1 - *p2);
}
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void OrdenaDesordenado() {
    // Copiar solo los elementos no nulos del arreglo tridimensional en un arreglo unidimensional
    int *temp = (int *)malloc(cntelem * sizeof(int));
    int index = 0;
    for (int i = 0; i < pl; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (tridi[i][j][k] != 0) {
                    temp[index++] = tridi[i][j][k];
                }
            }
        }
    }

    // Ordenar el arreglo unidimensional de forma ascendente
    qsort(temp, cntelem, sizeof(int), comparar);

    // Copiar los elementos ordenados del arreglo unidimensional de vuelta al arreglo tridimensional
    index = 0;
    for (int i = 0; i < pl && index < cntelem; i++) {
        for (int j = 0; j < m && index < cntelem; j++) {
            for (int k = 0; k < n && index < cntelem; k++) {
                tridi[i][j][k] = temp[index++];
            }
        }
    }

    // Rellenar el resto del arreglo tridimensional con ceros
    for (int i = 0; i < pl; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (tridi[i][j][k] == 0 && index < cntelem) {
                    tridi[i][j][k] = temp[index++];
                } else if (tridi[i][j][k] == 0) {
                    tridi[i][j][k] = 0;
                }
            }
        }
    }

    // Liberar la memoria del arreglo temporal
    free(temp);
}





void imprimir()
{
    int nivel01 = 0;
    int nivel02 = 0;
    int nivel03 = 0;

    for (nivel01 = 0; nivel01 < pl; nivel01++)
    {
        for (nivel02 = 0; nivel02 < m; nivel02++)
        {
            for (nivel03 = 0; nivel03 < n; nivel03++)
            {
                printf("%d ", tridi[nivel01][nivel02][nivel03]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void menuModificar()
{
    Indrcp pos;
    int dato;
    printf("Ingresa las coordenadas (r,c,p) del elemento a modificar: ");
    scanf("%d,%d,%d", &pos.r, &pos.c, &pos.p);
    printf("Ingresa el nuevo dato: ");
    scanf("%d", &dato);

    if (ModificaDesordenado(pos, dato))
    {
        printf("El elemento se ha modificado correctamente.\n");
    }
    else
    {
        printf("No se pudo modificar el elemento.\n");
    }
}
