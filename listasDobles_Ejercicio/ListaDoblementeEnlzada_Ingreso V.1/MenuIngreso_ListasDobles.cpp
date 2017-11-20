#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13

/*Libreria externas*/
void gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

char *ingresar(char *msg){ //Validacion solo de numeros.
    char dato [1000];
    char c;
    int i=0;
    printf("%s",msg);
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

/*Enzabezado
 _______________________________________________________________________
|                   <UNIVERSIDAD DE LAS FUERZAS ARMADAS>                |
|                               <ESPE>                                  |
|                        ESTRUCTURA DE DATOS                            |
|                                                                       |
|                                                                       |
| Autor: Borja Diego                                                    |
  Docente: Ing. Fernando Solis                                          |
|                                                                       |
| Tema: Lista Dobles                                                    |
|                                                                       |
| Fecha de Creacion: 14/11/2017      Fecha de Modificacion: 19/11/2017  |
|_______________________________________________________________________| */

void encabezadoMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11); //letras en amarillo
	printf("\n\t\t\t  MENU\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //letras en blanco
	printf("\t\t 1) Crear Lista Doble.\n");
	printf("\t\t 2) Insertar al inicio.\n");
	printf("\t\t 3) Insertar al final.\n");
	printf("\t\t 4) Insertar al medio.\n");
	printf("\t\t 5) Imprimir.\n");
	printf("\t\t 6) Salir.\n");
}

/*Declaracion de estructura*/
struct Nodo{
  long int datoEntero;
  struct Nodo *anteriorDireccion;
  struct Nodo *siguienteDireccion;
};
typedef struct Nodo *ListaDoble;

/*Declaracion de Funciones*/
void crearNodo(ListaDoble *);
void insertarAlPrincipio(ListaDoble *);
void insertarAlFinal(ListaDoble *);
void insertarAlMedio(ListaDoble *);
boolean MenuOpciones(ListaDoble *,int );
int Seleccion();
void impresion(ListaDoble *);
int contadorNodo=0;

/*Desarollo de Funciones*/
void impresion(ListaDoble &Lista)
{
	ListaDoble aux=new Nodo();
	aux=Lista;
	system("cls");
	if(aux == NULL)
    	printf("LISTA VACIA . . .\n\n");
    else
    {
	    printf("\t\t- Impresion - \n\nLISTA.\n\n");
		while(aux != NULL)
		{
	        printf("%d, ",aux->datoEntero);
	        aux=aux->siguienteDireccion;
	    }
		printf("\b\b. \n\n");
	}
}

void insertarAlFinal(ListaDoble &Lista)
{
	long int dato;
	ListaDoble Nuevo=new Nodo();
	ListaDoble Actual=new Nodo();
	Actual=Lista;
	if(contadorNodo!=0)
	{
		dato=atoi(ingresar("Ingrese el valor: "));
		while(Actual->siguienteDireccion!=NULL)
		{
			Actual=Actual->	siguienteDireccion;
		}
        Nuevo->	datoEntero=dato;
        Nuevo->	siguienteDireccion=NULL;
        Actual->siguienteDireccion=Nuevo;
        Nuevo->	anteriorDireccion=Actual;
		contadorNodo++;
		printf("\n\nA continuacion se le va a desplegar el dato ingresado\nPresione cualquier tecla para continuar. . .");
	    getch();
	    impresion(Lista);
		
	}
	else
		printf("Cree primero un nodo !\n\n");
}
void insertarAlPrincipio(ListaDoble &Lista)
{
	long int dato;
	ListaDoble Nuevo=new Nodo();
	ListaDoble Actual=new Nodo();
	if(contadorNodo!=0)
	{
		dato=atoi(ingresar("Ingrese el valor: "));
		if(Actual!=NULL)
		{
			Nuevo->	datoEntero=dato;
			Nuevo->	siguienteDireccion=Lista;
			Nuevo->anteriorDireccion=NULL;
			Actual->anteriorDireccion=Nuevo;
		}
		Lista=Nuevo;
		contadorNodo++;
		printf("\n\nA continuacion se le va a desplegar el dato ingresado\nPresione cualquier tecla para continuar. . .");
	    getch();
	    impresion(Lista);
	}
	else
		printf("Cree primero un nodo !\n\n");
}
void insertarAlMedio(ListaDoble &Lista)
{
	long int dato,posicion;
	int contador=2;
	ListaDoble Nuevo=new Nodo();
	ListaDoble Actual=new Nodo();
	Actual=Lista;
	if(contadorNodo!=0)
	{
		do
		{
			posicion=atoi(ingresar("Ingrese la posicion: "));
			if(posicion>contadorNodo||posicion<1)
				printf("\nPosicion incorrecta !!\n\n");
		}while(posicion>contadorNodo||posicion<1);
		printf("\n");
		if(posicion==1)
        {
            insertarAlPrincipio(Lista);
        }
        else 
			if(posicion==contadorNodo)
            {
                insertarAlFinal(Lista);
            }
        	else 
				if(Actual!=NULL)
	        	{
		        	while(Actual!=NULL&&contador!=posicion)
		        	{
		        		Actual=Actual->siguienteDireccion;
		        		contador++;
					}			
					dato=atoi(ingresar("Ingrese el valor: "));
					Nuevo->datoEntero=dato;
					Nuevo->siguienteDireccion=Actual->siguienteDireccion;
					Actual->siguienteDireccion=Nuevo;
					Nuevo->anteriorDireccion=Actual;
					Nuevo->siguienteDireccion->anteriorDireccion=Nuevo;
					contadorNodo++;
			    	printf("\n\nA continuacion se le va a desplegar el dato ingresado\nPresione cualquier tecla para continuar. . .");
			    	getch();
			    	impresion(Lista); 
				}
	}
	else
		printf("Cree primero un nodo !\n\n");
}
void crearNodo(ListaDoble &Lista)
{
	long int dato;
	ListaDoble Nuevo=new Nodo();
	if(contadorNodo==0)
	{
		dato=atoi(ingresar("Ingrese el valor: "));
		Nuevo->datoEntero=dato;
		Nuevo->anteriorDireccion=NULL;
		Nuevo->siguienteDireccion=NULL;
		Lista=Nuevo;
	    contadorNodo++;
	    printf("\n\nA continuacion se le va a desplegar el dato ingresado\nPresione cualquier tecla para continuar. . .");
	    getch();
	    impresion(Lista); 
	    
	}
	else
	{
		printf("Solo para creacion del primer elemento, vuelva al menu principal\n\n");
	}

}
int Seleccion()
{
	bool repite=true;
	int seleccionar=1,tecla;
	do
	{
		char *opciones[]={" 1) Crear Lista Doble.\n"," 2) Insertar al inicio.\n"," 3) Insertar al final.\n"," 4) Insertar al medio.\n"," 5) Imprimir.\n"," 6) Salir.\n"};
		gotoxy(0,0);
		encabezadoMenu();
		gotoxy(16,1+seleccionar); //17
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

boolean MenuOpciones(ListaDoble &Lista,int Opcion)
{
	boolean salir=true;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("cls");
	switch(Opcion)
	{
		case 1:
		{
			crearNodo(Lista);
			break;
		}

	    case 2:
		{
			insertarAlPrincipio(Lista);
			break;
		}
		case 3:
		{
			insertarAlFinal(Lista);
			break;
		}
		case 4:
		{
			insertarAlMedio(Lista);
			break;
		}
		case 5:
		{
			impresion(Lista);
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
		printf("Presione cualquier tecla para volver al menu principal . . .");
		getch();
	}

	return salir;
}

int main()
{
	int opcion;
	boolean op;
	ListaDoble nuevoNodo=NULL;
	do
	{
		system("cls");
    	opcion=Seleccion();
    	op=MenuOpciones(nuevoNodo,opcion);
	}while(op);
	return 0;
}
