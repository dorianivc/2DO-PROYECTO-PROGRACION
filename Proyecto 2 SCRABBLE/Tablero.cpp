#include "Tablero.h"



Tablero::Tablero()
{
	for (int i = 0; i < 13; i++) 
	{
		for (int y = 0; y < 13; y++) 
		{
			tablero[i][y] = " ";
		}
	}
}

string Tablero::toString()
{
	stringstream p;
	for (int i = 0; i < 13; i++)
	{
		
		for (int y = 0; y < 13; y++)
		{
			
			p << "[" << tablero[i][y] << "]";
			
		}
		p << endl;
	}
	return p.str();
}


Tablero::~Tablero()
{
	
}
