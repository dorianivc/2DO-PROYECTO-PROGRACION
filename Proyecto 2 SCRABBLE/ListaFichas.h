#ifndef LISTAFICHAS_H
#define LISTAFICHAS_H
#include "NodoFichas.h"
class ListaFichas
{
private:
	NodoFichas* primero;
	NodoFichas* actual;
public:
	ListaFichas();
	void insertarInicio(Fichas*);
	bool eliminarInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	~ListaFichas();
};

#endif // !LISTA_H