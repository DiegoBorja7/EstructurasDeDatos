#include <stdio.h>
#include <stdlib.h>

struct book{
	char titulo [50];
	char autor [50];
	char isbn [50];
};

struct Node{
	struct book libro;
	struct Node* siguiente;
};

struct list{
	struct Node* cabeza;
	int cantidad;
};

struct Node* CrearNodo (struct book* libro)
{
	struct Node* nodo= (struct Node*)malloc(sizeof (nodo));
	strncpy (nodo->libro.titulo, libro->titulo,50);
	strncpy (nodo->libro.autor, libro->autor,50);
	strncpy (nodo->libro.isbn, libro->isbn,50);
	nodo->siguiente=NULL;
	return nodo;
}

void DestruirNodo (struct Nodo* nodo)
{
	free (nodo);
}

void InsertarPrincipio(struct list* lista, struct book* libro )
{
	struct Node* nodo = CrearNodo(libro);
	nodo->siguiente=lista->cabeza;
	lista->cabeza= nodo;
	lista->cantidad++;
}
void InsertarFinal(struct list* lista, struct book* libro )
{
	struct Node* nodo = CrearNodo(libro);
	if(lista->cabeza==NULL)
		lista->cabeza=nodo;
	else
	{
		struct Node* puntero = lista->cabeza;
		while (puntero->siguiente)
				puntero=puntero->siguiente;
		puntero->siguiente=nodo;
	}
	lista->cantidad++;
}

void InsertarMedio(int n, struct list* lista, struct book* libro )
{
	int posicion=0;
	struct Node* nodo = CrearNodo(libro);
	if(lista->cabeza==NULL)
		lista->cabeza=nodo;
	else
	{
		struct Node* puntero = lista->cabeza;
		while (posicion < n && puntero->siguiente)
		{
				puntero=puntero->siguiente;
				posicion++;
		}

		nodo->siguiente=puntero->siguiente;
		puntero->siguiente=nodo;
	}
	lista->cantidad++;
}

struct book* Obtener (int n, struct list* lista)
{
	int posicion=0;
	if (lista->	cabeza==NULL)
		return NULL;
	else
	{
		struct Node* puntero = lista->cabeza;
		while (posicion < n && puntero->siguiente)
		{
				puntero=puntero->siguiente;
				posicion++;
		}
		if(posicion != NULL)
			return NULL;
		else
			return &puntero->libro;
	}
}
int contar(struct list* lista)
{
	return lista->cantidad;
}

void eliminarPrincipio(struct list* lista)
{
    if(lista->cabeza)
    {
        struct Node* eliminado = lista->cabeza;
        lista->cabeza=lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->cantidad--;
    }
}
void eliminarUltimo(struct list* lista)
{
    if(lista->cabeza)
    {
        if (lista->cabeza->siguiente)
        {
            struct Node* puntero = lista->cabeza;
            while(puntero->siguiente->siguiente)
                puntero=puntero->siguiente;

            struct Node* eliminado = puntero->siguiente;
            puntero->siguiente=NULL;
            DestruirNodo(eliminado);
            lista->cantidad--;
        }
        else
        {
            struct Node* eliminado = lista->cabeza;
            lista->cabeza=NULL;
            DestruirNodo(eliminado);
            lista->cantidad--;
        }
    }
}
void eliminarElemento(int n,struct list* lista)
{
    int posicion=0;
    if(lista->cabeza)
    {
        if(n==0)
        {
            struct Node* eliminado = lista->cabeza;
            lista->cabeza=lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->cantidad--;
        }
        else
        {
            if(n<lista->cantidad)
            {
                struct Node* puntero = lista->cabeza;
                while(posicion<(n-1))
                {
                    puntero=puntero->siguiente;
                    posicion++;
                }
                struct Node* eliminado = puntero->siguiente;
                puntero->siguiente=eliminado->siguiente;
                DestruirNodo(eliminado);
                lista->cantidad--;
            }
        }

    }
}
void main()
{
    printf("Listas Enlazadas");
}
