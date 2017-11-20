/* encabezado*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

/*declaración de estructura*/
struct Nodo{
	int datoEntero;
	struct Nodo *siguinteDir;
};
typedef struct Nodo *ListaSimple;

/*Declaracion de prototipos*/
char *ingresar(char *);
void insertarDato(ListaSimple *,int);
void imprimirDatos(ListaSimple *);

/*desarrollo de prototipos*/
char *ingresar(char *msg){
	char dato[5];
	char c;
	int i=0;
	printf("%s",msg);
	while((c=getch())!=13){
		if(c>='0'&&c<='9'){
			printf("%c",c);	
			dato[i++]=c;	
		}
		dato[i]='\0';
	}
	return dato;	
}

void insertarDato(ListaSimple &Nuevo,int datoInt)
{
	ListaSimple aux=new Nodo();
	if(Nuevo==NULL){
		aux->datoEntero = datoInt;
		aux->siguinteDir=NULL;
		
	}else{
		aux->datoEntero = datoInt;
		aux->siguinteDir =Nuevo;
	}
	Nuevo=aux;
}

void imprimirDatos(ListaSimple &lista)
{
	ListaSimple aux=new Nodo();
	aux = lista;
	while(aux != NULL)
	{
		printf("%d -> ",aux->datoEntero);
		system("pause");
		aux = aux->siguinteDir;
	}
}
	
int main(int argc, char** argv) {
	ListaSimple lista;
	lista=NULL;
	int datoEntero;
	int opc;
	do{
		datoEntero=atoi(ingresar("Ingrese el valor entero positivo: "));
		printf("\nValor ingresado es : %d",datoEntero);
		insertarDato(lista,datoEntero);
		printf("Desea ingresar otro valor\n1 Para si \n0 Para no\n");
		scanf("%d",&opc);
		printf("\n");
	}while(opc!=0);
	imprimirDatos(lista);
	
	return 0;
}

