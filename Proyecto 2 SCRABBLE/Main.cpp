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
using namespace std;

int main() {
	setlocale(LC_ALL, "spanish");
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
		fichasA->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());;


	}

	for (int y = 0; y < 7; y++)
	{
		num = 1 + rand() % (29 - 1);
		fichasB->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());;


	}



	//<------------------------------- Creo cada Jugador con sus fichas
	cout << "Bienvenidos a Scrabble." << endl;
	cout << "Este juego fue creado para jugar dos personas" << endl;
	cout << "Despues de desplegado el tablero, seguidamente van a tener un menu" << endl;
	cout << "1. Es para ingresar la ficha en el tablero, una vez escogida la letra que desea ingresar, digite La letra de la Columna y Fila para colocar las fichas" << endl;

	/*string nombre;
	cout << "Digite el nombre del Jugador 1 y presione ENTER dos veces" << endl;
	getline(cin, nombre);*/
	Jugador* A = new Jugador("nombre1", fichasA);
	/*cin.ignore();
	cout << "Digite el nombre del Jugador 2 y presione ENTER dos veces" << endl;
	getline(cin, nombre);*/
	Jugador* B = new Jugador("nombre2", fichasB);
	//cin.ignore();
	//<------------------------------------- Aqui una prueba de palabra;
	Palabra* palabraAUX = new Palabra(fichasA);

	//<------------------------------------- Ciclo de juego
	Juego* juegoPrincipal = new Juego(A, B, tb, diccionario);
	cout << tb->toString() << endl;
	//--->JUGUEMOS<---
	cout << "Empezaremos formando una palabra con sus fichas" << endl << "A continuacion usted presionara las letra que desea usar y presionara Enter" << endl << "Cuando termine escriba SD y presione Enter" << endl;
	cout << A->toString() << endl;
	string entrada, auxVerificarDiccionario;
	ListaFichas* fichasJugada = new ListaFichas();
	Palabra* entrante = new Palabra(fichasJugada);
	delete fichasJugada;
	fichasJugada = new ListaFichas();
	cout << A->toString() << endl;

	int contador = 0;//contador de jugadas

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

	if (fichasJugada != NULL)
	{
		delete entrante;
		entrante = new Palabra(fichasJugada);
		int verificador = 0;
		if (juegoPrincipal->verificarPalabra(entrante, 1) == true)
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
					cout << juegoPrincipal->getTablero()->toString();
					verificador = 1;
					entrada = 3;
				}
				else
					if (entrada == 2)
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
						cout << juegoPrincipal->getTablero()->toString();
						verificador = 1;
						entrada = 3;

					}



			} while (entrada > 3);
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
					int entrada;
					if (juegoPrincipal->verificarPalabra(entrante, 2) == true) {
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
								cout << juegoPrincipal->getTablero()->toString() << endl;
								verificador = 1;
								entrada = 3;
							}
							else
								if (entrada == 2)
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
									cout << juegoPrincipal->getTablero()->toString() << endl;
									verificador = 1;
									entrada = 3;

								}



						} while (entrada > 3);
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
	int eleccion12 = 0;
	do{
	cout << juegoPrincipal->getTablero()->toString() << endl;
	cout << "Es el turno de " << juegoPrincipal->getA()->getNombre() << endl;
	cout << juegoPrincipal->getA()->toString() << endl;
	cout << juegoPrincipal->getTablero()->imprimeInstrucciones() << endl;
	int eleccionA;
	do {
		cin >> eleccionA;
		if (eleccionA == 1)
		{
			cout << "Digite 1 si desea formar una palabra nueva" << endl;
			cout << "Digite 2 si desea formar una palabra nueva a base de otra palabra" << endl;
			int seleccionA1;
			cin >> seleccionA1;
			if (seleccionA1 == 1)
			{
				delete fichasJugada;
				fichasJugada = new ListaFichas();
				int contador = 0;//contador de jugadas
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

				if (fichasJugada != NULL)
				{
					delete entrante;
					entrante = new Palabra(fichasJugada);
					int verificador = 0;
					if (juegoPrincipal->verificarPalabra(entrante, 1) == true)
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
								eleccionA = 12;
								if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraHorizontal(eleccionColumna, fila, entrante) == true)
								{
									juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
									A->setPalabra(entrante);
									int p = entrante->getValorTotal();
									A->sumarPuntuacion(p);
									cout << juegoPrincipal->getTablero()->toString();
									verificador = 1;
									entrada = 3;
									
								}
								else
									cout << "La palabra no cabe, ha perdido su turno" << endl;
								entrada = 3;
							}
							else
								if (entrada == 2)
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
										cout << juegoPrincipal->getTablero()->toString();
										verificador = 1;
										entrada = 3;
										
									}
									else
										cout << "La palabra no cabe, ha perdido su turno" << endl;
									entrada = 3;
								}



						} while (entrada > 3);
					}
					else
						if (juegoPrincipal->verificarPalabra(entrante, 1) == false)
						{
							cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
							system("PAUSE");
							system("cls");
						}
				}
			}
			else
				if (seleccionA1 == 2)
				{
					cout << "Presione 1 si desea agregar la palabra de forma Horizontal" << endl;
					cout << "Presione 2 si desea agregar la palabra de forma Vertical" << endl;
					int seleccionA3;
					cin >> seleccionA3;
					if (seleccionA3 == 1)
					{
						int seleccionA4;
						cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						cin >> seleccionA4;
						if (seleccionA4 == 1)
						{
							cout << "Por favor seleccione sus fichas" << endl;
							cout << A->toString() << endl;
							ListaFichas* fichasJugada1 = new ListaFichas();
							int contador = 0;//contador de jugadas
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
										fichasJugada1->insertarInicio(aux3);

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
												fichasJugada1->insertarFinal(aux2);

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
								eleccionA = 12;
								if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								{

									juegoPrincipal->insertarFichasHorizontalFinal(eleccionColumna, fila, entrante);
									cout << juegoPrincipal->getTablero()->toString() << endl;
								}
								else
									cout << "La palabra no existe, ha perdido su turno" << endl;
								
							}

						}
						else if (seleccionA4 == 2)
						{
							{
								cout << "Por favor seleccione sus fichas" << endl;
								cout << A->toString() << endl;
								delete fichasJugada;
								fichasJugada = new ListaFichas();
								int contador = 0;//contador de jugadas
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
									eleccionA = 12;
									if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									{

										if (juegoPrincipal->insertarFichasHorizontalInicio(eleccionColumna, fila, entrante) == true)
										{
											cout << juegoPrincipal->getTablero()->toString() << endl;
										}
										else
											cout << "La palabra no existe, ha perdido su turno" << endl;
										

									}
									
								}

							}

						}
					}




				}
		}
		else if (eleccionA == 2)
		{
			for (int i = 0; i < 7; i++)
			{
				num = 1 + rand() % (29 - 1);
				fichasA->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());

			}
			cout << juegoPrincipal->getA()->toString() << endl;
		}
		else
			if (eleccionA == 3)
			{
				eleccionA = 5;
			}
			else if (eleccionA == 4)
			{
				eleccionA = 6;
				eleccion12 = 700;
			}
			else 
				cout << "Ha digitado un caracter incorrecto por favor intentelo de nuevo" << endl;
	}while (eleccionA < 4);

	//<-----------TERMINA JUGADOR A;

	//<-----------EMPIEZA JUGADOR B;

	cout << juegoPrincipal->getTablero()->toString() << endl;
	cout << "Es el turno de " << juegoPrincipal->getB()->getNombre() << endl;
	cout << juegoPrincipal->getB()->toString() << endl;
	cout << juegoPrincipal->getTablero()->imprimeInstrucciones() << endl;
	do {
		cin >> eleccionA;
		if (eleccionA == 1)
		{
			cout << "Digite 1 si desea formar una palabra nueva" << endl;
			cout << "Digite 2 si desea formar una palabra nueva a base de otra palabra" << endl;
			int seleccionA1;
			cin >> seleccionA1;
			if (seleccionA1 == 1)
			{
				delete fichasJugada;
				fichasJugada = new ListaFichas();
				int contador = 0;//contador de jugadas
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

				if (fichasJugada != NULL)
				{
					delete entrante;
					entrante = new Palabra(fichasJugada);
					int verificador = 0;
					if (juegoPrincipal->verificarPalabra(entrante, 2) == true)
					{

						cout << "La palabra es valida, por favor digite ----> 1<---- si desea agregar la palabra en forma horizontal" << endl;
						cout << "Digite ---->2<---- si desea poner la palabra en forma vertical" << endl;
						int entrada;
						B->setPalabra(entrante);
						do {
							cin >> entrada;
							if (entrada == 1)
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
								entrada = 3;
								if (juegoPrincipal->getTablero()->verificadorEspacioDePalabraHorizontal(eleccionColumna, fila, entrante) == true)
								{
									juegoPrincipal->getTablero()->insertarPalabraHorizontalInicio(entrante, eleccionColumna, fila - 1);
									int p = entrante->getValorTotal();
									A->sumarPuntuacion(p);
									cout << juegoPrincipal->getTablero()->toString();
									verificador = 1;
									entrada = 3;
								}
								else 
									cout << "La no cabe, ha perdido su turno" << endl;
							}
							else
								if (entrada == 2)
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
										cout << juegoPrincipal->getTablero()->toString();
										verificador = 1;
										entrada = 3;
									}
									else
										cout << "La no cabe, ha perdido su turno" << endl;
								}



						} while (entrada > 3);
					}
					else
						if (juegoPrincipal->verificarPalabra(entrante, 1) == false)
						{
							cout << "Lo siento su palabra no esta en el diccionario, ha perdido su turno" << endl;
							system("PAUSE");
							system("cls");
						}
				}
			}
			else
				if (seleccionA1 == 2)
				{
					cout << "Presione 1 si desea agregar la palabra de forma Horizontal" << endl;
					cout << "Presione 2 si desea agregar la palabra de forma Vertical" << endl;
					int seleccionA3;
					cin >> seleccionA3;
					if (seleccionA3 == 1)
					{
						int seleccionA4;
						cout << "Digite 1 si desea insertar las fichas al final de la palabra" << endl;
						cout << "Digite 2 si desea insertar las fichas al inicio de la palabra" << endl;
						cin >> seleccionA4;
						if (seleccionA4 == 1)
						{
							cout << "Por favor seleccione sus fichas" << endl;
							cout << B->toString() << endl;
							ListaFichas* fichasJugada1 = new ListaFichas();
							int contador = 0;//contador de jugadas
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
										fichasJugada1->insertarInicio(aux3);

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
												fichasJugada1->insertarFinal(aux2);

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
								eleccionA = 7;
								if (juegoPrincipal->verificarPalabra(entrante, 1) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
								{

									juegoPrincipal->insertarFichasHorizontalFinal(eleccionColumna, fila, entrante);
									cout << juegoPrincipal->getTablero()->toString() << endl;
								}
								else 
									cout << "La palabra a agregar no existe, ha perdido su turno" << endl;
								
							}

						}
						else if (seleccionA4 == 2)
						{
							{
								cout << "Por favor seleccione sus fichas" << endl;
								cout << B->toString() << endl;
								delete fichasJugada;
								fichasJugada = new ListaFichas();
								int contador = 0;//contador de jugadas
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
									eleccionA = 7;
									if (juegoPrincipal->verificarPalabra(entrante, 2) == true)//verificar revisa si esta en el diccionario y elimina las fichas de la lista del jugador
									{

										if (juegoPrincipal->insertarFichasHorizontalInicio(eleccionColumna, fila, entrante) == true)
										{
											cout << juegoPrincipal->getTablero()->toString() << endl;
										}

									}
									else cout << "La palabra a agregar no existe, ha perdido su turno" << endl;
									
								}

							}

						}
					}




				}
				
		}
		else if (eleccionA == 2)
		{
			for (int i = 0; i < 7; i++)
			{
				num = 1 + rand() % (29 - 1);
				fichasB->insertarInicio(FICHAS->fichaAleatoria(num)->getLetra());

			}
			cout << juegoPrincipal->getB()->toString() << endl;
		}
		else
			if (eleccionA == 3)
			{
				eleccionA = 5;
			}
			else if (eleccionA == 4)
			{
				eleccionA = 6;
				eleccion12=5;
			}
			else
				cout << "Ha digitado un caracter incorrecto por favor intentelo de nuevo" << endl;
	} while (eleccionA < 4);
	//<-------------TERMINA JUGADOR B;
	}while (eleccion12 == 0);
	cout << tb->toString() << endl;
	system("PAUSE");
	delete entrante;
	fichasA->~ListaFichas();
	fichasB->~ListaFichas();
	FICHAS->~ListaFichas();
	diccionario->~Lista();
	delete fichasJugada;
	delete juegoPrincipal;
	delete fichasA;
	delete fichasB;
	delete diccionario;
	delete palabraAUX;
	delete FICHAS;

	return 0;
}