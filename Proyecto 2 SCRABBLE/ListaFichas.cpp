#include "ListaFichas.h"

ListaFichas::ListaFichas()
{
	primero = NULL;
	actual = NULL;
}

Fichas * ListaFichas::getFichaDeLista(string LETRA)
{
	actual = primero;
	if (primero != NULL)
	{
		while (actual->getSiguiente() != NULL)
		{
			if (actual->getLetra()->getLetra() == LETRA)
			{
				return actual->getLetra();
			}
			else
				actual = actual->getSiguiente();

		}
		actual->getSiguiente();
		if (actual->getLetra()->getLetra() == LETRA)
		{
			return actual->getLetra();
		}
		else return NULL;
	
	}
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
			cadena =  cadena + aux1;
		}
		aux1 = actual->getLetra()->getLetra();
		cadena = cadena + aux1;
		return cadena;
	}
	else return "OOPS LISTA VACIA";
}

int ListaFichas::obtenerValorLetras()
{
	int valor=0, aux=0;
	actual = primero;
	if (primero != NULL)
	{
		while (actual->getSiguiente() != NULL)
		{
			aux = actual->getLetra()->getValor();
			actual = actual->getSiguiente();
			valor= valor + aux;
		}
		aux = actual->getLetra()->getValor();
		valor = valor + aux;
		return valor;
	}
	else
		return 0;
}

Fichas * ListaFichas::getFichasOrdenadas(int limite)
{
	while(primero!=NULL){
	actual = primero;
	if (limite == 0) 
	{
		return actual->getLetra();
	}

	for (int i = 0; i < limite; i++) 
	{
		actual = actual->getSiguiente();
	}
	return actual->getLetra();
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

void ListaFichas::eliminarFicha(string letra)
{
	if (primero != NULL)
	{
		actual = primero;
		NodoFichas* auxBorrar;
		NodoFichas* anterior = actual;
		auxBorrar = actual;
		while (auxBorrar != NULL && auxBorrar->getLetra()->getLetra() != letra) {
			anterior = actual;
			auxBorrar = auxBorrar->getSiguiente();
		}
		if (auxBorrar == NULL) {
			cout << "El elemento no existe" << endl;
		}
		else
			if (anterior == NULL) {
				actual = actual->getSiguiente();
				delete auxBorrar;
			}
			else
			{
				actual->setSiguiente(auxBorrar->getSiguiente());
				delete auxBorrar;
			}
	}
}

NodoFichas * ListaFichas::fichaAleatoria(int num)
{
	actual = primero;
	if (primero != NULL) 
	{
		for (int i = 0; i < num; i++) 
		{
			actual = actual->getSiguiente();
		}
		if (actual->getLetra()->getCantidadDisponible() != 0) 
		{
			actual->getLetra()->utilizarFicha();
			return actual;
		}
		else {


			srand(time(NULL));
			int num1 = 1 + rand() % (29 - 1);
			fichaAleatoria(num1);
		}
		
	}
}

ListaFichas::~ListaFichas()
{
	while (primero != NULL) { // voy eliminando siempre el primero
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
