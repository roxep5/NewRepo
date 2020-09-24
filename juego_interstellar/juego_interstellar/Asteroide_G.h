#pragma once
#include"Asteroide.h"
class Asteroide_G :public Asteroide
{
public:
	Asteroide_G(int, int, int);//hereda sus coordenadas de la clase padre
	void dibujar(); //cambia, ahora va a ser mas grande
	void mover(); //cambia porque ahora al ser mas grande, sus coordenadas
	void borrar();
	void eliminar();
	void colision(Nave&);//cambia porque la region de colision es mayir
};

