#ifndef JUEGO_H
#define JUEGO_H
#include <fstream>
#include "ListaFichas.h"
#include "ListaDiccionario.h"
#include "Palabra.h"
#include "Tablero.h"
#include "Jugador.h"
#include "NodoFichas.h"
using  namespace std;
class Juego
{
	
	Jugador* A;
	Jugador* B;
	Tablero* tablero;
	Lista* Diccionario;
public:
	Juego(Jugador*, Jugador*, Tablero*, Lista*);
	ListaFichas* crearPrimeraPalabra(int);
	void JugarPrimeraParte();
	bool insertarFichasHorizontalInicio(int, int, Palabra*);
	bool insertarFichasVerticalInicio(int, int, Palabra*);
	//Este metodo es para ingresar fichas o palabras al inicio de otra palabra 
	//y verificar si la palabra es valida
	bool insertarFichasHorizontalFinal(int, int, Palabra*);//Aqui el usuario tiene que insertar donde iniciaria la palabra a la que le quiere insertar 1 o mas fichas
	bool insertarFichasVerticalFinal(int, int, Palabra*);
	int retornaValor(char letra);
	bool verificarPalabra(Palabra* , int );//Al usar este metodo validar para que solamente pueda digitar entre valores 1 y 2;
	Jugador* getA();
	Jugador* getB();
	Tablero* getTablero();
	Lista* getDiccionario();
	~Juego();
};

#endif // !1