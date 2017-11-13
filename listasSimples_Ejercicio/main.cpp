#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include <time.h>
#define TECLA_ARRIBA 72 // NUMERO ASCII DE ARRIBA,ABAJO,ENTER
#define TECLA_ABAJO 80
#define TECLA_ENTER 13

/*Libreria externa*/
void gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

/* Encabezado*/
void encabezado()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),29);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242);
    printf(" _________________________________________________________ \n");
    printf("|            <UNIVERSIDAD DE LAS FUERZAS ARMADAS>         |\n");
    printf("|                   ESTRUCTURA DE DATOS                   |\n");
    printf("|                                                         |\n");
    printf("| Ing. Fernando Solis                                     |\n");
    printf("| Integrante: Borja Diego                                 |\n");
    printf("|                                                         |\n");
    printf("| Tema: Lista Simple                                      |\n");
    printf("|_________________________________________________________|\n");

}
void menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //letras en amarillo
	printf("\n\n\t\t\tMENU\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //letras en blanco
	printf("\t\t 1) Insertar Numero.\n");
	printf("\t\t 2) Buscar Numero.\n");
	printf("\t\t 3) Modificar Numero.\n");
	printf("\t\t 4) Eliminar Numero.\n");
	printf("\t\t 5) Imprimir Listado.\n");
	printf("\t\t 6) Salir.\n");
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
void buscarNodo(ListaSimple *);
void modificarNodo(ListaSimple *);
void eliminarNodo(ListaSimple *);
void imprimirDatos(ListaSimple *);
int Seleccion();
void MenuOpciones(ListaSimple *,int );
int contadorNodo=-1;

/*Desarollo de Prototipo*/
char *ingresar(char *msg){
    char dato [1000];
    char c;
    int i=0;
    printf("%s",msg);
    ///validar solo numeros
    do
    {
    	dato[0]='\0';
		while((c=getch())!= TECLA_ENTER)
		{
		    if(c>='0'&& c<='9'&& c!=' ')  /// validar que no ingrese vacio
		    {
		        printf("%c",c);
		        dato[i++]=c;
		    }
			if(c==8)	///VALIDAR BIEN EL BACKSPACE
			{
				printf("\b");
				printf(" ");
				dato[i--]=' ';
			}
		    dato[i]='\0';
		}
		if(dato[0]==' ')
			printf("Vuelva a ingresar un numero entero !\n\n");
	}while(dato[0]=='\0');
    return dato;
}
void insertarDato(ListaSimple &Nuevo,int datoNuevo) ///realizar el recorrido bien hecho
{
    ListaSimple aux=new Nodo();
    if(Nuevo==NULL)
	{
		aux->datoEntero = datoNuevo;
		aux->siguienteDir=NULL;
		
	}else
	{
		aux->datoEntero = datoNuevo;
		aux->siguienteDir =Nuevo;
	}
    Nuevo=aux;
    contadorNodo++;
    printf("\n(%d)\tNODO INGRESADO CORRECTAMENTE !!\n",Nuevo->datoEntero);
    
}
void imprimirDatos(ListaSimple &Lista) //&Lista manda la direccion de toda la lista
{
	ListaSimple aux=new Nodo();
	aux=Lista;

    if(aux == NULL)
    	printf("LISTA VACIA . . .\n\n");
    else
    {
	    printf("LISTA . . .\n\n");
		while(aux != NULL)
		{
	        printf("%d, ",aux->datoEntero);
	        aux=aux->siguienteDir;
	    }
		printf("\b\b \n\n");
	}

}
void buscarNodo(ListaSimple &lista){
	int buscar,contadorInterno;
	ListaSimple guia=new Nodo();
	guia=lista;
	if(guia == NULL)
    	printf("LISTA VACIA . . .\n\n");
    else
    {
		printf("BUSQUEDA . . .\n\n");
		printf("Ingrese el numero de la posicion a buscar: ");
	    scanf("%d",&buscar);
		if(buscar>contadorNodo)
			printf("Elemento no existente\n\n");
		else
		{
			contadorInterno=0;
			while(buscar!=contadorInterno)
			{
				guia=guia->siguienteDir;
				contadorInterno++;
			}
			if(buscar==contadorInterno)
				printf("El numero en la ubicacion %d es : %d\n\n",buscar,guia->datoEntero);
		}
	}

}
void modificarNodo(ListaSimple &lista)
{
	int buscar,editar,cont=0;
	ListaSimple guia=new Nodo();
	guia=lista;
	if(guia == NULL)
    	printf("LISTA VACIA . . .\n\n");
    else
    {
    	printf("MODIFICAR . . .\n\n");
		printf("Ingrese el numero que desea modificar: ");
		scanf("%d",&buscar);
		while(guia!=NULL)
		{
			if(buscar==guia->datoEntero)
			{
				printf("Elemento encontrado ! (%d)\n",buscar);
				printf("Ingrese el nuevo numero: ");
				scanf("%d",&editar);
				guia->datoEntero=editar;
				printf("Cambio Exitoso\n\n");
				cont++;
			}
			guia=guia->siguienteDir;
		}
		if(cont==0)
			printf("No se han encontrado elementos similares\n\n");

	}
}
void eliminarNodo(ListaSimple &lista)
{
	if(lista == NULL)
    	printf("LISTA VACIA . . .\n\n");
    else
    {
    	printf("ELIMINAR . . .\n\n");
    	lista=lista->siguienteDir;
		printf ("Usted ha eliminado el ultimo elemento");
		printf("\nEliminacion Exitosa !\n\n");
	}
}
boolean MenuOpciones(ListaSimple &Lista,int Opcion)
{
	boolean salir=true;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("cls");
	switch(Opcion)
	{
		case 1:
		{


			long int datoEnteroIngresado=0;
    		char opcion;
			do
		    {
				datoEnteroIngresado=atoi(ingresar("Ingrese un valor entero positivo: "));
			    insertarDato(Lista,datoEnteroIngresado);
			    printf("Desea volver a ingresar un numero Yes o No (Y/N) ");
			    opcion=getch();
			    while(((opcion!='Y')&&(opcion!='y'))&&((opcion!='N')&&(opcion!='n')))
			    {
			         printf("\nOpcion incorrecta !!\n");
			         fflush(stdin);
			         printf("Ingrese correctamente la opcion Yes o No (Y/N) ");
			         opcion=getch();
			    }
				printf("\n\n");
		    }while((opcion=='Y')||(opcion=='y'));
			break;
		}

	    case 2:
		{
			buscarNodo(Lista);
			break;
		}
		case 3:
		{
			modificarNodo(Lista);
			break;
		}
		case 4:
		{
			eliminarNodo(Lista);
			break;
		}
		case 5:
		{
			imprimirDatos(Lista);
			break;
		}
		case 6:
		{
			printf("Adios :)");
			salir=false;
			break;
		}
		default:
		{
			printf("OPCION INCORRECTA !!");
		}
	}
	if(Opcion!=6)
	{
		printf("Presione cualquier tecla para volver al menu principal. . .");
		getch();
	}

	return salir;
}
int Seleccion()
{
	bool repite=true;
	int seleccionar=1,tecla;
	do
	{
		char *opciones[6]={"1) Insertar Numero.\n","2) Buscar Numero.\n","3) Modificar Numero.\n","4) Eliminar Numero.\n","5) Imprimir Listado.\n","6) Salir.\n"};
		gotoxy(0,0);
		encabezado();
		menu();
		gotoxy(17,11+seleccionar); //17
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
		//printf("%c %s",175,opciones[seleccionar-1]); //impresion con asterisco
		printf("%s",opciones[seleccionar-1]);
		do
		{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!= TECLA_ENTER );

		switch(tecla)
		{
			case TECLA_ARRIBA:
				seleccionar--;
				if(seleccionar==0)
					seleccionar=6;
			break;
			case TECLA_ABAJO:
				seleccionar++;
				if(seleccionar==7)
					seleccionar=1;
			break;
			case TECLA_ENTER:
				repite=false;
			break;
		}
	}while(repite);

	return seleccionar;
}
int main()
{
	int opcion;
	boolean op;
	ListaSimple nuevoNodo=NULL;
	do
	{
		system("cls");
    	opcion=Seleccion();
    	op=MenuOpciones(nuevoNodo,opcion);
	}while(op);
	
    return 0;
}

