
#include <string.h>
#include <malloc.h>
int max=0;
int *array=NULL;
int d=0, db=0, ind=0;
int Add(int d);//InsertarElemento
int Remove(int d);
bool IsFull();
bool IsEmpty();
int GetItem();
int Modify(int db, int d);
void Order();
int Search(int d);

//definicion de funciones
bool CrearArray(int m){
	array=(int *)malloc(m* sizeof(int));
	if(array!=NULL){
		for (int i=0;i<m;i++)
			array[i]=NULL;
	}
		return true;
}
	

bool IsFull(){
	if(ind>=max-1 && array[ind]!=0)
		return true;
		 else  
		return false;
	}
	
	
bool IsEmpty(){
			
	if (ind<=0 && array[ind]==0)		
		return true;
		  else
			return false; 
	}
	
	
int GetItem(){
	return array[ind];
	}

	
	
int Add(int d){  //retorna los valores de 0 no se insert? por que esta llena, 1 se insert?,  2 no se inserrt? porque es 0, 
	int pos;
	
	 if (IsEmpty() && d!=0){ //primer elemento positivos y negativos
		array[ind]=d;
		  return 1;
	 }
	 else if (IsFull())
		 return 0;
	 else if (d==0)
		return 2; 
	 else{
	  pos=Search(d);
		if(pos<0){
		  return 0;
		}
		else{
							
		if (array[pos]==d)
		  return 0;
		else{
	      for(int i=ind+1;i>=pos+1;i--){
			array[i]=array[i-1];
		  }
			ind++;
			array[pos]=d;
			return 1;}
		printf(" d= %d",d);
		printf(" db= %d",db);
		printf(" ind= %d",ind);
		}
	 }
					
 }
	
	
	
int Remove (int d){ //0 no se elimino es vacia, 1 se elimino, 2 elemento no existe
	int pos=0;
	if (IsEmpty())
	 return 0;
	else{
	if (array[ind]==d){
		array[ind]=NULL;
	if (ind == 0) ind= 0; else ind--;
	 return 1;
	}
	else{
	 pos=Search(d);
	if (pos==-1)
     return -1; // elemento no existe
	 else{
	  if (array[pos]==d){
		for (int i=pos;i<ind;i++)
		  array[i]=array[i+1];
		  array[ind]=0;
			  if (ind == 0) ind= 0; else ind--;
				  return 1;
	  }
	  else
	  return 2;
	  printf(" d= %d",d);
	  printf(" db= %d",db);
	  printf(" ind= %d",ind);
	 }
    }
   }
 }

	
	
int Search(int d){
	printf(" d= %d",d);
	printf(" db= %d",db);
	printf(" ind= %d",ind);
	int j=0;
	  if (IsEmpty())
		return  -1;
	  else{
	 							
		while ((j<=ind) && (d>array[j])) {
		  j=j+1;
		}
		  return j;     
								
	  }
 }
	
	
void Visualice() { 
	
	if (IsEmpty()){
	  printf("Array vacio\n");
    }
	else{
	  printf("\nArreglo Unidimensional\n");
		for (int i=0;i<=ind;i++){
		  printf("[%d] ",array[i]);
		}
	}
 }


