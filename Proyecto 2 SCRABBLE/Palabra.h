#ifndef PALABRA_H
#define PALABRA_H
#include <string>
#include "ListaFichas.h"
using namespace std;
class Palabra
{
private:
	string laPalabra;
	int bonos, valorSimple, valorTotal;
	ListaFichas* palabraFormada;
public:
	Palabra(ListaFichas*);
	void actualizarBono(int);
	void setListaPalabraFormada(ListaFichas*);
	ListaFichas* getPalabraFormada();
	string getLaPalabra();
	int getValorTotal();
	string toString();
	~Palabra();
};
#endif