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
| Tema: Personal Library                                                |
|                                                                       |
| Fecha de Creacion: 02/12/2017      Fecha de Modificacion: 02/12/2017  |
|_______________________________________________________________________| */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <string>
#include <time.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define TECLA_ENTER 13

int ingresoNumerico(char *msg)  //Validacion solo de numeros (Bloqueo de Teclado), mandando un mensaje de parametro.
{
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
	
    return atoi(dato);
}

void gotoxy(int x, int y) //referencia: https://www.youtube.com/watch?v=evmIH4nyTgE
{ 
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);	
}

void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}

void imprimirTXT(char txt[])
{
	int x=0,y=0;
    char caracter[200];
    system("color 0E");
    FILE *INICIO;
    INICIO=fopen(txt,"r");

    while (!feof(INICIO))
    {
        fgets(caracter,130,INICIO);
        gotoxy(x,y);
		puts(caracter);
        y++;
    }
}

int obtenerDia()
{
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
     char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    
    return tlocal->tm_mday;
}
