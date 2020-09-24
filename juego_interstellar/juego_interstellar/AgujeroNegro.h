#pragma once
#include "Nave.h"
class AgujeroNegro
{
private:
	int x;
	int y;
	bool izquierda;
public: 
	AgujeroNegro();
	void mover();
	void dibujar();
	void borrar();
	bool ganar(Nave&);
	void setCoordenadas(int, int);
	void setX(int);
	void setY(int);
	int getY();
	int getX();
};

