
//estructura de datos
//mariana estefania barcenas rodriguez
// 08/04/2022
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef struct nodo{
	int dato;
	struct nodo *siguiente;
}NODO;
NODO* crearNodo(int dato);
int Insertarinicio(NODO**c,int dato);
int Insertarfinal(NODO**c,int dato);
int EstaVacia(NODO *c);
int ExisteElemento(NODO *c,int dato);
NODO* elementoduplicado(NODO *c,int elemento);
void Mostrarlista(NODO *c);

NODO* crearNodo(int dato){
	NODO *nuevo=NULL;
	nuevo=(NODO*)malloc(sizeof(NODO));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
	}
	return nuevo;
}
	int Insertarinicio(NODO**c,int dato){
		NODO* nuevo=NULL;
		nuevo=crearNodo(dato);
		if(nuevo!=NULL){
			nuevo->siguiente=*c;
			*c=nuevo;
			return 1;
		}
		return 0;
	}
		int Insertarfinal(NODO**c,int dato){
			NODO* nuevo=NULL,*aux=*c;
			nuevo=crearNodo(dato);
			if(nuevo!=NULL){
				while(aux->siguiente!=NULL){
					aux=aux->siguiente;
				}
				aux->siguiente=nuevo;
				return 1;
				
			}
			return 0;
			
		}	
			
			int EstaVacia(NODO *c){
				if(c==NULL)
					return 1;
				else
					return 0;
			}
				int ExisteElemento(NODO *c,int dato){
					NODO *aux=c;
					while(aux!=NULL){
						if(aux->dato==dato)
							return 1;
						aux=aux->siguiente;
					}
					return 0;
				}
					void Mostrarlista(NODO *c){
						NODO *aux=c;
						while(aux!=NULL){
							printf("%d->",aux->dato);
							aux=aux->siguiente;
						}
					}
						
						NODO* elementoduplicado(NODO *c,int elemento){
							NODO*aEliminar;
							NODO* aux=c;
							while(aux!=NULL){
								if(c->dato==elemento){
									aEliminar=c;
									c=c->siguiente;
									aux=aux->siguiente;
									free(aEliminar);
								}else{
									if(aux->siguiente!=NULL && aux->siguiente->dato==elemento){
										aEliminar=aux->siguiente;
										aux->siguiente=aux->siguiente->siguiente;
										free( aEliminar);
									}else{
										aux=aux->siguiente;
									}
								}
							}
							return c;
						}
							int main(int argc, char *argv[]) {
								NODO *LISTA=NULL;
								printf("Se crea la lista con los datos ya elegidos\n");
								Insertarinicio(&LISTA,10);
								Insertarinicio(&LISTA,90);
								Insertarfinal(&LISTA,9);
								Insertarfinal(&LISTA,9);
								Insertarfinal(&LISTA,9);
								Insertarfinal(&LISTA,7);
								printf("Se muestra la lista\n");
								Mostrarlista(LISTA);
								printf("\nSe elige un dato duplicado es el \n");
								LISTA=elementoduplicado(LISTA,9);
								printf("\n");
								printf("Se elimino el dato duplicado de la lista\n");
								Mostrarlista(LISTA);
							}
							
							
