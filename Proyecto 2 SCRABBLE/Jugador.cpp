#include "Jugador.h"

Jugador::Jugador(string NOMBRE, ListaFichas * FICHASDADAS)
{
	nombre = NOMBRE;
	sieteFichas = FICHASDADAS;
	laPalabra = NULL;
	puntuacion = 0;
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getPuntuacion()
{
	return puntuacion;
}

void Jugador::sumarPuntuacion(int PUNTOSGANADOS)
{
	puntuacion = +PUNTOSGANADOS;
}

Palabra * Jugador::getPalabra()
{
	return laPalabra;
}

void Jugador::setPalabra(Palabra * PALABRA)
{
	laPalabra = PALABRA;
}

ListaFichas * Jugador::getFichasJugador()
{
	return sieteFichas;
}

Jugador::~Jugador()
{
}
