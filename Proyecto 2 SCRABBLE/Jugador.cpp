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
	puntuacion = puntuacion + PUNTOSGANADOS;
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

string Jugador::toString()
{
	stringstream p;
	p << "Nombre: " << nombre << endl;
	p << "Puntuacion: " << puntuacion << endl;
	if (laPalabra != NULL)
	{
		p << laPalabra->toString() << endl;
	}
	else
	{ 
		p << "Palabra: SIN PALABRA FORMADA AUN" << endl;
	}
	p << sieteFichas->toString() << endl;
	return p.str();
}

Jugador::~Jugador()
{
}
