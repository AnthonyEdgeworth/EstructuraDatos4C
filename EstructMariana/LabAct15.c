#include <stdlib.h>
#include <stdio.h>
#define INT_MAX 10
#define INT_MIN 0

struct Pila{
	int tope;
	int capacidad;
	int* arreglo;
};


struct Pila* crearPila(int capacidad){
	struct Pila* pila = (struct Pila*) malloc(sizeof(struct Pila)); 
	pila->capacidad = capacidad; 
	pila->tope = -1; 
	pila->arreglo = (int*)malloc(pila->capacidad*sizeof(int));
	return pila;
}
int POP(struct Pila* pila);
void PUSH(struct Pila* pila, int elemento);
	int estaVacia (struct Pila* pila){
		return pila->tope == -1;
	}
		
		int estaLlena(struct Pila* pila){
			return pila->tope == pila->capacidad-1;
		}
			int PEEK(struct Pila* pila){
				int val = POP(pila);
				PUSH(pila,val);
				return val;
			}
				
				
				void PUSH(struct Pila* pila, int elemento){
					if (estaLlena(pila))
						return;
					pila->arreglo[++pila->tope] = elemento;
				}
					void imprimir(struct Pila* pila){
						int i=0;
						for (i = pila->tope; i > -1; i--)
							printf("\nElementos de la pila:\n%i\n", pila->arreglo[i]);	
					}
						int POP(struct Pila* pila){
							if (estaVacia(pila))
								return INT_MIN;
							return pila->arreglo[pila->tope--];
						}	
							void EliminarRepetidos(struct Pila* pila){
								int i,k,j,tam;
								tam=6;
								int cont=0;
								for(i = 0; i < tam; i++){
									for(j = i+1; j < tam; j++)
									{
										if(pila->arreglo[i] == pila->arreglo[j]){
											k = j;
											cont++;
											while(k < tam)
											{
												pila->arreglo[k] = pila->arreglo[k+1];
												++k;
											}
											--tam;
											--j;
										}
									}
								}
								while(cont>0){
									POP(pila);
									--cont;
								}
							}
								
								int numElementos(struct Pila* pila){
									return pila->tope+1;
								}
									
									int main(int argc, char *argv[]) {
										struct Pila* temporal = crearPila(5);
										struct Pila* temporal2 = crearPila(5);
										struct Pila* pila = crearPila(5); 
										int opc;
										struct Pila* pila2 = crearPila(5);
										int n;
										int c;
										
										do {
											
											printf("1. Poner un elemento en la pila\n");
											printf("2. Quitar un elemento de la pila\n");
											printf("3. Mostrar los elementos de la pila \n");
											printf("4. Intercambiar los elementos de las pilas\n");
											printf("5. Eliminar elementos de la pila repetidos\n");
											printf("6. Salir\n");
											scanf("%d",&c);
											
											switch(c) {
											case 1:
												printf("\nQue pila quieres llenar 1 o 2:");
												scanf("%d",&opc);
												if(opc==1){
													printf("\nInserta elemento para la pila:");
													scanf("%d",&n);
													PUSH(pila,n);
													printf("La pila tiene %i elementos\n",numElementos(pila));
													if (estaLlena(pila))
														printf("La pila esta llena");
													break;
												}
												if(opc==2){
													printf("\nQue elemento quieres poner en la pila :");
													scanf("%d",&n);
													PUSH(pila2,n);
													printf("La pila tiene %d elementos\n",numElementos(pila2));
													if (estaLlena(pila2))
														printf("La pila esta llena");
													break;
												}
												break;
											case 2:
												printf("\nA que pila desea Eliminar el ultimo valor:");
												scanf("%d",&opc);
												if(opc==1){
													if (estaVacia(pila)){
														printf("La pila esta vacia");
													}else
																  POP(pila);
													break;
												}
												if(opc==2){
													if (estaVacia(pila)){
														printf("La pila esta vacia");
													}else
																  POP(pila2);
													break;
												}
												break;
											case 3: 
												printf("\nA Que pila quieres mostrar en la pantalla:");
												scanf("%d",&opc);
												if(opc==1){
													imprimir(pila);
													break;
												}
												if(opc==2){
													imprimir(pila2);
													break;
												}
												break;
											case 4:
												temporal=pila;
												temporal2= pila2;
												pila2=temporal;
												pila=temporal2;
												break;
											case 5:
												printf("\nA que pila quieres eliminar sus numeros repetidos:");
												scanf("%d",&opc);
												if(opc==1){
													EliminarRepetidos(pila);
												}
												if(opc==2){
													EliminarRepetidos(pila2);
												}
												break;
											default:
												break;
											}
										} while(c != 6 && c != EOF);
										free(temporal);
										free(temporal2);
										return 0;
										
									}