#include "ListaFichas.h"

ListaFichas::ListaFichas()
{
	primero = NULL;
	actual = NULL;
}

void ListaFichas::insertarInicio(Fichas *  LETRA)
{
	{
		actual = new NodoFichas(LETRA, NULL);
		if (primero == NULL)
		{
			primero = actual;

		}
		else
		{
			actual->setSiguiente(primero);
			primero = actual;
		}
	}

}

bool ListaFichas::eliminarInicio()
{
	if (primero == NULL)  // caso 1: la ListaFichasFichas esta vacia
	{
		return false;
	}
	else // caso 2: la ListaFichas no esta vacia
	{
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		return true;
	}
}

string ListaFichas::toString()
{
	stringstream s;
	actual = primero;
	while (actual != NULL)
	{
		s << actual->toString();
		actual = actual->getSiguiente();
	}
	return s.str();
}

int ListaFichas::cuentaNodos()
{
	actual = primero;
	int can = 0;

	while (actual != NULL)
	{
		can++;
		actual = actual->getSiguiente();
	}
	return can;
}

bool ListaFichas::listaVacia()
{
	return  (primero == NULL) ? true : false;
}

ListaFichas::~ListaFichas()
{
}
