#include "NodoDiccionario.h"



Nodo::Nodo(string* palabra, Nodo* siguiente)
{
	info = palabra;
	this->siguiente = siguiente;
}

void Nodo::setInfo(string * Reemplazo)
{
	info = Reemplazo;
}

string* Nodo::getInfo()
{
	return info;
}

void Nodo::setSiguiente(Nodo * SIGUIENTE)
{
	siguiente = SIGUIENTE;
}

Nodo * Nodo::getSiguiente()
{
	return siguiente;
}

string Nodo::toStringNodo()
{
	stringstream p;
	p << info << endl;
	return p.str();
}


Nodo::~Nodo()
{
}
