#pragma once
#include"nave.h"
class Asteroide
{
protected://cambiamos la proteccion de los atributos para que sean accesibles por sus hijos
	int x;
	int y;
	int dureza;
public:
	//Asteroide();
	Asteroide(int, int);
	Asteroide(int, int,int);
	void dibujar();
	void mover();
	void borrar();
	void colision(Nave&);
	int getX();
	int getY();
	int getDureza();
	void setDureza(int);
	void eliminar();
};

