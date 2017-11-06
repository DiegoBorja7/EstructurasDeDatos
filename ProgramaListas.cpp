//Listas simples

#include<stdio.h>
#include<stdlib.h>

void membrete() 
{ 
    printf("\t _________________________________________________________\n"); 
    printf("\t|            <UNIVERSIDAD DE LAS FUERZAS ARMADAS>         |\n"); 
    printf("\t|                   ESTRUCTURA DE DATOS                   |\n"); 
    printf("\t|                                                         |\n"); 
    printf("\t| Ing. Fernando Solis                                     |\n"); 
    printf("\t| Integrante: Borja Diego                                 |\n"); 
    printf("\t|                                                         |\n"); 
    printf("\t| Tema: Lista Simple Enlazada                             |\n"); 
    printf("\t|_________________________________________________________|\n\n"); 
    //printf(" /* Programa para ingresar n NODOS */ \n\n"); 
} 

struct nuevalista{
  int dato;
  struct nuevalista *sig;
};

nuevalista *primero=NULL;
nuevalista *ultimo=NULL;

void agregar(nuevalista *novo){
	novo->sig=NULL;
		
	if(primero==NULL)
	{
		primero=novo;
		ultimo=novo;
	}
	else
	{
		ultimo->sig=novo;
		ultimo=novo;		
	}
}

int main(){
	membrete();
	/*int i,nod;
	printf("ingresar cantidad de nodos: ");
	scanf("%d",&nod);
	for(i=0;i<nod;i++)*/	
	//nuevalista *primerNum = (nuevalista*)malloc(sizeof(nuevalista));
	nuevalista (*primerNum)=new nuevalista();
	primerNum->	dato=7;
	
	nuevalista *segundoNum =(nuevalista*) malloc(sizeof(nuevalista));
	segundoNum->dato=10;
	
	nuevalista *i=primerNum;
	
	agregar(primerNum);
	agregar(segundoNum);
	
	while(i!= NULL)
	{
		printf("%d   ",i->dato);
		i=i->sig;
	}
	
	return 0;
}
