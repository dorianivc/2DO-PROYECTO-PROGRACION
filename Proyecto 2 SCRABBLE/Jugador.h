#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "Palabra.h"
#include "ListaFichas.h"
using namespace std;
class Jugador
{
private:
	string nombre;
	int puntuacion;
	Palabra* laPalabra;
	ListaFichas * sieteFichas;
public:
	Jugador(string, ListaFichas*);
	string getNombre();
	int getPuntuacion();
	void sumarPuntuacion(int);
	Palabra* getPalabra();
	void setPalabra(Palabra*);
	ListaFichas* getFichasJugador();
	~Jugador();
};

#endif // !JUGADOR_H