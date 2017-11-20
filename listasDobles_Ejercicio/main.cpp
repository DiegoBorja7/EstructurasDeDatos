#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
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
|                 <UNIVERSIDAD DE LAS FUERZAS ARMADAS>                  |
|                                <ESPE>                                 |
|                          ESTRUCTURA DE DATOS                          |
|                                                                       |
|                                                                       |
| Autores:																|
|		   Borja Diego                                                  |
|		   Lasso Dany													|
|		   Rodriguez Bryan												|
|																		|
| Docente: Ing. Fernando Solis                                          |
|                                                                       |
| Tema: Lista Dobles                                                    |
|                                                                       |
| Fecha de Creacion: 14/11/2017      Fecha de Modificacion: 19/11/2017  |
|_______________________________________________________________________| */
void encabezadoMenu()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),29);
	printf("\t\t\tLISTAS DOBLES\t\t\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //letras en amarillo
	printf("\n\n\t\t\t    MENU\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //letras en blanco
	printf("\t\t   1) Insertar Numero.\n");
	printf("\t\t   2) Buscar Numero.\n");
	printf("\t\t   3) Modificar Numero.\n");
	printf("\t\t   4) Eliminar Numero.\n");
	printf("\t\t   5) Imprimir Listado.\n");
	printf("\t\t   6) Salir.\n");

}

void encabezadoIngreso()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //letras en amarillo
	printf("\n\t\t\t  Ingresar\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //letras en blanco
	printf("\t\t 1) Insertar al inicio.\n");
	printf("\t\t 2) Insertar al medio.\n");
	printf("\t\t 3) Insertar al final.\n");
	printf("\t\t 4) Regresar Menu Principal.\n");

}

void encabezadoEliminar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //letras en amarillo
	printf("\n\t\t\t  Eliminar\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //letras en blanco
	printf("\t\t 1) Eliminar al inicio.\n");
	printf("\t\t 2) Eliminar al medio.\n");
	printf("\t\t 3) Eliminar al final.\n");
	printf("\t\t 4) Regresar Menu Principal.\n");

}

int seleccionMenu()
{
	bool repite=true;
	int seleccionar=1,tecla;
	do
	{
		char *opciones[6]={"1) Insertar Numero.\n","2) Buscar Numero.\n","3) Modificar Numero.\n","4) Eliminar Numero.\n","5) Imprimir Listado.\n","6) Salir.\n"};
		gotoxy(0,0);
		encabezadoMenu();
		gotoxy(19,2+seleccionar); //17
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

int seleccionIngreso()
{
	bool repite=true;
	int seleccionar=1,tecla;
	do
	{
		char *opciones[4]={"1) Insertar al inicio.\n","2) Insertar al medio.\n","3) Insertar al final.\n","4) Regresar Menu Principal.\n"};
		gotoxy(0,0);
		encabezadoIngreso();
		gotoxy(17,1+seleccionar); //17
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
					seleccionar=4;
			break;
			case TECLA_ABAJO:
				seleccionar++;
				if(seleccionar==5)
					seleccionar=1;
			break;
			case TECLA_ENTER:
				repite=false;
			break;
		}
	}while(repite);

	return seleccionar;
}

int seleccionEliminar()
{
	bool repite=true;
	int seleccionar=1,tecla;
	do
	{
		char *opciones[4]={"1) Eliminar al inicio.\n","2) Eliminar al medio.\n","3) Eliminar al final.\n","4) Regresar Menu Principal.\n"};
		gotoxy(0,0);
		encabezadoEliminar();
		gotoxy(17,1+seleccionar); //17
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
					seleccionar=4;
			break;
			case TECLA_ABAJO:
				seleccionar++;
				if(seleccionar==5)
					seleccionar=1;
			break;
			case TECLA_ENTER:
				repite=false;
			break;
		}
	}while(repite);

	return seleccionar;
}

/*Declaracion de estructura*/
struct Nodo{
  int datoEntero;
  struct Nodo *anteriorDireccion;
  struct Nodo *siguienteDireccion;
};

typedef struct Nodo *ListaDoble;
int contadorNodo=0;

/*Declaracion de Funciones*/
bool menuPrincipal(ListaDoble *,int );
bool menuIngreso(ListaDoble *,int );
bool menuEliminar(ListaDoble *,int );
void ingresar(ListaDoble *);
void insertarAlPrincipio(ListaDoble *);
void insertarAlMedio(ListaDoble *);
void insertarAlFinal(ListaDoble *);
void buscar(ListaDoble *);
void modificar(ListaDoble *);
void eliminar(ListaDoble *);
void eliminarAlPrincipio(ListaDoble *);
void eliminarAlMedio(ListaDoble *);
void eliminarAlFinal(ListaDoble *);
void impresion(ListaDoble *);

/*Desarollo de Funciones*/
void impresion(ListaDoble &Lista)
{
	ListaDoble aux=new Nodo();
	aux=Lista;
	system("cls");
	if(aux == NULL)
    	printf("No existe elementos en la lista.\n\n");
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

void eliminarAlFinal(ListaDoble &Lista)
{
	int cont=1;
	ListaDoble Nuevo=new Nodo();
	Nuevo=Lista;
	if(Nuevo == NULL)
		printf("No existe elementos en la lista.\n\n");
	else
	{
		if(contadorNodo==1)
		{
			delete Lista;
			Lista=NULL;
			printf("Eliminacion exitosa !");
		}
		else
		{
			while(cont<contadorNodo)
			{
				Nuevo=Nuevo->siguienteDireccion;
				cont++;		        
	    	}
	    	Nuevo=Nuevo->anteriorDireccion;
			Nuevo->siguienteDireccion=NULL;
			printf("Eliminacion exitosa !");			
		}
		printf("\n\nA continuacion se le va a desplegar la lista para verificar su eliminacion.\nPresione cualquier tecla para continuar. . .");
	    getch();
	    impresion(Lista);
	    contadorNodo--;
	}
}

void eliminarAlPrincipio(ListaDoble &Lista)
{
	ListaDoble Nuevo=new Nodo();
	Nuevo=Lista;
	if(Nuevo == NULL)
		printf("No existe elementos en la lista.\n\n");
	else
	{
		if(contadorNodo==1)
		{
			delete Lista;
			Lista=NULL;
			printf("Eliminacion exitosa !");
		}
		else
		{
			Nuevo=Nuevo->siguienteDireccion;
			Nuevo->anteriorDireccion=NULL;
			printf("Eliminacion exitosa !");
		}
		Lista=Nuevo;
		printf("\n\nA continuacion se le va a desplegar la lista para verificar su eliminacion.\nPresione cualquier tecla para continuar. . .");
	    getch();
	    impresion(Lista);
	    contadorNodo--;
	}

}

void eliminarAlMedio(ListaDoble &Lista)
{
	long int dato,cont=0;
	ListaDoble Nuevo=new Nodo();
	Nuevo=Lista;
	if(Nuevo == NULL)
		printf("No existe elementos en la lista.\n\n");
	else
	{
		dato=atoi(ingresar("Ingrese el numero que desea eliminar: "));
		while(Nuevo!=NULL)
		{
			if(dato==Nuevo->datoEntero)
			{
				cont++;
				
			}
			Nuevo=Nuevo->siguienteDireccion;
		}
		if(cont==0)
			printf("\nNo se han encontrado elementos similares\n\n");
		else
		{
			if(contadorNodo==1)
			{
				delete Lista;
				Lista=NULL;
				printf("\nEliminacion exitosa !");
				printf("\n\nA continuacion se le va a desplegar la lista para verificar su eliminacion.\nPresione cualquier tecla para continuar. . .");
				getch();
				impresion(Lista);
				contadorNodo--;
			}
			else
			{
				if(cont==1)
				{
					printf("\n");
					eliminarAlPrincipio(Lista);
				}				
				else
				{
					if(cont==contadorNodo)
					{
						printf("\n");
						eliminarAlFinal(Lista);
					}
					else
					{
						Nuevo=Lista;
						while(Nuevo!=NULL)
						{
							if(dato==Nuevo->datoEntero)
							{
								Nuevo=Nuevo->anteriorDireccion;
								Nuevo->siguienteDireccion=Nuevo->siguienteDireccion->siguienteDireccion;
								printf("\nEliminacion exitosa !");
								
				    			break;
							}
							Nuevo=Nuevo->siguienteDireccion;
						}
						printf("\n\nA continuacion se le va a desplegar la lista para verificar su eliminacion.\nPresione cualquier tecla para continuar. . .");
						getch();
						impresion(Lista);
						contadorNodo--;	
					}
				}
			}
			
		}
	}
}

bool menuEliminar(ListaDoble &Lista,int Opcion)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("cls");
	boolean salir=true;
	switch(Opcion)
	{
		case 1:
		{
			eliminarAlPrincipio(Lista);
			break;
		}
	    case 2:
		{
			eliminarAlMedio(Lista);
			break;
		}
		case 3:
		{
			eliminarAlFinal(Lista);
			break;
		}
		case 4:
		{
			salir=false;
			break;
		}
		default:
		{
			printf("OPCION INCORRECTA !!");
		}
	}
	if(Opcion!=4)
	{
		printf("Presione cualquier tecla para volver al menu eliminar . . .");
		getch();
	}
	return salir;
}

void eliminar(ListaDoble &Lista)
{
	do
	{
		system("cls");
	}while(menuEliminar(Lista,seleccionEliminar()));
}

void modificar(ListaDoble &Lista)
{
	int buscar,editar,cont=0;
	ListaDoble guia=new Nodo();
	guia=Lista;
	if(guia == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("MODIFICAR.\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		buscar=atoi(ingresar("Ingrese el numero que desea modificar: "));
		while(guia!=NULL)
		{
			if(buscar==guia->datoEntero)
			{
				printf("\nElemento encontrado ! (%d)\n",buscar);
				editar=atoi(ingresar("Ingrese el nuevo numero: "));
				guia->datoEntero=editar;
				printf("\nCambio Exitoso");
				cont++;
				printf("\n\nA continuacion se le va a desplegar la lista para verificar su modificacion\nPresione cualquier tecla para continuar. . .");
    			getch();
    			impresion(Lista);
    			break;
			}
			guia=guia->siguienteDireccion;
		}
		if(cont==0)
			printf("\nNo se han encontrado elementos similares\n\n");

	}
}

void buscar(ListaDoble &Lista)
{
	int buscar,contadorInterno;
	ListaDoble guia=new Nodo();
	guia=Lista;
	if(guia == NULL)
    	printf("No existe elementos en la lista.\n\n");
    else
    {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("BUSQUEDA.\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("Ingrese el numero de la posicion a buscar: ");
	    scanf("%d",&buscar);
		if(buscar>contadorNodo||buscar<1)
			printf("Elemento no existente ! \n\n");
		else
		{
			contadorInterno=1;
			while(buscar!=contadorInterno)
			{
				guia=guia->siguienteDireccion;
				contadorInterno++;
			}
			if(buscar==contadorInterno)
			{
				printf("El numero en la ubicacion [%d] es : %d",buscar,guia->datoEntero);
				printf("\n\nA continuacion se le va a desplegar la lista para verificar su busqueda\nPresione cualquier tecla para continuar. . .");
    			getch();
    			impresion(Lista);
			}
				
		}
	}
}

void insertarAlPrincipio(ListaDoble &Lista)
{
	long int dato;
	ListaDoble Nuevo=new Nodo();
	ListaDoble Actual=new Nodo();
	dato=atoi(ingresar("Ingrese el valor: "));
	if(Actual!=NULL)
	{
		Nuevo->datoEntero=dato;
		Nuevo->siguienteDireccion=Lista;
		Nuevo->anteriorDireccion=NULL;
		Actual->anteriorDireccion=Nuevo;
	}
	else
	{
		Nuevo->datoEntero=dato;
		Nuevo->anteriorDireccion=NULL;
		Nuevo->siguienteDireccion=NULL;
	}
	Lista=Nuevo;
	contadorNodo++;
	printf("\n\nA continuacion se le va a desplegar el dato ingresado\nPresione cualquier tecla para continuar. . .");
    getch();
    impresion(Lista);
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
		printf("Ingrese un primer elemento !\n\n");
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
		printf("Ingrese un primer elemento !\n\n");
}

bool menuIngreso(ListaDoble &Lista,int Opcion)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("cls");
	boolean salir=true;
	switch(Opcion)
	{
		case 1:
		{
			insertarAlPrincipio(Lista);
			break;
		}
	    case 2:
		{
			insertarAlMedio(Lista);
			break;
		}
		case 3:
		{
			insertarAlFinal(Lista);
			break;
		}
		case 4:
		{
			salir=false;
			break;
		}
		default:
		{
			printf("OPCION INCORRECTA !!");
		}
	}
	if(Opcion!=4)
	{
		printf("Presione cualquier tecla para volver al menu ingreso . . .");
		getch();
	}
	return salir;
}

void ingresar(ListaDoble &Lista)
{
	do
	{
		system("cls");
	}while(menuIngreso(Lista,seleccionIngreso()));
		
}

bool menuPrincipal(ListaDoble &Lista,int Opcion)
{
	boolean salir=true;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("cls");
	switch(Opcion)
	{
		case 1:
		{
			ingresar(Lista);
			break;
		}

	    case 2:
		{
			buscar(Lista);
			break;
		}
		case 3:
		{
			modificar(Lista);
			break;
		}
		case 4:
		{
			eliminar(Lista);
			break;
		}
		case 5:
		{
			impresion(Lista); 
			break;
		}
		case 6:
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
			printf("Adios :)");
			salir=false;
			break;
		}
		default:
		{
			printf("OPCION INCORRECTA !!");
		}
	}
	if(Opcion!=6&&Opcion!=1&&Opcion!=4)
	{
		printf("Presione cualquier tecla para volver al menu principal . . .");
		getch();
	}

	return salir;
}

int main()
{
	ListaDoble nuevoNodo=NULL;
	do
	{
		system("cls");
	}while(menuPrincipal(nuevoNodo,seleccionMenu()));
    return 0;
}
