#include "Juego.h"




Juego::Juego(Jugador * A, Jugador * B, Tablero * tb, Lista* Diccionario)
{
	this->Diccionario = Diccionario;
	this->A = A;
	this->B = B;
	tablero = tb;
}


bool Juego::insertarFichasHorizontalInicio(int columna, int fila, Palabra * palabra)
{
	int i = columna + palabra->getPalabraFormada()->cuentaNodos(), y = fila;
	const string espacio = "  ";
	const string espacio2 = " ";
	const string espacio3 = "";
	string aux, aux2;
	while ((i > 13) && (tablero->getTablero(i,y) != espacio || tablero->getTablero(i, y) != espacio2 || tablero->getTablero(i, y) != espacio3 || tablero->getTablero(i, y) != "TP" || tablero->getTablero(i, y) != "DP"))
	{
		aux = tablero->getTablero(i, y);
		aux2 = aux2 + aux;
		i++;
	}
	aux = palabra->getLaPalabra() + aux2;
	if (Diccionario->getNodoSegunPalabra(aux) == true) 
	{
		tablero->insertarLetrasInicioPalabraHorizontal(columna, fila, palabra);
		return true;
	}
	else return false;

}

bool Juego::insertarFichasVerticalInicio(int columna, int fila, Palabra * palabra)
{
	int i = columna , y = fila + palabra->getPalabraFormada()->cuentaNodos();
	const string espacio = "  ";
	const string espacio2 = " ";
	const string espacio3 = "";
	string aux, aux2;
	while ((y > 13) && (tablero->getTablero(i, y) != espacio || tablero->getTablero(i, y) != espacio2 || tablero->getTablero(i, y) != espacio3 || tablero->getTablero(i, y) != "TP" || tablero->getTablero(i, y) != "DP"))
	{
		aux = tablero->getTablero(i, y);
		aux2 = aux2 + aux;
		y++;
	}
	aux = palabra->getLaPalabra() + aux2;
	if (Diccionario->getNodoSegunPalabra(aux) == true)
	{
		tablero->insertarLetrasInicioPalabraVertical(columna, fila, palabra);
		return true;
	}
	else return false;
}

bool Juego::insertarFichasHorizontalFinal(int columna, int fila, Palabra * palabra)
{
	int i = columna, y = fila;
	const string espacio = "  ";
	const string espacio2 = " ";
	const string espacio3 = "";
	string aux, aux2;
	while ((i > 13) && (tablero->getTablero(i, y) != espacio || tablero->getTablero(i, y) != espacio2 || tablero->getTablero(i, y) != espacio3 || tablero->getTablero(i, y) != "TP" || tablero->getTablero(i, y) != "DP"))
	{
		aux = tablero->getTablero(i, y);
		aux2 = aux2 + aux;
		i++;
	}
	aux = aux2 + palabra->getLaPalabra();
	if (Diccionario->getNodoSegunPalabra(aux) == true)
	{
		tablero->insertarLetrasInicioPalabraHorizontal(columna, fila, palabra);
		return true;
	}
	else return false;
}

bool Juego::insertarFichasVerticalFinal(int columna, int fila, Palabra * palabra)
{
	int i = columna, y = fila;
	const string espacio = "  ";
	const string espacio2 = " ";
	const string espacio3 = "";
	string aux, aux2;
	while ((y > 13) && (tablero->getTablero(i, y) != espacio || tablero->getTablero(i, y) != espacio2 || tablero->getTablero(i, y) != espacio3 || tablero->getTablero(i, y) != "TP" || tablero->getTablero(i, y) != "DP"))
	{
		aux = tablero->getTablero(i, y);
		aux2 = aux2 + aux;
		y++;
	}
	aux = aux2 + palabra->getLaPalabra();
	if (Diccionario->getNodoSegunPalabra(aux) == true)
	{
		tablero->insertarLetrasInicioPalabraVertical(columna, fila, palabra);
		return true;
	}
	else return false;
}

int Juego::retornaValor(char letra)
{
	{
		switch (letra)
		{
		case 'A': return 0; break;
		case 'a': return 0; break;
		case 'B': return 1; break;
		case 'b': return 1; break;
		case 'c': return 2; break;
		case 'C': return 2; break;
		case 'D': return 3; break;
		case 'd': return 3; break;
		case 'E': return 4; break;
		case 'e': return 4; break;
		case 'f': return 5; break;
		case 'F': return 5; break;
		case 'G': return 6; break;
		case 'g': return 6; break;
		case 'H':return 7; break;
		case 'h': return 7; break;
		case 'I':return 8; break;
		case 'i':return 8; break;
		case 'j':return 9; break;
		case 'J':return 9; break;
		case 'k':return 10; break;
		case 'K':return 10; break;
		case 'L': return 11; break;
		case 'l':return 11; break;
		default: cout << "COLUMNA NO EXISTENTE, POR FAVOR RE INGRESE LA LETRA CORRESPONDIENTE A UNA COLUMNA DEL TABLERO" << endl;
			char eleccion2;
			cin >> eleccion2;
			return retornaValor(eleccion2);
		}
	}
}

bool Juego::verificarPalabra(Palabra* Palabran, int jugador)
{
	if (jugador == 1) //1 para A, 2 para B
	{
		string auxPalabra = Palabran->getLaPalabra();
		if (Diccionario->getNodoSegunPalabra(auxPalabra) == true)
		{
			A->setPalabra(Palabran);
			for (int i = 0; i < Palabran->getPalabraFormada()->cuentaNodos()-1; i++) 
			{
				string letra = Palabran->getPalabraFormada()->getFichasOrdenadas(i)->getLetra();
				A->getFichasJugador()->eliminarFicha(letra);
			}
			
			return true;
		}
		else
			return false;

	}
	else if (jugador == 2) 
	{
		string auxPalabra = Palabran->getLaPalabra();
		if (Diccionario->getNodoSegunPalabra(auxPalabra) == true)
		{
			B->setPalabra(Palabran);
			for (int i = 0; i < Palabran->getPalabraFormada()->cuentaNodos(); i++)
			{
				string letra = Palabran->getPalabraFormada()->getFichasOrdenadas(i)->getLetra();
				B->getFichasJugador()->eliminarFicha(letra);
			}
			return true;
		}
		else
			return false;
	}
}

Jugador * Juego::getA()
{
	return A;
}

Jugador * Juego::getB()
{
	return B;
}

Tablero * Juego::getTablero()
{
	return tablero;
}

Lista * Juego::getDiccionario()
{
	return Diccionario;
}



Juego::~Juego()
{
	
	tablero->~Tablero();
	delete A;
	delete B;
	delete tablero;
}
