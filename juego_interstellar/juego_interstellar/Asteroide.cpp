#include "Asteroide.h"
#include"funciones.h"
Asteroide::Asteroide(int x, int y)
{
	this->x = x;
	this->y = y;
}
Asteroide::Asteroide(int x, int y,int dureza)
{
	this->x = x;
	this->y = y;
	this->dureza = dureza;
}

void Asteroide::dibujar()
{
	gotoxy(x, y); cout << "O";
}

void Asteroide::mover()
{
	color("marron");
	borrar();
	y++;
	if(y > 36) {
		borrar();
		eliminar();
	}
	dibujar();
}

void Asteroide::borrar()
{
	gotoxy(x, y); cout << " ";
}

void Asteroide::colision(Nave &nave) {
	color("marron");
	if (x >= nave.getX() && x<(nave.getX() + 7) && y>nave.getY()&&y<nave.getY()+5) {
		nave.setSalud(nave.getSalud() - 1);//disminuyo la salud
		//definir nuevas coordenadas del asteroide
		nave.dibujar_salud();
		nave.dibujar();
		nave.morir();
		eliminar();
		PlaySound(TEXT("sonidos/alerta1.wav"), NULL, SND_ASYNC);
	}
}
int Asteroide::getX()
{
	return x;
}

int Asteroide::getY()
{
	return y;
}

int Asteroide::getDureza()
{
	return dureza;
}

void Asteroide::setDureza(int dureza)
{
	this->dureza = dureza;
}

void Asteroide::eliminar()
{
	y = 4;
	x = rand() % 92 + 4;//numero aleatorio entre4 y 97 n
}
