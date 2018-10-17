#ifndef LISTA_H
#define LISTA_H
#include"NodoDiccionario.h"
class Lista
{
private:
	Nodo* primero;
	Nodo* actual;
public:
	Lista();
	void insertarInicio(string*);
	bool eliminarInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	~Lista();
};

#endif // !LISTA_H