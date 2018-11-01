#include "NodoFichas.h"



NodoFichas::NodoFichas(Fichas* LETRA, NodoFichas* SGT)
{
	letra = LETRA;
	siguiente = SGT;
}

void NodoFichas::setLetra(Fichas * INFO)
{
	letra = INFO;
}

Fichas* NodoFichas::getLetra()
{
	return letra;
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
return letra->toString();
}


NodoFichas::~NodoFichas()
{
}
