#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int p;
    int r;
    int c;
} Indrcp;

int cntelem = 0, m = 0, n = 0, pl = 0;
int ***tridi;
Indrcp indrcp;
int dato = 0;

bool Crea(int m, int n, int p) {
    tridi = (int ***) malloc(p * sizeof(int **));

    if (tridi == NULL) {
        return false;
    }

    for (int k = 0; k < p; k++) {
        tridi[k] = (int **) malloc(m * sizeof(int *));
        if (tridi[k] == NULL) {
            return false;
        }
        for (int i = 0; i < m; i++) {
            tridi[k][i] = (int *) malloc(n * sizeof(int));
            if (tridi[k][i] == NULL) {
                return false;
            }
            for (int j = 0; j < n; j++) {
                tridi[k][i][j] = 0; /* Inicializar a cero */
            }
        }
    }

m = m;
n = n;
pl = p;
    return true;
}

bool EsVacia() {
    return cntelem == 0;
}

bool EsLlena() {
    return cntelem >= (pl * m * n);
}

bool InsertarDesordenado(int d) {
    if (EsVacia()) {
        indrcp.r = 0;
        indrcp.c = 0;
        indrcp.p = 0;
    } else if (!EsLlena()) {
        if (indrcp.c >= n - 1 && indrcp.r <= m - 1) {
            indrcp.r++;
            indrcp.c = 0;
        }
        if (indrcp.r > m - 1) {
            indrcp.p++;
            indrcp.r = 0;
            indrcp.c = 0;
        }
        tridi[indrcp.p][indrcp.r][indrcp.c] = d;
    } else {
        return false;
    }

    cntelem++;
    return true;
}


