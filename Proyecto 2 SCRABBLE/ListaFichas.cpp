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

void ListaFichas::insertarFinal(Fichas * LETRA)
{
	actual = primero;
	if (primero == NULL)
	{
		primero = new NodoFichas(LETRA, NULL);
	}
	else
		actual = primero;
	while (actual->getSiguiente() != NULL) 
	{
		actual = actual->getSiguiente();
	}
	actual->setSiguiente(new NodoFichas(LETRA, NULL));
}

string ListaFichas::obtenerLetras()
{
	string cadena, aux1;
	actual = primero;
	if (primero != NULL) 
	{
		while (actual->getSiguiente() != NULL) 
		{
			aux1 =actual->getLetra()->getLetra();
			actual = actual->getSiguiente();
			cadena = cadena + aux1;
		}
		aux1 = actual->getLetra()->getLetra();
		cadena = cadena + aux1;
		return cadena;
	}
	else return "OOPS LISTA VACIA";
}

int ListaFichas::obtenerValorLetras()
{
	int valor=0, aux;
	actual = primero;
	if (primero != NULL)
	{
		while (actual->getSiguiente() != NULL)
		{
			aux = actual->getLetra()->getValor();
			actual = actual->getSiguiente();
			valor = +aux;
		}
		aux = actual->getLetra()->getValor();
		valor = +aux;
		return valor;
	}
	else
		return 0;
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
