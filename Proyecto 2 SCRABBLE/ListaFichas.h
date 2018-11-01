#ifndef LISTAFICHAS_H
#define LISTAFICHAS_H
#include "NodoFichas.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
class ListaFichas
{
private:
	NodoFichas* primero;
	NodoFichas* actual;
public:
	ListaFichas();
	Fichas* getFichaDeLista(string);
	void insertarInicio(Fichas*);
	void insertarFinal(Fichas*);
	string obtenerLetras();
	int obtenerValorLetras();//suma los valores de cada ficha y lo retorna;
	Fichas* getFichasOrdenadas(int);
	bool eliminarInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	void eliminarFicha(string);
	NodoFichas* fichaAleatoria(int);
	~ListaFichas();
};

#endif // !LISTA_H