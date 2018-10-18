#include "Palabra.h"



Palabra::Palabra(ListaFichas* PALABRAFORMADA)
{
	palabraFormada = PALABRAFORMADA;
	laPalabra = palabraFormada->obtenerLetras();
	bonos = 1;
	valorSimple = palabraFormada->obtenerValorLetras();
	valorTotal = valorSimple * bonos;
}


Palabra::~Palabra()
{
}
