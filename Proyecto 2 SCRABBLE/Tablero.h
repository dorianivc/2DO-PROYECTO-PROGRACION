#ifndef TABLERO_H
#define TABLERO_H
#include <sstream>
#include <string>
using namespace std;
class Tablero
{
private:
	string tablero[13][13];
public:
	Tablero();
	string toString();
	~Tablero();
};

#endif // !TABLERO_H