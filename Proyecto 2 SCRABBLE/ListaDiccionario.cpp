#include "ListaDiccionario.h"



Lista::Lista()
{
	primero = NULL;
	actual = NULL;
}



void Lista::insertarInicio(string * palabra)
{
	actual = new Nodo(palabra, NULL);
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

bool Lista::eliminarInicio()
{
	if (primero == NULL)  // caso 1: la lista esta vacia
	{
		return false;
	}
	else // caso 2: la lista no esta vacia
	{
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		return true;
	}
}
bool Lista::getNodoSegunPalabra(string  PALABRA)
{
	if (primero != NULL)
	{
		actual = primero;
		while (actual->getSiguiente() != NULL)
		{
			if (actual->getInfo() == &PALABRA)
			{
				return true;
			}
			else
				actual = actual->getSiguiente();
		}

		if (actual->getInfo() == &PALABRA)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

string Lista::toString()
{
	stringstream s;
	actual = primero;
	while (actual != NULL)
	{
		s << actual->toStringNodo();
		actual = actual->getSiguiente();
	}
	return s.str();
}

int Lista::cuentaNodos()
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

bool Lista::listaVacia()
{
	return  (primero == NULL) ? true : false;
}



Lista::~Lista()
{
	while (primero != NULL) { // voy eliminando siempre el primero
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
