#include "Asteroide_m.h"
#include <iostream>
#include "funciones.h"
//clase hija asteroide mediano//r
Asteroide_m::Asteroide_m(int x, int y, int dureza) :Asteroide(x, y, dureza)
{

}

void Asteroide_m::dibujar()
{
	if (dureza == 2) {
		gotoxy(x, y); cout <<		" __ ";
		gotoxy(x, y + 1); cout <<   "(__)";
	}
	else {
		gotoxy(x, y); cout << " __ ";
		gotoxy(x, y + 1); cout << "(XX)";
	}
}

void Asteroide_m::mover()
{
	borrar();
	y++;
	if (y > 36) {
		//borrar();
		eliminar();
	}
	dibujar();
}

void Asteroide_m::borrar()
{
	gotoxy(x, y); cout << "    ";
	gotoxy(x, y + 1); cout << "    ";
}

void Asteroide_m::eliminar()
{
	y = 4;
	x = rand() % 88 + 4;//numero aleatorio entre4 y 97
	dureza = 2;
}

void Asteroide_m::colision(Nave& nave) {
	if (
		(
			(x >= nave.getX() && x <= nave.getX() + 7) &&
			(y >= nave.getY() && y <= nave.getY() + 5)
			) ||
		(
			(x + 3 >= nave.getX() && x + 3 <= nave.getX() + 7) &&
			(y + 1 >= nave.getY() && y + 1 <= nave.getY() + 5)
			)
		) {
		nave.setSalud(nave.getSalud() - 2);//disminuyo la salud
		//definir nuevas coordenadas del asteroide
		borrar();
		eliminar();
		nave.dibujar_salud();
		nave.borrar();
		nave.dibujar();
		PlaySound(TEXT("sonidos/alerta1.wav"), NULL, SND_ASYNC);
		//nave.morir();
	}
}