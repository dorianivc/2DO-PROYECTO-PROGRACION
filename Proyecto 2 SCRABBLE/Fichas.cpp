#include "Fichas.h"



Fichas::Fichas(string LETRAS, string VALOR,string CANTIDAD)
{
	letra = LETRAS;
	valor = atoi(VALOR.c_str());
	totalFichas = atoi(CANTIDAD.c_str());
	cantidadDisponible = totalFichas;

}

string Fichas::toString()
{
	stringstream p;
	p << "Letra: " << letra << endl;
	p << "Valor: " << valor << endl;
	p << "Cantidad de Fichas: " << cantidadDisponible << endl;
	return p.str();
}


Fichas::~Fichas()
{
}
