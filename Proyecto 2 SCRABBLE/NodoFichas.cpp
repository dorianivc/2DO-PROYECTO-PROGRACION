#include "NodoFichas.h"



NodoFichas::NodoFichas(Fichas* LETRA, NodoFichas* SGT)
{
	Letra = LETRA;
	siguiente = SGT;
}

void NodoFichas::setLetra(Fichas * INFO)
{
	Letra = INFO;
}

Fichas* NodoFichas::getLetra()
{
	return Letra;
}

void NodoFichas::setSiguiente(NodoFichas * SGT)
{
	siguiente = SGT;
}

NodoFichas * NodoFichas::getSiguiente()
{
	return siguiente;
}

string NodoFichas::toString()
{
return Letra->toString();
}


NodoFichas::~NodoFichas()
{
}
