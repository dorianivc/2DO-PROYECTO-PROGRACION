#include "ColeccionPalabras.h"



ColeccionPalabras::ColeccionPalabras()
{
	for (int i = 0; i < 300; i++) 
	{
		palabras[i] = "VACIO";
	}
}

void ColeccionPalabras::insertarPalabra(string & Palabra)
{
	int i = 0;
	int resultado = 0;
	while (i > 300) 
	{
		if (palabras[i] != "VACIO")
		{
			i++;
		}
		else
		{
			resultado = i;
			i == 500;
		}
		
	}
	palabras[resultado] = Palabra;
}

string ColeccionPalabras::getPalabra(int i)
{
	return palabras[i];
}


ColeccionPalabras::~ColeccionPalabras()
{
}
