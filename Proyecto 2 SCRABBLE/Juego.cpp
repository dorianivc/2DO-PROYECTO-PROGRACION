#include "Juego.h"




Juego::Juego(Jugador * A, Jugador * B, Tablero * tb, Lista* Diccionario)
{
	this->Diccionario = Diccionario;
	this->A = A;
	this->B = B;
	tablero = tb;
}

ListaFichas * Juego::crearPrimeraPalabra(int eleccion)
{
	string entrada, auxVerificarDiccionario;
	ListaFichas* fichasJugada = new ListaFichas();
	int contador = 0;//contador de jugadas
	if (eleccion == 1) {
		for (int y = 0; y < 13; y++) {
			cin >> entrada;
			if (entrada == "SD")
			{
				y = 100;
			}
			else
			{
				if (entrada == "Ñ" || entrada == "ñ")
				{
					entrada = char(164);
				}

				Fichas* aux = A->getFichasJugador()->getFichaDeLista(entrada);
				if (aux->getLetra() == entrada && contador == 0)
				{

					Fichas* aux3 = aux;
					cout << aux3->toString() << endl;
					fichasJugada->insertarInicio(aux3);

					contador++;


				}
				else
					if (aux->getLetra() != entrada)
					{
						cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
					}
					else
						if (aux->getLetra() == entrada && contador > 0)
						{
							Fichas* aux2 = aux;
							cout << aux2->toString() << endl;
							fichasJugada->insertarFinal(aux2);

						}

			}

		}
		cout << fichasJugada->toString() << endl;
		return fichasJugada;
	}
	else if (eleccion == 2)
	{
		for (int y = 0; y < 13; y++) {
			cin >> entrada;
			if (entrada == "SD")
			{
				y = 100;
			}
			else
			{
				if (entrada == "Ñ" || entrada == "ñ")
				{
					entrada = char(164);
				}

				Fichas* aux = B->getFichasJugador()->getFichaDeLista(entrada);
				if (aux->getLetra() == entrada && contador == 0)
				{

					Fichas* aux3 = aux;
					cout << aux3->toString() << endl;
					fichasJugada->insertarInicio(aux3);

					contador++;


				}
				else
					if (aux->getLetra() != entrada)
					{
						cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
					}
					else
						if (aux->getLetra() == entrada && contador > 0)
						{
							Fichas* aux2 = aux;
							cout << aux2->toString() << endl;
							fichasJugada->insertarFinal(aux2);

						}

			}

		}
		cout << fichasJugada->toString() << endl;
		return fichasJugada;
	}
	else
		cout << "Ha ocurrido algun error" << endl;
}

void Juego::JugarPrimeraParte()
{
	cout << "Empezaremos formando una palabra con sus fichas" << endl << "A continuacion usted presionara las letra que desea usar y presionara Enter" << endl << "Cuando termine escriba SD y presione Enter" << endl;
	cout << A->toString() << endl;
	ListaFichas* aux = crearPrimeraPalabra(1);
	Palabra* entrante = new Palabra(aux);
	if (verificarPalabra(entrante, 1) == true)
	{

		cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
		cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
		int entrada;
		A->setPalabra(entrante);
		do {
			cin >> entrada;
			if (entrada == 1)
			{
				cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
				char columna;
				cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
				retornaValor(columna);
				int eleccionColumna = retornaValor(columna);
				cout << "Digite el numero de la fila donde quiere poner la palabra" << endl;
				int fila;
				cin >> fila;//validaciones no puede ser ni letra ni mayor a 13
				if (fila < 0 || fila>13)
				{
					do
					{
						cout << "Ha digitado una fila inexistente por favor intentelo de nuevo" << endl;
						cin >> fila;
					} while (fila > 13 && fila < 0);
				}
				tablero->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
				int p = entrante->getValorTotal();
				A->sumarPuntuacion(p);
				cout << tablero->toString();
				entrada = 3;
			}
			else
				if (entrada == 2)
				{
					cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
					char columna;
					cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
					retornaValor(columna);
					int eleccionColumna = retornaValor(columna);
					cout << "Digite el numero de la fila donde quiere poner la palabra" << endl;
					int fila;
					cin >> fila;//validaciones no puede ser ni letra ni mayor a 13
					if (fila < 0 || fila>13)
					{
						do
						{
							cout << "Ha digitado una fila inexistente por favor intentelo de nuevo" << endl;
							cin >> fila;
						} while (fila > 13 && fila < 0);
					}
					tablero->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
					int p = entrante->getValorTotal();
					A->sumarPuntuacion(p);
					cout << tablero->toString();
					entrada = 3;

				}



		} while (entrada > 3);
	}
	else
		if (verificarPalabra(entrante, 1) == false)
		{
			cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
			system("PAUSE");
			system("cls");
			cout << "Turno del jugador: " << B->getNombre() << endl;
			cout << "Empezaremos formando una palabra con sus fichas" << endl << "A continuacion usted presionara las letra que desea usar y presionara Enter" << endl << "Cuando termine escriba SD y presione Enter" << endl;
			cout << B->toString() << endl;
			aux = crearPrimeraPalabra(2);
			entrante = new Palabra(aux);
			int entrada;
			if (verificarPalabra(entrante, 2) == true) {
				cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
				cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
				B->setPalabra(entrante);
				do {
					cin >> entrada;
					if (entrada == 1)
					{
						cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
						char columna;
						cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
						retornaValor(columna);
						int eleccionColumna = retornaValor(columna);
						cout << "Digite el numero de la fila donde quiere poner la palabra" << endl;
						int fila;
						cin >> fila;//validaciones no puede ser ni letra ni mayor a 13
						if (fila < 0 || fila>13)
						{
							do
							{
								cout << "Ha digitado una fila inexistente por favor intentelo de nuevo" << endl;
								cin >> fila;
							} while (fila > 13 && fila < 0);
						}
						tablero->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
						int p = entrante->getValorTotal();
						A->sumarPuntuacion(p);
						cout << tablero->toString();
						entrada = 3;
					}
					else
						if (entrada == 2)
						{
							cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
							char columna;
							cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
							retornaValor(columna);
							int eleccionColumna = retornaValor(columna);
							cout << "Digite el numero de la fila donde quiere poner la palabra" << endl;
							int fila;
							cin >> fila;//validaciones no puede ser ni letra ni mayor a 13
							if (fila < 0 || fila>13)
							{
								do
								{
									cout << "Ha digitado una fila inexistente por favor intentelo de nuevo" << endl;
									cin >> fila;
								} while (fila > 13 && fila < 0);
							}
							tablero->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
							int p = entrante->getValorTotal();
							A->sumarPuntuacion(p);
							cout << tablero->toString();
							entrada = 3;

						}



				} while (entrada > 3);

			}
			else
				cout << "Vamos agregando letras" << endl;
		}
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
	delete A;
	delete B;
	delete tablero;
}
