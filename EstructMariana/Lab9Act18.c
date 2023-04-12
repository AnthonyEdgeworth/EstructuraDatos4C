//estructura de datos
//mariana estefania barcenas rodriguez
// 10/05/2022

#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct nodoA{
    int info;
    struct nodoA *izq;
    struct nodoA *der;
}tiponodo;
typedef tiponodo *NodoA;
NodoA arbol;
NodoA nuevoNodo(NodoA,int,NodoA );
NodoA cargarNodos(int,NodoA);
//RECORRIDOS DE LOS ARBOLES
void inorden(NodoA );
void preorden (NodoA );
void postorden(NodoA );
int compara(int,int);
NodoA Busca(NodoA,int);
void InsertarDato(int);
NodoA elimina(NodoA,int);

int main(){
    int edad=-1,mayor,edades;
	NodoA temp;

    printf("\n\n Cuantas edades quieres introducir en tu arbol ?");
	scanf("%d",&edades);
    
   
    for(int i=0;i<edades;i++)
	{
	printf("Dame las edades: \n");
	scanf(" %d",&edad);
	if (edad!=0)
	arbol=cargarNodos(edad,arbol);

    if(edad>mayor)
		{
			mayor=edad;
		}   
    }


	printf("\n arbol en inorden\n");
	inorden(arbol);
	printf("\n arbol en preorden\n");
	preorden(arbol);
	printf("\n arbol en postorden\n");
	postorden(arbol);
    printf("\nla edad mayor entre todos es:%d",mayor);

	printf("\n Dame un elemento a buscar");
	scanf("%d",&edad);

	temp=Busca(arbol,edad);

	if (temp!=NULL)
	printf("\n La raiz del arbol es %d ",temp->info);
	else
	printf("\n Elemento no encontrado"); 
  
	return 0;
}

NodoA nuevoNodo(NodoA izq,int inf,NodoA der){
	NodoA q;
	q=(NodoA)malloc(sizeof(tiponodo));
	if (!q){
	printf("\n Error al crear el nuevo nodo");
	exit(0);
	}
	q->info=inf;
	q->izq=izq;
	q->der=der;
	return q;
}

NodoA cargarNodos(int dato, NodoA ini){
	if (ini==NULL){
	ini=nuevoNodo(NULL,dato, NULL); 	}
	else if (compara(dato, ini->info)==-1){ //va al lado izquierdo
	ini->izq=cargarNodos(dato,ini->izq); 
    }
	else if (compara(dato,ini->info)==1){//va al lado derecho
	ini->der=cargarNodos(dato, ini->der); 
    	}
	return ini;
}//fin funciÃ³n

int compara(int a, int b){
	if (a<b)
	return -1;
	if (a>b)
	return 1;
	if (a==b)
	return 0;
	return NULL;
}

void inorden(NodoA raiz){
	if (raiz!=NULL){
	inorden(raiz->izq);
	printf(" %d", raiz->info);
	inorden(raiz->der); 
    }
}

void postorden(NodoA raiz){
	if (raiz!=NULL){
	postorden(raiz->izq);
	postorden(raiz->der);
	printf(" %d", raiz->info);
    }
}

void preorden(NodoA raiz){
	if(raiz!=NULL){
	printf(" %d", raiz->info);
	preorden(raiz->izq);
 	preorden(raiz->der);
    }
}

NodoA Busca(NodoA raiz, int datoB){
	int bandera=0;
    if (raiz!=NULL){
	    if (datoB==raiz->info){
	    bandera=1;
        }
        printf("\n El elemento buscado se encontro y es %d ",raiz->info);
	    return raiz;
	}
	else{
	    if (compara(datoB, raiz->info)==-1){
	    raiz->izq=Busca(raiz->izq,datoB);
	    }
	    else if (compara(datoB, raiz->info)==1) {
	    raiz->der=Busca(raiz->der,datoB);
	}
    }

}



