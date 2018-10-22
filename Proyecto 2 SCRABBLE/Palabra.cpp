#include "Palabra.h"



Palabra::Palabra(ListaFichas* PALABRAFORMADA)
{
	palabraFormada = PALABRAFORMADA;
	laPalabra = palabraFormada->obtenerLetras();
	bonos = 1;
	valorSimple = palabraFormada->obtenerValorLetras();
	valorTotal = valorSimple * bonos;
}

void Palabra::actualizarBono(int BONO)
{
	bonos = BONO;
	valorTotal = valorSimple * bonos;
}

int Palabra::getValorTotal()
{
	return valorTotal;
}


string Palabra::toString()
{
	stringstream p;
	p << "Palabra Formada: " << laPalabra << endl;
	p << "Bonos: " << bonos << endl;
	p << "Valor Simple: " << valorSimple << endl;
	p << "Valor Total: " << valorTotal << endl;
	return p.str();
}


Palabra::~Palabra()
{
}
