//estructura de datos
//mariana estefania barcenas rodriguez
// 01/03/2022

#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "PilasList.h"

typedef struct libro{
	char titulo[30];
	char nserie[30];
}book;

typedef struct Nodos{
	struct libro  info;
	struct Nodos *liga;
}tiponodo;

typedef struct lista{
	struct Nodos *inicio;
	struct Nodos *fin;
	int t;
}tipolista;

typedef tiponodo *nodo;
typedef tipolista listaE;
typedef book libro;
listaE Lista;


nodo NuevoNodo(int,nodo);
listaE CrearFinal(listaE,int);//VA PA LA PILA
bool esVacia(listaE);
void Recorrer(listaE);//VA PA LA PILA
listaE EliminarFinal(listaE);//VA PA LA PILA





	bool esVacia(listaE lst){
		if (lst.inicio!=NULL)
			return false;
		else
            return true;
	}

void recorrer(listaE lst){
	nodo t;
	if(esVacia(lst)){
		printf("La lista esta vacia\n");
	}
	else{
		t=lst.inicio;
		printf("\nEstado Actual del TDA Lista Enlazada Sencilla\n");
		while(t!=NULL){
			printf("\n %s, serie:%s ",t->info.titulo,t->info.nserie);
			t=t->liga;
		}
	}
}
nodo nuevoNodo(libro elem,nodo liganueva){
	nodo n;
	n=(nodo)malloc (sizeof(tiponodo));
	if(!n){
		printf("error al crear nodo \n");
	return NULL;
    }else{
		n->info=elem;
		n->liga=liganueva;
		return n;
	}
}
listaE crearFinal(listaE lst, libro elem){
	if(esVacia(lst)){
		lst.inicio=nuevoNodo(elem,NULL);
		lst.fin=lst.inicio;
		lst.t++;
	}else {
		lst.fin->liga=nuevoNodo(elem,NULL);
		lst.fin=lst.fin->liga;
		lst.t++;
	}
	recorrer(lst);
    return lst;
}

listaE EliminarFinal(listaE lst)
{
	nodo aux=lst.inicio;
	if (esVacia(lst))
		printf("Es vacia");
	else
    {
		if (lst.inicio==lst.fin)
        { 
			lst.inicio=lst.fin=NULL;
			lst.t--;
			free(lst.inicio);
			free(lst.fin);
		}
        else
        {
			while(aux->liga!=lst.fin)
				aux=aux->liga;
			lst.fin=aux;
			lst.fin->liga=NULL;
        	aux=aux->liga;
			lst.t--;
			free(aux);
        }
	}

    return lst;
}

int main()
{
    char nom,elem;
    char serie;
	int opcion;
    libro bk;
    while(opcion != 14)
    {
		system("cls");
		printf("1.Insertar \n");		
		printf("6.Eliminar \n");
		printf("11.Mostrar la lista enlazada\n");
		printf("14.Salir\n");
		scanf("%d",&opcion);
		switch(opcion)
        {
		    case 1:
			printf("Dame el nombre del libro: ");
			scanf("%s",&bk.titulo);
            fflush(stdin);
            printf("Dame la serie del libro: ");
			scanf("%s",&bk.nserie);
			Lista = crearFinal(Lista,bk);
			printf("\n\n");
			system("pause");
			break;

		    case 6:
			Lista = EliminarFinal(Lista);
			printf("\n\n");
			system("pause");
			break;

		    case 11:
			recorrer(Lista);
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
	
