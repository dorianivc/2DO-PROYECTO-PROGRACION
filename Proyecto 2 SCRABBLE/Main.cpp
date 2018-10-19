#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <locale.h>
#include "ListaDiccionario.h"
#include "ContenedorFichas.h"
#include "ListaFichas.h"
#include <time.h>
#include "Tablero.h"
#include "Jugador.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "spanish");
	string aux1, aux2;
	ifstream dicionarioFisico;
	dicionarioFisico.open("diccionario.txt");
	Lista diccionario;//Lista de ListaDiccionario.h
	if (dicionarioFisico.fail())
	{
		cout << "Error al cargar diccionario de palabras" << endl;
	}
	else
		dicionarioFisico >> aux1;
	diccionario.insertarInicio(&aux1);
	cout << aux1 << endl;
	int cont = 1;
	while (!dicionarioFisico.eof()) 
	{
		dicionarioFisico >> aux1;
		diccionario.insertarInicio(&aux1);
		cout << aux1 << endl;
		cont++;
		
	}
	system("PAUSE");
	cout << "Contador del ciclo es: " << cont << endl;
	cout << "Probando lista" << endl;
	cout << "Contador de nodos: " << endl;
	cout << diccionario.cuentaNodos() << endl;
	system("PAUSE");

	dicionarioFisico.close();

   
		//Lectura de Fichas
	ListaFichas FICHAS;//<--------------------------------------LISTA DE FICHAS 
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
			FICHAS.insertarInicio(new Fichas(LETRA, VALOR, TOTALFICHAS));
			cout << LETRA << endl;
			cout << VALOR << endl;
			cout << TOTALFICHAS << endl;
	
		} 
	FICHAS.insertarInicio(new Fichas("COMODIN", "0", "2"));

		
		cout << "Contador de nodos: " << endl;
		cout << FICHAS.cuentaNodos() << endl;
		lecturaFichas.close();
		//<-----------------------FALTA LAS FICHAS EN BLANCO
		system("PAUSE");
		//<----------------------- Hacemos la lista de 7 fichas para darselas a cada jugador
		srand(time(NULL));
		ListaFichas* fichasA;
		ListaFichas* fichasB;
		fichasA = new ListaFichas();
		fichasB = new ListaFichas();
		int num;
		num= 1 + rand() % (29 - 1);
		for (int i = 0; i <7 ; i++) 
		{
			num = 1 + rand() % (29 - 1);
			fichasA->insertarInicio(FICHAS.fichaAleatoria(num)->getLetra());
			
		}

		for (int y = 0; y < 7; y++)
		{
			num = 1 + rand() % (29 - 1);
			fichasB->insertarInicio(FICHAS.fichaAleatoria(num)->getLetra());;

		}
/*
		cout << fichasA->toString() << endl;
		cout << fichasB->toString() << endl;
		system("PAUSE");
		//<------------------------------- Creo cada Jugador con sus fichas
		
		string nombre;
		cout << "Digite el nombre del Jugador 1 y presione ENTER dos veces" << endl;
		getline(cin, nombre);
		Jugador* A = new Jugador (nombre, fichasA);
		cin.ignore();
		cout << "Digite el nombre del Jugador 2 y presione ENTER dos veces" << endl;
		getline(cin, nombre);
		Jugador* B = new Jugador(nombre, fichasA);
		cin.ignore();
		cout << A->toString() << endl;
		cout << B->toString() << endl;
		Palabra* prueba;
		prueba = new Palabra(fichasA);
		A->setPalabra(prueba);
		cout << A->toString() << endl;*/

		Tablero* tb = new Tablero();
		cout << tb->toString() << endl;
		system("PAUSE");
	return 0;
}