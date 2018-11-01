#ifndef FICHAS_H
#define FICHAS_H
#include <string>
#include<sstream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Fichas
{
private:
	string letra;
	int valor;
	int totalFichas;
	int cantidadDisponible;
	
public:
	Fichas(string,string,string);
	string toString();
	string getLetra();
	int getCantidadDisponible();
	void setLetra(string);//para cuando sea ficha comodin;
	int getValor();
	void utilizarFicha();
	~Fichas();
};


#endif // !FICHAS_H