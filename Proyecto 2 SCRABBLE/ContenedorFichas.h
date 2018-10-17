#ifndef CONTENEDORFICHAS_H
#define CONTENEDORFICHAS_H
#include "Fichas.h"
class ContenedorFichas
{
private:
	Fichas **contenedor;

public:
	ContenedorFichas();
	bool agregarFicha(Fichas*);
	int contarFichas();
	string toString();
	~ContenedorFichas();
};

#endif // !CONTENEDORFICHAS_H