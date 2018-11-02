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
	fichasConocidas = NULL;
}

string Tablero::getTablero(int X, int Y)
{
		if (X < 13 && Y < 13)
		{
			return getLetrasDeCasillas(X,Y);
		}
	

}

void Tablero::setFichasConocidas(ListaFichas * FICHASPARATABLERO)
{
	fichasConocidas = FICHASPARATABLERO;
}

ListaFichas * Tablero::getFichasConocidas()
{
	return fichasConocidas;
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
		p <<"<-------"<<i+1<< endl;
	}
	
	
	
	return p.str();
}


Tablero::~Tablero()
{
	
}

void Tablero::insertarPalabraHorizontalInicio(Palabra * formada, int columna, int fila)
{
	int conAux = columna;
	int filAux = fila;
	const string auxq = " ";
	string aux=formada->getLaPalabra();
	int limite = formada->getPalabraFormada()->cuentaNodos();
	int i = 0;
	cout << aux << endl;
	if (tablero[conAux][filAux] == "DP")
	{
		formada->actualizarBono(2);
	}
	else if (tablero[conAux][filAux] == "TP")
	{
		formada->actualizarBono(3);
	}
	
	for (i; i < limite; i++)
	{
		if (aux[i] == 'R' && aux[i + 1] == 'R')
		{
			tablero[conAux][filAux] = "RR";
			i++;
			filAux++;
		}
		else if (aux[i] == 'L'&& aux[i + 1] == 'L')
		{
			tablero[conAux][filAux] = "LL";
			i++;
			filAux++;
		}
		else if (aux[i] == 'C' && aux[i + 1] == 'H')
		{
			tablero[conAux][filAux] = "CH";
			i++;
			filAux++;
		}
		else
		{
			tablero[conAux][filAux] = auxq + aux[i];
			filAux= filAux+1;
		}
	}
}

void Tablero::insertarPalabraVerticalInico(Palabra * formada, int columna, int fila)
{
	int conAux = columna;
	int filAux = fila;
	const string auxq = " ";
	string aux = formada->getLaPalabra();
	int limite = formada->getPalabraFormada()->cuentaNodos();
	int i = 0;
	cout << aux << endl;
	if (tablero[conAux][filAux] == "DP")
	{
		formada->actualizarBono(2);
	}
	else if (tablero[conAux][filAux] == "TP")
	{
		formada->actualizarBono(3);
	}

	for (i; i < limite; i++)
	{
		
		
			if (aux[i] == 'R' && aux[i + 1] == 'R')
			{
				tablero[conAux][filAux] = "RR";
				i++;
				conAux = conAux + 1;
			}
			else if (aux[i] == 'L'&& aux[i + 1] == 'L')
			{
				tablero[conAux][filAux] = "LL";
				i++;
				conAux = conAux + 1;
			}
			else if (aux[i] == 'C' && aux[i + 1] == 'H')
			{
				tablero[conAux][filAux] = "CH";
				i++;
				conAux = conAux + 1;
			}
			else
			{
				tablero[conAux][filAux] = auxq + aux[i];
				conAux = conAux + 1;
			}
		
	}
}

string Tablero::getLetrasDeCasillas(int columna,int fila)
{
	if (tablero[columna][fila] == "RR" || tablero[columna][fila] == "CH" || tablero[columna][fila] == "LL")
	{
		return tablero[columna][fila];
	}
	else 
	{
		string auxq = " ";
		string palabraConEspacios = tablero[columna][fila];
		auxq = palabraConEspacios[1];
		return auxq;

	}
}

bool Tablero::verificarCasillas(int A, int B)
{
	const string terri = "  ";
	if (tablero[A][B] == terri || tablero[A][B] == "TP" || tablero[A][B] == "DP" || tablero[A][B] == "  " || tablero[A][B] == " " || tablero[A][B] == "") 
	{
		return true;
	}
	else return false;
}

bool Tablero::verificadorEspacioDePalabraHorizontal(int Columna, int fila, Palabra* palabra)
{
	int limite = palabra->getPalabraFormada()->cuentaNodos();
	int cont = 0;
	for (int i = Columna; i < 13; i++) 
	{
		if (verificarCasillas(i, fila) == true) 
		{
			cont++;
		}
		else if (verificarCasillas(i, fila) == false) 
		{
			if (cont > limite || cont == limite)
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool Tablero::verificadorEspacioDePalabraVertical(int Columna, int fila, Palabra * palabra)
{
	int limite = palabra->getPalabraFormada()->cuentaNodos();
	int cont = 0;
	for (int i = fila; i < 13; i++)
	{
		if (verificarCasillas(Columna, i) == true)
		{
			cont++;
		}
		else if (verificarCasillas(Columna, i) == false)
		{
			if (cont > limite || cont == limite)
			{
				return true;
			}
			else
				return false;
		}
	}
}

void Tablero::insertarLetrasInicioPalabraHorizontal(int columna, int fila, Palabra * palabra)
{
		if (verificadorEspacioDePalabraHorizontal(columna, fila, palabra) == true && verificarCasillas(columna, fila)==true)
	{
		insertarPalabraHorizontalInicio(palabra, columna, fila);
	}
	else
		cout << "Lo siento, pero su palabra no cabe totalmente en el tablero, ha perdido su turno" << endl;
}

void Tablero::insertarLetrasInicioPalabraVertical(int columna, int fila, Palabra * palabra)
{
	if (verificadorEspacioDePalabraHorizontal(columna, fila, palabra) == true && verificarCasillas(columna, fila) == true)
	{
		insertarPalabraVerticalInico(palabra, columna, fila);
	}
	else
		cout << "Lo siento, pero su palabra no cabe totalmente en el tablero, ha perdido su turno" << endl;
}

string Tablero::imprimeInstrucciones()
{
	stringstream p;
	p << "1:Ingresar letra. 2: Agregar 7 fichas a mis fichas. 3: Ceder Turno. 4: Salir del Juego " << endl;
	return p.str();
}



