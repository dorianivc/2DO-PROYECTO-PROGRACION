//ESCULA DE INFORMATICA UNIVERSIDAD NACIONAL
//ESTUDIANTE: DORIAN VALLECILLO CALDERON
//2DO PROYECTO, PROGRAMACION I
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <locale.h>
#include "ListaDiccionario.h"
#include "ListaFichas.h"
#include <time.h>
#include "Tablero.h"
#include "Jugador.h"
#include "Juego.h"
#include "ColeccionPalabras.h"

using namespace std;
void convertirMayuscula(string & entrada)
{
	for (int i = 0; i < entrada.length(); i++) 
	{
		entrada[i] = toupper(entrada[i]);
	}
}
bool validarNumeroAux(string& p) {
	for (int i = 0; i < p.length(); i++) {
		if (!(isdigit(p[i]))) {
			cout << "Ingresa solo numeros" << endl;
			return false;

		}

	}
	return true;
}
int validarNumero(string &p) 
{
	if (validarNumeroAux(p) == true)
	{
		return p[0];
	}
	else if (validarNumeroAux(p) == false) 
	{
		
		cin >> p;
		return p[0];
	}
		


}
bool validarLetraAux(string& p) {
	for (int i = 0; i < p.length(); i++) {
		if ((isdigit(p[i]))) {
			cout << "Ingresa solo letras" << endl;
			return false;

		}

	}
	return true;
}
string validarLetra(string &p) 
{
	if (validarLetraAux(p) == true)
	{
		return p;
	}
	else if (validarLetraAux(p) == false)
	{
		cin >> p;
		
		
	}
	return p;

}
int main() {
	setlocale(LC_ALL, "spanish");
	int perro = 0;
	char papaya = 'p';
	int zopilote = 0;
	char terri = 'p';
	char gato = 'p';
	char perico = 'p';
	char perico2 = 'p';
	do{
	cout << "Bienvenido a Scrabble" << endl;
	string w = "0";
	cout << "Digite 1 para comenzar el juego" << endl;
	cout << "Digite 2 para ver los records e historial de palabras ingresadas" << endl;
	cout << "Presione 3 para salir" << endl;
	cin >> w;
	validarNumero(w);
	if(w=="1")
	{
	
	
	string aux1, aux2;
	ifstream dicionarioFisico;
	dicionarioFisico.open("diccionario.txt");
	Lista* diccionario;//Lista de ListaDiccionario.h
	diccionario = new Lista();
	if (dicionarioFisico.fail())
	{
		cout << "Error al cargar diccionario de palabras" << endl;
	}
	else
		dicionarioFisico >> aux1;
	diccionario->insertarInicio(&aux1);
	cout << aux1 << endl;
	int cont = 1;
	while (!dicionarioFisico.eof())
	{
		dicionarioFisico >> aux1;
		diccionario->insertarInicio(&aux1);
		cout << aux1 << endl;
		cont++;

	}
	system("PAUSE");
	cout << "Contador del ciclo es: " << cont << endl;
	cout << "Probando lista" << endl;
	cout << "Contador de nodos: " << endl;
	cout << diccionario->cuentaNodos() << endl;
	system("cls");

	dicionarioFisico.close();


	//Lectura de Fichas
	ListaFichas* FICHAS;//<--------------------------------------LISTA DE FICHAS 
	FICHAS = new ListaFichas();
	ifstream lecturaFichas;
	string  LETRA, VALOR, TOTALFICHAS;
	lecturaFichas.open("fichasDor.txt");
	if (lecturaFichas.fail())
	{
		cout << "Error al abrir el archivo de las fichas" << endl;
	}
	else
		while (!lecturaFichas.eof())
		{
			getline(lecturaFichas, LETRA, '/');
			getline(lecturaFichas, VALOR, '/');
			getline(lecturaFichas, TOTALFICHAS, '/');
			FICHAS->insertarInicio(new Fichas(LETRA, VALOR, TOTALFICHAS));
			cout << LETRA << endl;
			cout << VALOR << endl;
			cout << TOTALFICHAS << endl;

		}

	FICHAS->insertarInicio(new Fichas("COMODIN", "0", "2"));
	system("cls");

	cout << "Contador de nodos: " << endl;
	cout << FICHAS->toString();
	cout << FICHAS->cuentaNodos() << endl;
	lecturaFichas.close();
	Tablero* tb = new Tablero();
	tb->setFichasConocidas(FICHAS);

	//<----------------------- Hacemos la lista de 7 fichas para darselas a cada jugador
	srand(time(NULL));
	ListaFichas* fichasA;
	ListaFichas* fichasB;
	fichasA = new ListaFichas();
	fichasB = new ListaFichas();
	int num;
	num = 1 + rand() % (29 - 1);
	for (int i = 0; i < 7; i++)
	{
		num = 1 + rand() % (29 - 1);
		fichasA->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());
		FICHAS->fichaAleatoria(num)->getLetra()->utilizarFicha();



	}

	for (int y = 0; y < 7; y++)
	{
		num = 1 + rand() % (29 - 1);
		fichasB->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());
		FICHAS->fichaAleatoria(num)->getLetra()->utilizarFicha();

	}



	//<------------------------------- Creo cada Jugador con sus fichas
	cout << "Bienvenidos a Scrabble." << endl;
	cout << "Este juego fue creado para jugar dos personas" << endl;
	cout << "Despues de desplegado el tablero, seguidamente van a tener un menu" << endl;
	cout << " Para ingresar la ficha en el tablero, una vez escogida la letra que desea ingresar, digite La letra de la Columna y Fila para colocar las fichas" << endl;
	ColeccionPalabras* contenedor = new ColeccionPalabras();
	string nombre;
	cout << "Digite el nombre del Jugador 1 y presione ENTER " << endl;
	cin >> nombre;
	Jugador* A = new Jugador(nombre, fichasA);
	cout << "Digite el nombre del Jugador 2 y presione ENTER" << endl;
	cin >> nombre;
	Jugador* B = new Jugador(nombre, fichasB);
	//<------------------------------------- Aqui una prueba de palabra;
	Palabra* palabraAUX = new Palabra(fichasA);

	//<------------------------------------- Ciclo de juego
	Juego* juegoPrincipal = new Juego(A, B, tb, diccionario);
	cout << tb->toString() << endl;
	//--->JUGUEMOS<---
	cout << "Empezaremos formando una palabra con sus fichas" << endl << "A continuacion usted presionara las letra que desea usar y presionara Enter" << endl << "Cuando termine escriba SD y presione Enter" << endl;
	string entrada, auxVerificarDiccionario;
	ListaFichas* fichasJugada = new ListaFichas();
	Palabra* entrante = new Palabra(fichasJugada);
	delete fichasJugada;
	fichasJugada = new ListaFichas();
	cout << A->toString() << endl;

	int contador = 0;//contador de jugadas

	for (int y = 0; y < 13; y++) {
		cin >> entrada;
		entrada=validarLetra(entrada);
		convertirMayuscula(entrada);
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

	if (fichasJugada != NULL)
	{
		delete entrante;
		entrante = new Palabra(fichasJugada);
		int verificador = 0;
		if (juegoPrincipal->verificarPalabra(entrante, 1) == true)
		{
			
			cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
			cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
			string entrada;
			A->setPalabra(entrante);
			
			do {
				perico = 'p';
				cin >> entrada;
				entrada = validarNumero(entrada);
				if (entrada == "1")
				{
					cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
					char columna;
					cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
					juegoPrincipal->retornaValor(columna);
					int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
					juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
					int p = entrante->getValorTotal();
					A->setPalabra(entrante);
					A->sumarPuntuacion(p);
					string conAux = entrante->getLaPalabra();
					contenedor->insertarPalabra(conAux);
					cout << juegoPrincipal->getTablero()->toString();
					verificador = 1;
					perico='z';
				}
				else
					if (entrada == "2")
					{
						cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
						char columna;
						cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
						int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
						juegoPrincipal->getTablero()->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
						int p = entrante->getValorTotal();
						A->sumarPuntuacion(p);
						A->setPalabra(entrante);
						string conAux = entrante->getLaPalabra();
						contenedor->insertarPalabra(conAux);
						cout << juegoPrincipal->getTablero()->toString();
						verificador = 1;
						perico = 'z';
					}
					else 
					{
						perico = 'p';
					}



			} while (perico=='p');
		}
		else
			if (juegoPrincipal->verificarPalabra(entrante, 1) == false)
			{
				cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
				system("PAUSE");
				system("cls");
				cout << "Turno del jugador: " << B->getNombre() << endl;
				cout << "Empezaremos formando una palabra con sus fichas" << endl << "A continuacion usted presionara las letra que desea usar y presionara Enter" << endl << "Cuando termine escriba SD y presione Enter" << endl;
				cout << B->toString() << endl;
				delete fichasJugada;
				fichasJugada = new ListaFichas();
				int contador = 0;//contador de jugadas
				for (int y = 0; y < 13; y++) {
					cin >> entrada;
					entrada = validarLetra(entrada);
					convertirMayuscula(entrada);
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
				if (fichasJugada != NULL)
				{
					
					delete entrante;
					entrante = new Palabra(fichasJugada);
					string entrada;
					if (juegoPrincipal->verificarPalabra(entrante, 2) == true) {
						cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
						cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
						B->setPalabra(entrante);
						do {
							perico2 = 'p';
							cin >> entrada;
							entrada= validarNumero(entrada);
							if (entrada == "1")
							{
								cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								char columna;
								cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								juegoPrincipal->retornaValor(columna);
								int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
								juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
								int p = entrante->getValorTotal();
								B->setPalabra(entrante);
								B->sumarPuntuacion(p);
								string conAux = entrante->getLaPalabra();
								contenedor->insertarPalabra(conAux);
								cout << juegoPrincipal->getTablero()->toString() << endl;
								verificador = 1;
								perico2='z';

							}
							else
								if (entrada == "2")
								{
									cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
									char columna;
									cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									juegoPrincipal->retornaValor(columna);
									int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
									juegoPrincipal->getTablero()->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
									B->setPalabra(entrante);
									int p = entrante->getValorTotal();
									B->sumarPuntuacion(p);
									string conAux = entrante->getLaPalabra();
									contenedor->insertarPalabra(conAux);
									cout << juegoPrincipal->getTablero()->toString() << endl;
									verificador = 1;
									perico2= 'z';
								}
								else 
								{
									perico2 = 'p';
								}



						} while (perico2=='p');
					}
					else
					{
						cout << "La palabra no existe, ha perdido su turno" << endl;
						system("PAUSE");
						system("cls");
					}
				}
				else
					cout << "Ha ocurrido  un error con la lista de fichas que usted eligio" << endl;

			}

	}
	//<------------- TERMINA PRIMERA PARTE
//<--------------Jugador A;
	
	do{
	
	cout << juegoPrincipal->getTablero()->toString() << endl;
	cout << "Es el turno de " << juegoPrincipal->getA()->getNombre() << endl;
	cout << juegoPrincipal->getA()->toString() << endl;
	cout << juegoPrincipal->getTablero()->imprimeInstrucciones() << endl;
	
	string eleccionA;
	do {
		
		cin >> eleccionA;
		eleccionA = validarNumero(eleccionA);
		if (eleccionA == "1")
		{
			cout << "Digite 1 si desea formar una palabra nueva" << endl;
			cout << "Digite 2 si desea formar una palabra nueva a base de otra palabra" << endl;
			string seleccionA1;
			seleccionA1 = validarNumero(seleccionA1);
			cin >> seleccionA1;
			if (seleccionA1 == "1")
			{
				cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
				delete fichasJugada;
				fichasJugada = new ListaFichas();
				int contador = 0;//contador de jugadas
				for (int y = 0; y < 13; y++) {
					cin >> entrada;
					entrada = validarLetra(entrada);
					convertirMayuscula(entrada);
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

				if (fichasJugada != NULL)
				{
					delete entrante;
					entrante = new Palabra(fichasJugada);
					int verificador = 0;
					if (juegoPrincipal->verificarPalabra(entrante, 1) == true)
					{

						cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
						cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
						string entrada;
						A->setPalabra(entrante);
						terri = 'p';
						do {
							cin >> entrada;
							entrada = validarNumero(entrada);
							if (entrada == "1")
							{
								cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								char columna;
								cin >> columna;
								juegoPrincipal->retornaValor(columna);
								int eleccionColumna = juegoPrincipal->retornaValor(columna);
								cout << "Digite el numero de la fila donde quiere poner la palabra" << endl;
								int fila;
								cin >> fila;
								if (fila < 0 || fila>13)
								{
									do
									{
										cout << "Ha digitado una fila inexistente por favor intentelo de nuevo" << endl;
										cin >> fila;
									} while (fila > 13 && fila < 0);
								}
								if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraHorizontal(eleccionColumna, fila, entrante) == true)
								{
									juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
									A->setPalabra(entrante);
									int p = entrante->getValorTotal();
									A->sumarPuntuacion(p);
									string conAux = entrante->getLaPalabra();
									contenedor->insertarPalabra(conAux);
									cout << juegoPrincipal->getTablero()->toString();
									verificador = 1;
									terri = 'z';
									zopilote = 6;
									
								}
								else
									cout << "La palabra no cabe, ha perdido su turno" << endl;
							
							}
							else
								if (entrada == "2")
								{
									cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
									char columna;
									cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
									eleccionA = 12;
									if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraVertical(eleccionColumna, fila, entrante) == true) {
										A->setPalabra(entrante);
										juegoPrincipal->getTablero()->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
										int p = entrante->getValorTotal();
										A->sumarPuntuacion(p);
										string conAux = entrante->getLaPalabra();
										contenedor->insertarPalabra(conAux);
										cout << juegoPrincipal->getTablero()->toString();
										verificador = 1;
										terri = 'z';
										zopilote = 6;
										
									}
									else
										cout << "La palabra no cabe, ha perdido su turno" << endl;
										terri = 'z';
										zopilote = 6;
								}
								else 
								{
									terri = 'p';
								}



						} while (terri=='p');
					}
					else
						if (juegoPrincipal->verificarPalabra(entrante, 1) == false)
						{
							cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
							system("PAUSE");
							system("cls");
							zopilote = 6;
						}
				}
			}
			else
				if (seleccionA1 == "2")
				{
					cout << "Presione 1 si desea agregar la palabra de forma Horizontal" << endl;
					cout << "Presione 2 si desea agregar la palabra de forma Vertical" << endl;
					string seleccionA3;
					cin >> seleccionA3;
					seleccionA3 = validarNumero(seleccionA3);
					if (seleccionA3 == "1")
					{
						string seleccionA4;
						cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						cin >> seleccionA4;
						seleccionA4 = validarNumero(seleccionA4);
						if (seleccionA4 == "1")
						{
							cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
							cout << A->toString() << endl;
							ListaFichas* fichasJugada = new ListaFichas();
							int contador = 0;//contador de jugadas
							for (int y = 0; y < 13; y++) {
								cin >> entrada;
								entrada = validarLetra(entrada);
								convertirMayuscula(entrada);
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
										if (aux->getLetra() == entrada && contador > 0)
										{
											Fichas* aux2 = aux;
											cout << aux2->toString() << endl;
											fichasJugada->insertarFinal(aux2);

										}
										else

											if (aux->getLetra() != entrada)
											{
												cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
											}

								}



							}
							cout << fichasJugada->toString() << endl;

							if (fichasJugada != NULL)
							{
								delete entrante;
								entrante = new Palabra(fichasJugada);
								cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								char columna;
								cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								juegoPrincipal->retornaValor(columna);
								int eleccionColumna = juegoPrincipal->retornaValor(columna);
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

								if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								{

									juegoPrincipal->insertarFichasHorizontalFinal(eleccionColumna, fila, entrante);
									string conAux = entrante->getLaPalabra();
									contenedor->insertarPalabra(conAux);
									cout << juegoPrincipal->getTablero()->toString() << endl;
									zopilote = 6;
								}
								else
									cout << "La palabra no existe, ha perdido su turno" << endl;
								zopilote = 6;
							}

						}
						else if (seleccionA4 == "2")
						{
							{
								cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
								cout << A->toString() << endl;
								delete fichasJugada;
								fichasJugada = new ListaFichas();
								int contador = 0;//contador de jugadas
								for (int y = 0; y < 13; y++) {
									cin >> entrada;
									entrada=validarLetra(entrada);
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
											if (aux->getLetra() == entrada && contador > 0)
											{
												Fichas* aux2 = aux;
												cout << aux2->toString() << endl;
												fichasJugada->insertarFinal(aux2);

											}
											else

												if (aux->getLetra() != entrada)
												{
													cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
												}

									}



								}
								cout << fichasJugada->toString() << endl;
								delete entrante;
								if (fichasJugada != NULL)
								{

									entrante = new Palabra(fichasJugada);
									cout << "Digite la letra de la columna donde empezaria la palabra" << endl;
									char columna;
									cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									juegoPrincipal->retornaValor(columna);
									int eleccionColumna = juegoPrincipal->retornaValor(columna);
									cout << "Digite el numero de la fila donde empezaria la palabra" << endl;
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
									if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									{

										if (juegoPrincipal->insertarFichasHorizontalInicio(eleccionColumna, fila, entrante) == true)
										{
											cout << juegoPrincipal->getTablero()->toString() << endl;
											string conAux = entrante->getLaPalabra();
											contenedor->insertarPalabra(conAux);
											zopilote = 6;
										}
										else
											cout << "La palabra no existe, ha perdido su turno" << endl;
										zopilote = 6;

									}
									
								}

							}

						}
					}
					else if (seleccionA3 == "2")
						 {

						 string seleccionA4;
						 cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						 cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						 cin >> seleccionA4;
						 seleccionA4 = validarNumero(seleccionA4);
						 if (seleccionA4 == "1")
						 {
							 cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
							 cout << A->toString() << endl;
							 ListaFichas* fichasJugada1 = new ListaFichas();
							 int contador = 0;//contador de jugadas
							 for (int y = 0; y < 13; y++) {
								 cin >> entrada;
								 entrada = validarLetra(entrada);
								 convertirMayuscula(entrada);
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
										 fichasJugada1->insertarInicio(aux3);

										 contador++;


									 }
									 else
										 if (aux->getLetra() == entrada && contador > 0)
										 {
											 Fichas* aux2 = aux;
											 cout << aux2->toString() << endl;
											 fichasJugada1->insertarFinal(aux2);

										 }
										 else

											 if (aux->getLetra() != entrada)
											 {
												 cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
											 }

								 }



							 }
							 cout << fichasJugada1->toString() << endl;

							 if (fichasJugada1 != NULL)
							 {
								 delete entrante;
								 entrante = new Palabra(fichasJugada);
								 cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								 char columna;
								 cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								 juegoPrincipal->retornaValor(columna);
								 int eleccionColumna = juegoPrincipal->retornaValor(columna);
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

								 if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								 {

									 juegoPrincipal->insertarFichasVerticalFinal(eleccionColumna, fila, entrante);
									 string conAux = entrante->getLaPalabra();
									 contenedor->insertarPalabra(conAux);
									 cout << juegoPrincipal->getTablero()->toString() << endl;
									 zopilote = 6;
								 }
								 else
									 cout << "La palabra no existe, ha perdido su turno" << endl;
								 zopilote = 6;
							 }

						 }
						 else if (seleccionA4 == "2")
						 {
							 {
								 cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
								 cout << A->toString() << endl;
								 delete fichasJugada;
								 fichasJugada = new ListaFichas();
								 int contador = 0;//contador de jugadas
								 for (int y = 0; y < 13; y++) {
									 cin >> entrada;
									 entrada = validarLetra(entrada);
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
											 if (aux->getLetra() == entrada && contador > 0)
											 {
												 Fichas* aux2 = aux;
												 cout << aux2->toString() << endl;
												 fichasJugada->insertarFinal(aux2);

											 }
											 else

												 if (aux->getLetra() != entrada)
												 {
													 cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
												 }

									 }



								 }
								 cout << fichasJugada->toString() << endl;
								 delete entrante;
								 if (fichasJugada != NULL)
								 {

									 entrante = new Palabra(fichasJugada);
									 cout << "Digite la letra de la columna donde empezaria la palabra" << endl;
									 char columna;
									 cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									 juegoPrincipal->retornaValor(columna);
									 int eleccionColumna = juegoPrincipal->retornaValor(columna);
									 cout << "Digite el numero de la fila donde empezaria la palabra" << endl;
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
									 if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									 {

										 if (juegoPrincipal->insertarFichasVerticalInicio(eleccionColumna, fila, entrante) == true)
										 {
											 cout << juegoPrincipal->getTablero()->toString() << endl;
											 string conAux = entrante->getLaPalabra();
											 contenedor->insertarPalabra(conAux);
											 zopilote = 6;
										 }
										 else
											 cout << "La palabra no existe, ha perdido su turno" << endl;
										 zopilote = 6;

									 }

								 }

							 }

						 }
						}



						//aqui
				}
		}
		else if (eleccionA == "2")
		{
			for (int i = 0; i < 7; i++)
			{
				num = 1 + rand() % (29 - 1);
				fichasA->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());
				FICHAS->fichaAleatoria(num)->getLetra()->utilizarFicha();

			}
			cout << juegoPrincipal->getA()->toString() << endl;
		}
		else
			if (eleccionA == "3")
			{
				zopilote = 6;
			}
			else if (eleccionA == "4")
			{
				zopilote = 6;
				gato = 'z';
				
			}
			else 
				cout << "Ha digitado un caracter incorrecto por favor intentelo de nuevo" << endl;
	}while (zopilote<6);

	//<-----------TERMINA JUGADOR A;

	//<-----------EMPIEZA JUGADOR B;

	cout << juegoPrincipal->getTablero()->toString() << endl;
	cout << "Es el turno de " << juegoPrincipal->getB()->getNombre() << endl;
	cout << juegoPrincipal->getB()->toString() << endl;
	cout << juegoPrincipal->getTablero()->imprimeInstrucciones() << endl;
	
	do {
		//perro = 'p';
		cin >> eleccionA;
		if (eleccionA == "1")
		{
			cout << "Digite 1 si desea formar una palabra nueva" << endl;
			cout << "Digite 2 si desea formar una palabra nueva a base de otra palabra" << endl;
			string seleccionA1;
			cin >> seleccionA1;
			seleccionA1 = validarNumero(seleccionA1);
			if (seleccionA1 == "1")
			{
				cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
				delete fichasJugada;
				fichasJugada = new ListaFichas();
				int contador = 0;//contador de jugadas
				for (int y = 0; y < 13; y++) {
					cin >> entrada;
					entrada = validarLetra(entrada);
					convertirMayuscula(entrada);
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
							if (aux->getLetra() == entrada && contador > 0)
							{
								Fichas* aux2 = aux;
								cout << aux2->toString() << endl;
								fichasJugada->insertarFinal(aux2);

							}
							else

								if (aux->getLetra() != entrada)
								{
									cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
								}

					

					}



				}
				cout << fichasJugada->toString() << endl;

				if (fichasJugada != NULL)
				{
					delete entrante;
					entrante = new Palabra(fichasJugada);
					int verificador = 0;
					if (juegoPrincipal->verificarPalabra(entrante, 2) == true)
					{

						cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
						cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
						string entrada;
						B->setPalabra(entrante);
						do {
							cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
							cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
							cin >> entrada;
							entrada = validarNumero(entrada);
							if (entrada == "1")
							{
								cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								char columna;
								cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								juegoPrincipal->retornaValor(columna);
								int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
								
								if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraHorizontal(eleccionColumna, fila, entrante) == true)
								{
									juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
									int p = entrante->getValorTotal();
									A->sumarPuntuacion(p);
									string conAux = entrante->getLaPalabra();
									contenedor->insertarPalabra(conAux);
									cout << juegoPrincipal->getTablero()->toString();
									verificador = 1;
									perro = 6;
								}
								else 
									cout << "La palabra no cabe, ha perdido su turno" << endl;
								perro = 6;
							}
							else
								if (entrada == "2")
								{
									cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
									char columna;
									cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
									if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraVertical(eleccionColumna, fila, entrante) == true) {
										juegoPrincipal->getTablero()->insertarPalabraVerticalInico(entrante, eleccionColumna, fila - 1);
										int p = entrante->getValorTotal();
										A->sumarPuntuacion(p);
										string conAux = entrante->getLaPalabra();
										contenedor->insertarPalabra(conAux);
										cout << juegoPrincipal->getTablero()->toString();
										verificador = 1;
									
										perro = 6;
									}
									else
										cout << "La no cabe, ha perdido su turno" << endl;
									perro = 6;
								}
								else 
								{

								}



						} while (perro<6);
					}
					else
						if (juegoPrincipal->verificarPalabra(entrante, 1) == false)
						{
							cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
							perro = 'z';
							system("PAUSE");
							system("cls");
						}
				}
			}
			else
				if (seleccionA1 == "2")
				{
					cout << "Presione 1 si desea agregar la palabra de forma Horizontal" << endl;
					cout << "Presione 2 si desea agregar la palabra de forma Vertical" << endl;
					int seleccionA3;
					cin >> seleccionA3;
					if (seleccionA3 == 1)
					{
						string seleccionA4;
						cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						cin >> seleccionA4;
						seleccionA4 = validarNumero(seleccionA4);
						if (seleccionA4 == "1")
						{
							cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
							cout << B->toString() << endl;
							ListaFichas* fichasJugada = new ListaFichas();
							int contador = 0;//contador de jugadas
							for (int y = 0; y < 13; y++) {
								cin >> entrada;
								entrada = validarLetra(entrada);
								convertirMayuscula(entrada);
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
										if (aux->getLetra() == entrada && contador > 0)
										{
											Fichas* aux2 = aux;
											cout << aux2->toString() << endl;
											fichasJugada->insertarFinal(aux2);

										}
										else

											if (aux->getLetra() != entrada)
											{
												cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
											}
								}



							}
							cout << fichasJugada->toString() << endl;

							if (fichasJugada != NULL)
							{
								delete entrante;
								entrante = new Palabra(fichasJugada);
								cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								char columna;
								cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								juegoPrincipal->retornaValor(columna);
								int eleccionColumna = juegoPrincipal->retornaValor(columna);
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
								
								if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								{

									juegoPrincipal->insertarFichasHorizontalFinal(eleccionColumna, fila, entrante);
									cout << juegoPrincipal->getTablero()->toString() << endl;
									string conAux = entrante->getLaPalabra();
									contenedor->insertarPalabra(conAux);
									perro = 6;
								}
								else 
									cout << "La palabra a agregar no existe, ha perdido su turno" << endl;
								perro = 6;
							}

						}
						else if (seleccionA4 == "2")
						{
							{
								 cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
								cout << B->toString() << endl;
								delete fichasJugada;
								fichasJugada = new ListaFichas();
								int contador = 0;//contador de jugadas
								for (int y = 0; y < 13; y++) {
									cin >> entrada;
									entrada=validarLetra(entrada);
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
											if (aux->getLetra() == entrada && contador > 0)
											{
												Fichas* aux2 = aux;
												cout << aux2->toString() << endl;
												fichasJugada->insertarFinal(aux2);

											}
											else

												if (aux->getLetra() != entrada)
												{
													cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
												}

									}



								}
								cout << fichasJugada->toString() << endl;
								delete entrante;
								if (fichasJugada != NULL)
								{

									entrante = new Palabra(fichasJugada);
									cout << "Digite la letra de la columna donde empezaria la palabra" << endl;
									char columna;
									cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									juegoPrincipal->retornaValor(columna);
									int eleccionColumna = juegoPrincipal->retornaValor(columna);
									cout << "Digite el numero de la fila donde empezaria la palabra" << endl;
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
									
									if (juegoPrincipal->verificarPalabra(entrante, 2) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									{

										if (juegoPrincipal->insertarFichasHorizontalInicio(eleccionColumna, fila, entrante) == true)
										{
											cout << juegoPrincipal->getTablero()->toString() << endl;
											string conAux = entrante->getLaPalabra();
											contenedor->insertarPalabra(conAux);
											perro = 6;
										}

									}
									else cout << "La palabra a agregar no existe, ha perdido su turno" << endl;
									perro = 6;
									
								}

							}

						}
					}
					else if (seleccionA3 == 2) 
						{
							{

						 string seleccionA4;
						 cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						 cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						 cin >> seleccionA4;
						 seleccionA4 = validarNumero(seleccionA4);
						 if (seleccionA4 == "1")
						 {
							 cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
							 cout << A->toString() << endl;
							 ListaFichas* fichasJugada = new ListaFichas();
							 int contador = 0;//contador de jugadas
							 for (int y = 0; y < 13; y++) {
								 cin >> entrada;
								 entrada = validarLetra(entrada);
								 convertirMayuscula(entrada);
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
										 if (aux->getLetra() == entrada && contador > 0)
										 {
											 Fichas* aux2 = aux;
											 cout << aux2->toString() << endl;
											 fichasJugada->insertarFinal(aux2);

										 }
										 else

											 if (aux->getLetra() != entrada)
											 {
												 cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
											 }

								 }



							 }
							 cout << fichasJugada->toString() << endl;

							 if (fichasJugada != NULL)
							 {
								 delete entrante;
								 entrante = new Palabra(fichasJugada);
								 cout << "Digite la letra de la columna donde quiere poner la palabra" << endl;
								 char columna;
								 cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
								 juegoPrincipal->retornaValor(columna);
								 int eleccionColumna = juegoPrincipal->retornaValor(columna);
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

								 if (juegoPrincipal->verificarPalabra(entrante, 2) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								 {

									 juegoPrincipal->insertarFichasVerticalFinal(eleccionColumna, fila, entrante);
									 string conAux = entrante->getLaPalabra();
									 contenedor->insertarPalabra(conAux);
									 cout << juegoPrincipal->getTablero()->toString() << endl;
									 zopilote = 6;
								 }
								 else
									 cout << "La palabra no existe, ha perdido su turno" << endl;
								 zopilote = 6;
							 }

						 }
						 else if (seleccionA4 == "2")
						 {
							 {
								 cout << "Por favor seleccione sus fichas uno por uno seguido de enter, y cuando termina presiona -->SD<--" << endl;
								 cout << A->toString() << endl;
								 delete fichasJugada;
								 fichasJugada = new ListaFichas();
								 int contador = 0;//contador de jugadas
								 for (int y = 0; y < 13; y++) {
									 cin >> entrada;
									 entrada = validarLetra(entrada);
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
											 if (aux->getLetra() == entrada && contador > 0)
											 {
												 Fichas* aux2 = aux;
												 cout << aux2->toString() << endl;
												 fichasJugada->insertarFinal(aux2);

											 }
											 else

												 if (aux->getLetra() != entrada)
												 {
													 cout << "La ficha digitada no existe, por favor intentelo de nuevo" << endl;
												 }

									 }



								 }
								 cout << fichasJugada->toString() << endl;
								 delete entrante;
								 if (fichasJugada != NULL)
								 {

									 entrante = new Palabra(fichasJugada);
									 cout << "Digite la letra de la columna donde empezaria la palabra" << endl;
									 char columna;
									 cin >> columna;//validaciones no puede ser numero, letra ni mayor a 13
									 juegoPrincipal->retornaValor(columna);
									 int eleccionColumna = juegoPrincipal->retornaValor(columna);
									 cout << "Digite el numero de la fila donde empezaria la palabra" << endl;
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
									 if (juegoPrincipal->verificarPalabra(entrante,2) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									 {

										 if (juegoPrincipal->insertarFichasVerticalInicio(eleccionColumna, fila, entrante) == true)
										 {
											 cout << juegoPrincipal->getTablero()->toString() << endl;
											 string conAux = entrante->getLaPalabra();
											 contenedor->insertarPalabra(conAux);
											 zopilote = 6;
										 }
										 else
											 cout << "La palabra no existe, ha perdido su turno" << endl;
										 zopilote = 6;

									 }

								 }

							 }

						 }
						}


						}




				}
				
		}
		else if (eleccionA == "2")
		{
			for (int i = 0; i < 7; i++)
			{
				num = 1 + rand() % (29 - 1);
				fichasB->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());
				FICHAS->fichaAleatoria(num)->getLetra()->utilizarFicha();

			}
			cout << juegoPrincipal->getB()->toString() << endl;
		}
		else
			if (eleccionA == "3")
			{
				perro = 6;
			}
			else if (eleccionA == "4")
			{
				perro = 6;
				gato = 'z';
			}
			else
				cout << "Ha digitado un caracter incorrecto por favor intentelo de nuevo" << endl;
	} while (perro<5);
	//<-------------TERMINA JUGADOR B;
	}while (gato== 'p');
	cout << tb->toString() << endl;
	if (juegoPrincipal->getA()->getPuntuacion() > juegoPrincipal->getB()->getPuntuacion()) 
	{
		cout << "El ganador de la partida fue: " << juegoPrincipal->getA()->getNombre() << endl;
	}
	else if (juegoPrincipal->getA()->getPuntuacion() < juegoPrincipal->getB()->getPuntuacion()) 
	{
		cout << "El ganador de la partida fue: " << juegoPrincipal->getB()->getNombre() << endl;
	}
	else if (juegoPrincipal->getA()->getPuntuacion() == juegoPrincipal->getB()->getPuntuacion()) 
	{
		
		cout << "La partida quedo empate" << endl;
	}
	system("PAUSE");
	ofstream puntajes;
	puntajes.open("PuntajePartidas.txt", std::ios_base::app);
	puntajes << juegoPrincipal->getA()->getNombre() << " -> Puntaje: " << juegoPrincipal->getA()->getPuntuacion() <<"/"<< endl;
	puntajes << juegoPrincipal->getB()->getNombre() << " -> Puntaje: " << juegoPrincipal->getB()->getPuntuacion() << "/"<<endl;
	puntajes.close();
	ofstream palabrasAcertadas("PalabrasAcertadas.txt", std::ios_base::app);
	for (int i1 = 0; i1 < 300; i1++) 
	{
		if (contenedor->getPalabra(i1) != "VACIO") 
		{
			palabrasAcertadas << contenedor->getPalabra(i1) << "/";
		}
	}
	palabrasAcertadas.close();
	FICHAS->~ListaFichas();
	fichasA->~ListaFichas();
	fichasB->~ListaFichas();
	fichasJugada->~ListaFichas();
	delete entrante;
	delete contenedor;
	diccionario->~Lista();
	delete diccionario;
	delete fichasJugada;
	delete juegoPrincipal;
	delete fichasA;
	delete fichasB;
	delete palabraAUX;
	delete FICHAS;
	}
	else if (w == "2"){
	cout << "Historial del juego" << endl;
	ifstream lectura;
	lectura.open("PuntajePartidas.txt");
	string lectura2;
	if (lectura.fail()) {
	cout << "Error cargando el archivo" << endl;
	system("PAUSE");

	}
	else{
		while (!lectura.eof()){
			getline(lectura, lectura2, '/');
			cout << lectura2 << endl;
		}
		system("PAUSE");
		lectura.close();
		}
	cout << "Historial de palabras" << endl;
	ifstream revisar;
	revisar.open("PalabrasAcertadas.txt");
	if (revisar.fail()) 
	{
		cout << "Error abriendo el archivo" << endl;
		system("PAUSE");

	}
	else
	{
		while (!revisar.eof()) 
		{
			getline(revisar, lectura2, '/');
			cout << lectura2 << endl;
		}
		system("PAUSE");
		revisar.close();
		}
	}
	else if (w == "3") {
	papaya = 'z';
	}
	else{
	papaya = 'p';
	}




	system("cls");
	
	
}while (papaya == 'p');

	return 0;
}
