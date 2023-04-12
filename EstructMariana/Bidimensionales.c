//mariana estefania barcenas rodriguez
// 25022022
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define m 3
#define n 3

typedef struct {
    int i;
    int j;
}Indij;

int matriz[m][n];
Indij indij;
int dato =0;

bool insertarDesordenado(int);
bool EliminaDesorden(int);
void imprimir();
Indij BuscaSec(int);
bool EsVacia();
bool ModificaDesordenado(int,int);
void OrdenarDesordenado();


int main(int argc, char *argv[]){
    int opcion2;
    int opcion;
    int dato2;
    
    int intentar=true;
    while(intentar==true){
        do{    
            printf("1...Insertar\n");
            printf("2...Eliminar\n");
            printf("3...Visualizar\n");
            printf("4...Modificar\n");
            printf("5...Ordenar\n");
            printf("0...Salir\nElige una opcion\n");
            scanf("%d",&opcion2);
            fflush(stdin);
            switch(opcion2) {
                case 1:
                    printf("Dame el dato a insertar\n");
                    scanf("%d",&dato);
                    if(insertarDesordenado(dato)==true){
                        printf("Se inserto el elemento\n");
                    } else {
                        printf("No se inserto el elemento\n");
                    }
                    break;
                case 2:
                    printf("\nDame el elemento a eliminar\n");
                    scanf("%d", &dato);
                    fflush(stdin);
                    if (EliminaDesorden(dato) == true) {
                        printf("El elemento se elimino correctamente\n");
                    } else {
                        printf("El elemento no se elimino\n");
                    }
                    break;
                case 3:
                    imprimir();
                    break;
                case 4:
                    printf("\nDame el elemento a buscar\n");
                    scanf("%d", &dato2);
                    fflush(stdin);
                    printf("\nDame el elemento nuevo\n");
                    scanf("%d", &dato);
                    fflush(stdin);
                    if (ModificaDesordenado(dato2, dato) == true) {
                        printf("Se modifico el elemento\n");
                    } else {
                        printf("El elemento no se modifico\n");
                    }
                    break;
                case 5:
                    OrdenarDesordenado();
                    printf("Se ordeno la matriz correctamente\n");
                    break;
            }
        } while(opcion2!=0);
    }
    return 0;
}

bool EsVacia() {
    if (indij.i == 0 && indij.j == 0) {
        if (matriz[indij.i][indij.j] == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool insertarDesordenado(int d) {
    if (indij.i < m) {
        if (indij.j < n) {
            matriz[indij.i][indij.j] = d;
            indij.j++;
            return true;
        } else {
            indij.j = 0;
            indij.i++;
            insertarDesordenado(d);
        }

    } else {
        indij.i--;
        indij.j = n - 1;
        return false;
    }
}

Indij BuscaSec(int elemento) {
    Indij p;
    p.i = 0;
    p.j = 0;
    while (p.i < m) {
        while (p.j < n) {
            if (matriz[p.i][p.j] == elemento) {
                return p;
            } else {
                p.j++;
            }
        }
        p.j = 0;
        p.i++;
    }
    p.i = m + 1;
    p.j = n + 1;
    return p;
}

bool EliminaDesorden(int d) {
    Indij pos;
    int i, j;
    if (EsVacia() == false) {
        pos = BuscaSec(d);
        if (pos.i > m || pos.j > n) {
            return false;
        } else {
            i = pos.i;
            j = pos.j;
            while (i < m) {
                while (j < n) {
                    if (i < m - 1 && j == n - 1) {
                        matriz[i][j] = matriz[i + 1][0];
                    } else {
                        matriz[i][j] = matriz[i][j + 1];
                    }
                    j++;
                }
                i++;
                j = 0;
            }
            if (indij.j == 0) {
                indij.j = n - 1;
                indij.i--;
            } else {
                indij.j--;
            }
            return true;
        }
    } else {
        return false;
    }
}

bool ModificaDesordenado(int datob, int dato) {
    Indij pos;
    if (EsVacia() == false) {
        pos = BuscaSec(datob);
        if (pos.i > m || pos.j > n) {
            return false;
        } else {
            matriz[pos.i][pos.j] = dato;
            return true;
        }
    } else {
        return false;
    }
}

void OrdenarDesordenado() {
    int aux;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (matriz[i][j] < matriz[k][l]) {
                        aux = matriz[i][j];
                        matriz[i][j] = matriz[k][l];
                        matriz[k][l] = aux;
                    }
                }
            }
        }
    }
}

void imprimir() {
    printf("El array es: \n");
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

