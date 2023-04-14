/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int info;
    struct Nodo* liga;
} tipoNodo;

typedef struct Lista {
    tipoNodo* inicio;
    tipoNodo* fin;
    int t;
} tipoLista;

typedef tipoNodo* nodo;
typedef tipoLista listaE;

listaE Lista;

nodo NuevoNodo(int, nodo);
listaE CrearFinal(listaE, int);
bool EsVacia(listaE);
void Recorrer(listaE);
listaE CrearInicio(listaE, int);
nodo BuscarX(listaE, int, char);
listaE InsertarAntesX(listaE, int, int);
listaE InsertarDespuesX(listaE, int, int);
listaE EliminarX(listaE, int);
int tsize(listaE);
listaE EliminarAntesX(listaE, int);
listaE EliminarDespuesX(listaE, int);
listaE EliminarInicio(listaE);
listaE EliminarFinal(listaE);
listaE OrdenarLista(listaE);
listaE ModificarElemX(listaE, int, int);
listaE EliminarDuplicados(listaE);

nodo NuevoNodo(int elem, nodo liganueva) {
    nodo n;
    n = (nodo)malloc(sizeof(tipoNodo));
    if (!n) {
        printf("Error al crear nodo nuevo");
        return NULL;
    } else {
        n->info = elem;
        n->liga = liganueva;
        return n;
    }
}

bool EsVacia(listaE lst) {
    if (lst.inicio != NULL)
        return false;
    else
        return true;
}

void Recorrer(listaE lst) {
    nodo t;
    if (EsVacia(lst)) {
        printf("La lista esta vacia\n");
    } else {
        t = lst.inicio;
        printf("\nEstado Actual del TDA Lista Enlazada Sencilla\n");
        while (t != NULL) {
            printf("%d | ", t->info);
            t = t->liga;
        }
    }
}

listaE CrearFinal(listaE lst, int Elem) {
    if (EsVacia(lst)) {
        lst.inicio = NuevoNodo(Elem, NULL);
        lst.fin = lst.inicio;
        lst.t++;
    } else {
        lst.fin->liga = NuevoNodo(Elem, NULL);
        lst.fin = lst.fin->liga;
        lst.t++;
    }
    Recorrer(lst);
    return lst;
}

listaE CrearInicio(listaE lst, int Elem) {
    nodo t;
    if (EsVacia(lst)) {
        lst.inicio = NuevoNodo(Elem, NULL);
        lst.fin = lst.inicio;
        lst.t++;
    } else {
        t = NuevoNodo(Elem, NULL);
        t->liga = lst.inicio;
        lst.inicio = t;
        lst.t++;
    }
    Recorrer(lst);
    return lst;
}

nodo BuscarX(listaE lista, int ElemX, char Modo) {
    nodo t = lista.inicio;
    nodo q = t;
    while (t != NULL) {
        if (t->info == ElemX) {
            if (Modo == 'A')
                return q;
            else
                return t;
        } else {
            q = t;
            t = t->liga;
        }
    }
    return NULL;
}


listaE InsertarAntesX(listaE lst, int Elem, int ElemX) {
    nodo q, t;
    q = BuscarX(lst, ElemX, 'A');
    if (q == NULL) {
        printf("El elemento no esta en la lista");
        return lst;
    }
    t = NuevoNodo(Elem, q->liga);
    q->liga = t;
    lst.t++;
    Recorrer(lst);
    return lst;
}

listaE InsertarDespuesX(listaE lst, int Elem, int ElemX) {
    nodo q, t;
    q = BuscarX(lst, ElemX, 'P');
    if (q == NULL) {
        printf("El elemento no esta en la lista");
        return lst;
    }
    t = NuevoNodo(Elem, q->liga);
    q->liga = t;
    if (lst.fin == q) {
        lst.fin = t;
    }
    lst.t++;
    Recorrer(lst);
    return lst;
}

listaE EliminarX(listaE lst, int ElemX) {
    nodo q, t;
    q = BuscarX(lst, ElemX, 'A');
    if (q == NULL) {
        printf("El elemento no esta en la lista");
        return lst;
    }
    t = q->liga;
    q->liga = t->liga;
    if (lst.fin == t) {
        lst.fin = q;
    }
    free(t);
    lst.t--;
    Recorrer(lst);
    return lst;
}

int tsize(listaE lst) {
    return lst.t;
}

listaE EliminarAntesX(listaE lst, int ElemX) {
    nodo q, t;
    if (lst.inicio->info == ElemX) {
        printf("El elemento se encuentra al inicio de la lista, no se puede eliminar\n");
        return lst;
    } else {
        q = BuscarX(lst, ElemX, 'A');
        if (q == NULL || q == lst.inicio) {
            printf("El elemento no tiene un anterior en la lista\n");
            return lst;
        }
        t = q->liga;
        q->liga = t->liga;
        free(t);
        lst.t--;
        Recorrer(lst);
        return lst;
    }
}

listaE EliminarDespuesX(listaE lst, int ElemX) {
    nodo q, t;
    if (lst.fin->info == ElemX) {
        printf("El elemento se encuentra al final de la lista, no se puede eliminar\n");
        return lst;
    } else {
        q = BuscarX(lst, ElemX, 'P');
        if (q == NULL || q == lst.fin) {
            printf("El elemento no tiene un siguiente en la lista\n");
            return lst;
        }
        t = q->liga;
        q->liga = t->liga;
        if (lst.fin == t) {
            lst.fin = q;
        }
        free(t);
        lst.t--;
        Recorrer(lst);
        return lst;
    }
}

listaE EliminarInicio(listaE lst) {
    nodo t;
    if (EsVacia(lst)) {
        printf("La lista esta vacia\n");
    } else {
        t = lst.inicio;
        lst.inicio = t->liga;
        free(t);
        lst.t--;
    }
    Recorrer(lst);
    return lst;
}

listaE EliminarFinal(listaE lst) {
    nodo t;
    if (EsVacia(lst)) {
        printf("La lista esta vacia\n");
    } else if (lst.inicio->liga == NULL) {
        t = lst.inicio;
        lst.inicio = NULL;
        lst.fin = NULL;
        free(t);
        lst.t--;
    } else {
        nodo q;
        t = lst.inicio;
        while (t->liga != NULL) {
            q = t;
            t = t->liga;
        }
        q->liga = NULL;
        lst.fin = q;
        free(t);
        lst.t--;
    }
    Recorrer(lst);
    return lst;
}

listaE OrdenarLista(listaE lst) {
    nodo i, j;
    int aux;
    for (i = lst.inicio; i != NULL; i = i->liga) {
        for (j = i->liga; j != NULL; j = j->liga) {
            if (i->info > j->info) {
                aux = i->info;
                i->info = j->info;
                j->info = aux;
            }
        }
    }
    Recorrer(lst);
    return lst;
}

listaE ModificarElemX(listaE lst, int ElemX, int NuevoElem) {
    nodo t;
    t = BuscarX(lst, ElemX, 'B');
    if (t != NULL) {
        t->info = NuevoElem;
        Recorrer(lst);
    } else {
        printf("El elemento %d no se encuentra en la lista\n", ElemX);
    }
    return lst;
}

listaE EliminarDuplicados(listaE lst) {
    nodo i, j, q;
    for (i = lst.inicio; i != NULL; i = i->liga) {
        for (j = i->liga, q = i; j != NULL; j = j->liga) {
            if (i->info == j->info) {
                q->liga = j->liga;
                free(j);
                j = q;
                lst.t--;
            } else {
                q = j;
            }
        }
    }
    Recorrer(lst);
    return lst;
}

int main(int argc, char *argv[])
{
    int elem;
    int elemX;
    int opcion;
    while (opcion != 14)
    {
        system("cls");
        printf("1.Insertar al inicio\n");
        printf("2.Insertar al final\n");
        printf("3.Insertar antes de x\n");
        printf("4.Insertar despues de x\n");
        printf("5.Eliminar al inicio\n");
        printf("6.Eliminar al final\n");
        printf("7.Eliminar el elemento x\n");
        printf("8.Eliminar antes de x\n");
        printf("9.Eliminar despues de x\n");
        printf("10.Ordenar (con metodo burbuja)\n");
        printf("11.Mostrar la lista enlazada\n");
        printf("12.Modificar algun dato\n");
        printf("13.Eliminar Duplicados\n");
        printf("14.Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Dame el elemento a insertar por el inicio: ");
            scanf("%d", &elem);
            Lista = CrearInicio(Lista, elem);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            printf("Dame el elemento a insertar por el final: ");
            scanf("%d", &elem);
            Lista = CrearFinal(Lista, elem);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            BuscarX(Lista, elemX, 'A');
            printf("Dame el elemento a insertar antes de %d: ", elemX);
            scanf("%d", &elem);
            Lista = InsertarAntesX(Lista, elem, elemX);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            BuscarX(Lista, elemX, 'D');
            printf("Dame el elemento a insertar despues de %d: ", elemX);
            scanf("%d", &elem);
            Lista = InsertarDespuesX(Lista, elem, elemX);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            Lista = EliminarInicio(Lista);
            printf("\n\n");
            system("pause");
            break;
        case 6:
            Lista = EliminarFinal(Lista);
            printf("\n\n");
            system("pause");
            break;
        case 7:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            Lista = EliminarX(Lista, elemX);
            printf("\n\n");
            system("pause");
            break;
        case 8:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            BuscarX(Lista, elemX, 'A');
            Lista = EliminarAntesX(Lista, elemX);
            printf("\n\n");
            system("pause");
            break;
        case 9:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            BuscarX(Lista, elemX, 'D');
            Lista = EliminarDespuesX(Lista, elemX);
            printf("\n\n");
            system("pause");
            break;
        case 10:
            Lista = OrdenarLista(Lista);
            printf("\n\n");
            system("pause");
            break;
        case 11:
            Recorrer(Lista);
            printf("\n\n");
            system("pause");
            break;
        case 12:
            printf("Ingrese el numero X: ");
            scanf("%d", &elemX);
            printf("Dame el nuevo elemento que lo va a sustituir: ");
            scanf("%d", &elem);
            Lista = ModificarElemX(Lista, elemX, elem);
            printf("\n\n");
            system("pause");
            break;
        case 13:
            printf("Elimina elementos duplicados");
            Lista = EliminarDuplicados(Lista);
            Recorrer(Lista);
            printf("\n\n");
            system("pause");
            break;
        case 14:
            break;
        }
    }
    printf("\nHasta luego\n");
    system("pause");
    return 0;
}
