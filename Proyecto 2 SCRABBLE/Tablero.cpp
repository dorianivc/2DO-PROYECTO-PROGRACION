#include "Tablero.h"



Tablero::Tablero()
{
	for (int i = 0; i < 13; i++)
	{
		for (int y = 0; y < 13; y++)
		{
			tablero[i][y] = "  ";
		}
	}
	tablero[0][0] = "DP";
	tablero[0][7] = "DP";
	tablero[0][11] = "DP";
	tablero[0][12] = "TP";
	tablero[1][2] = "TP";
	tablero[1][4] = "DP";
	tablero[1][10] = "DP";
	tablero[2][3] = "TP";
	tablero[2][9] = "DP";
	tablero[3][8] = "DP";
	tablero[4][7] = "TP";
	tablero[5][6] = "DP";
	tablero[6][5] = "DP";
	tablero[7][4] = "DP";
	tablero[5][4] = "TP";
	tablero[4][2] = "DP";
	tablero[3][4] = "TP";
	tablero[4][5] = "TP";
	tablero[5][6] = "DP";
	tablero[6][7] = "TP";
	tablero[7][8] = "TP";
	tablero[3][10] = "TP";
	tablero[7][0] = "TP";
	tablero[7][12] = "DP";
}

string Tablero::toString()
{
	stringstream p;
	p << "Bienvenido a Scrabble" << endl;
	p << "TP: TRIPLICA PALABRA" << endl;
	p << "DP: DUPLICLA PALABRA" << endl;
	p << "  " << "A" << " ";
	p << "  " << "B" << " ";
	p << "  " << "C" << " ";
	p << "  " << "D" << " ";
	p << "  " << "E" << " ";
	p << "  " << "F" << " ";
	p << "  " << "G" << " ";
	p << "  " << "H" << " ";
	p << "  " << "I" << " ";
	p << "  " << "J" << " ";
	p << "  " << "K" << " ";
	p << "  " << "L" << " ";
	p << "  " << "M" << " ";
	p << endl;
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << "  " << "|" << " ";
	p << endl;

	for (int i = 0; i < 13; i++)
	{
		
		for (int y = 0; y < 13; y++)
		{
			
			p << "[" << tablero[i][y] << "]";
			
		}
		p <<"--->"<< i+1 << endl;
	}


	
	
	return p.str();
}


Tablero::~Tablero()
{
	
}
