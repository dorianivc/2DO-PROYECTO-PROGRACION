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
	~Fichas();
};


#endif // !FICHAS_H