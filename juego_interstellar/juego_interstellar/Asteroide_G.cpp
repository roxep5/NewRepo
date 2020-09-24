#include "Asteroide_G.h"
#include "funciones.h"

Asteroide_G::Asteroide_G(int x, int y, int dureza) :Asteroide(x, y, dureza)
{

}

void Asteroide_G::dibujar()
{
	color("verde");
	if (dureza <= 4&&dureza>2) {
		gotoxy(x, y); cout <<		" __---__ ";
		gotoxy(x, y + 1); cout <<	"|       |";
		gotoxy(x, y + 2); cout <<	"|       |";
		gotoxy(x, y + 3); cout <<	" --___-- ";
	}
	else if(dureza<=2){
		gotoxy(x, y); cout <<		" __---__ ";
		gotoxy(x, y + 1); cout <<	"|X X X X|";
		gotoxy(x, y + 2); cout <<	"| X X X |";
		gotoxy(x, y + 3); cout <<	" --___-- ";
	}
}

void Asteroide_G::mover()
{
	borrar();
	y++;
	if (y > 34) {
		//borrar();
		eliminar();
	}
	dibujar();
	
}

void Asteroide_G::borrar()
{

		gotoxy(x, y); cout << "         ";
		gotoxy(x, y + 1); cout << "         ";
		gotoxy(x, y + 2); cout << "         ";
		gotoxy(x, y + 3); cout << "         ";

}

void Asteroide_G::eliminar()
{
	y = 4;
	x = rand() % 84 + 4;//numero aleatorio entre4 y 97
	//dureza = 2;
}



void Asteroide_G::colision(Nave& nave)
{
	if (
		(
			(x >= nave.getX() && x <= nave.getX() + 7) &&
			(y >= nave.getY() && y <= nave.getY() + 5)
			) ||
		(
			(x + 3 >= nave.getX() && x + 8 <= nave.getX() + 7) &&
			(y + 1 >= nave.getY() && y + 4 <= nave.getY() + 5)
			)
		) {
		nave.setSalud(nave.getSalud() - 4);//disminuyo la salud
		//definir nuevas coordenadas del asteroide
		borrar();
		eliminar();
		nave.dibujar_salud();
		nave.borrar();
		nave.dibujar();
		PlaySound(TEXT("sonidos/alerta2.wav"), NULL, SND_ASYNC);
		//nave.morir();
	}
}
