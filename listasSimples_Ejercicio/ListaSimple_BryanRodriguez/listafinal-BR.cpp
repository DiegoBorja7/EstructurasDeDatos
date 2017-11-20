#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>


struct Nodo{
	int dato;
	Nodo *siguiente;
};

int contadorNodo=-1;
//ingreso de la lista
void ingresoListas(Nodo *&lista, int numero){
	Nodo *nuevo=new Nodo();
	nuevo->dato=numero;
	Nodo *aux1=lista;
	Nodo *aux2;
	while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->siguiente;
		contadorNodo++;
	}
	
	if(lista==aux1){
		lista=nuevo;
		nuevo->siguiente=aux1;
	}
	else{
		aux2->siguiente=nuevo;
		nuevo->siguiente=aux1;
		
	}
	printf("El numero %d ha sido ingresado.\n", numero);	
}
//imprimir el nodo
void mostrarLista(Nodo *lista){
	Nodo *guia=new Nodo();
	guia=lista;
	printf("\nLos elementos de la lista son: ");
	while(guia!=NULL){
		printf("%d ",guia->dato);
		guia=guia->siguiente;
	}
	//printf("NULL");
	delete guia;
}

void buscarNodo(Nodo *lista, int ubicacion){
	Nodo *guia=new Nodo();
	guia=lista;
	if(ubicacion>contadorNodo)
		printf("Elemento no existente");
	else{
		contadorNodo=0;
		while(ubicacion!=contadorNodo)
		{
			guia=guia->siguiente;
			contadorNodo++;
		}		
		if(ubicacion==contadorNodo)
			printf("ELEMENTO ENCONTRADO ES: %d",guia->dato);
	}

}
//funcion principal
int main(){
	Nodo *lista;
	int dato,ubi;
	lista=NULL;
	
	printf("Ingrese un numero: ");
	scanf("%d",&dato);
	ingresoListas(lista,dato);
	printf("Ingrese un numero: ");
	scanf("%d",&dato);
	ingresoListas(lista,dato);
	printf("Ingrese un numero: ");
	scanf("%d",&dato);
	ingresoListas(lista,dato);
	mostrarLista(lista);
	
	printf("\nIMPRESIONSUMA:%d\n",contadorNodo);
	//validar posicion entera positiva
	printf("Ingrese la ubicacion que desea buscar un posicion:");
	scanf("%d",&ubi);
	buscarNodo(lista,ubi);
	return 0;
}
