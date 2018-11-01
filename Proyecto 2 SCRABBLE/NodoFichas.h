#ifndef NODOFICHAS_H
#define NODOFICHAS_H
#include "Fichas.h"
class NodoFichas
{
private:
	Fichas* letra;
	NodoFichas* siguiente;

public:
	NodoFichas(Fichas*, NodoFichas*);
	void setLetra(Fichas*);
	Fichas* getLetra();
	void setSiguiente(NodoFichas*);
	NodoFichas* getSiguiente();
	string toString();
	~NodoFichas();
};

#endif // !NODOFICHAS_H