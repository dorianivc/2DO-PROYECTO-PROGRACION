#ifndef NODO_H
#define NODO_H
#include <sstream>
#include <string>
using namespace std;
class Nodo
{
private:
	string* info;
	Nodo* siguiente;
public:
	Nodo(string*, Nodo*);
	void setInfo(string*);
	string* getInfo();
	void setSiguiente(Nodo*);
	Nodo* getSiguiente();
	string toStringNodo();

	~Nodo();
};
#endif
