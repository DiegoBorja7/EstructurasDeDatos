///se desea insertar elementos enteros a una lista

#include<conio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

/* Encabezado*/
void encabezado()
{
    printf("\t _________________________________________________________\n");
    printf("\t|            <UNIVERSIDAD DE LAS FUERZAS ARMADAS>         |\n");
    printf("\t|                   ESTRUCTURA DE DATOS                   |\n");
    printf("\t|                                                         |\n");
    printf("\t| Ing. Fernando Solis                                     |\n");
    printf("\t| Integrante: Borja Diego                                 |\n");
    printf("\t|                                                         |\n");
    printf("\t| Tema: Lista Simple                                      |\n");
    printf("\t|_________________________________________________________|\n\n");
    //printf(" /* Programa para ingresar n NODOS */ \n\n");
}
/*Declaracion de estructura*/
struct Nodo{
  int datoEntero;
  struct Nodo *siguienteDir;
};
typedef struct Nodo *ListaSimple;

/*Declaracion de Prototipo*/
char *ingresar(char *); ///retorno una cadena
void insertarDato(ListaSimple *,int);
void imprimirDatos(ListaSimple *);

/*Desarollo de Prototipo*/
char *ingresar(char *msg){
    char dato [5];
    char c;
    int i=0;
    printf("%s",msg);
    ///validar solo numeros
    while((c=getch())!=13) ///13==ascii ENTER
    {
        if(c>='0'&&c<='9')      ///entender
        {
            printf("%c",c);
            dato[i++]=c;
        }
        dato[i]='\0';
    }
    printf("***%s",dato);
    return dato;
}
void insertarDato(ListaSimple *Nuevo,int datoNuevo) ///realizar el recorrido bien hecho
{
     ListaSimple* ultimo=new ListaSimple();
     ultimo=NULL;
     if(Nuevo==NULL)
     {
         Nuevo=ultimo;
         Nuevo->datoEntero=datoNuevo;
         ultimo->siguienteDir=NULL;
     }
     else
     {
        ultimo->siguienteDir=Nuevo;

     }
}
int main()
{
    int datoEntero;
    ListaSimple lista;
    lista=NULL;
    datoEntero=atoi(ingresar("Ingrese el valor entero positvo: "));
    printf("%d",datoEntero);
    return 0;
}

