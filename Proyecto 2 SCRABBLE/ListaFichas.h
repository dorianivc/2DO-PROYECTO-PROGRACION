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
	void insertarFinal(Fichas*);
	string obtenerLetras();
	int obtenerValorLetras();//suma los valores de cada ficha y lo retorna;
	bool eliminarInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	NodoFichas* fichaAleatoria(int);
	~ListaFichas();
};

#endif // !LISTA_H