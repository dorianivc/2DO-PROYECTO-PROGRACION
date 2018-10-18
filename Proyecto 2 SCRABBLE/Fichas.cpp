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

string Fichas::getLetra()
{
	return letra;
}

void Fichas::setLetra(string LETRA)
{
	letra = LETRA;
}

int Fichas::getValor()
{
	return valor;
}

void Fichas::utilizarFicha()
{
	totalFichas = totalFichas - 1;
}


Fichas::~Fichas()
{
}
