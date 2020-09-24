#include "Disparo.h"
#include"funciones.h"
Disparo::Disparo()
{
}
Disparo::Disparo(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Disparo::mover()
{

	gotoxy(x, y); cout << " ";

	if (y > 4)y--;
	gotoxy(x, y); cout << "|";
}

void Disparo::setcoordenadas(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Disparo::borrar()
{
	gotoxy(x, y); cout << " ";
}

void Disparo::dibujar()
{
	color("cyan");
	gotoxy(x, y); cout << "|";
}

bool Disparo::fuera()
{
	if (y == 4)return true;
	else return false;
}

void Disparo::eliminar()
{
	y = 4;
}

int Disparo::getX()
{
	return x;
}

int Disparo::getY()
{
	return y;
}
