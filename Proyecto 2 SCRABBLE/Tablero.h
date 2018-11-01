#ifndef TABLERO_H
#define TABLERO_H
#include <sstream>
#include "Palabra.h"
#include <string>
#include "ListaFichas.h"
using namespace std;
class Tablero
{
private:
	string tablero[13][13];
	ListaFichas* fichasConocidas;
public:
	Tablero();
	string getTablero(int, int);
	void setFichasConocidas(ListaFichas*);
	ListaFichas* getFichasConocidas();
	string toString();
	~Tablero();
	void insertarPalabraHorizontalInicio(Palabra*, int, int);
	void insertarPalabraVerticalInico(Palabra*, int, int);
	string getLetrasDeCasillas(int, int);
	bool verificarCasillas(int, int);
	bool verificadorEspacioDePalabraHorizontal(int, int, Palabra*);
	bool verificadorEspacioDePalabraVertical(int, int, Palabra*);
	void insertarLetrasInicioPalabraHorizontal(int, int, Palabra*);
	void insertarLetrasInicioPalabraVertical(int, int, Palabra*);
	string imprimeInstrucciones();
	
};

#endif // !TABLERO_H