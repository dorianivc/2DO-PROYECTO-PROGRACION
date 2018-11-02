#ifndef COLECCIONPALABRAS_H
#define COLECCIONPALABRAS_H
#include <string>
using namespace std;
class ColeccionPalabras
{
private:
	string palabras[300];
public:
	ColeccionPalabras();
	void insertarPalabra(string &);
	string getPalabra(int);
	~ColeccionPalabras();
};
#endif // !COLECCIONPALABRAS_H

