#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <locale.h>
#include "ListaDiccionario.h"
#include "ContenedorFichas.h"
#include "ListaFichas.h"
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
			

	return 0;
}