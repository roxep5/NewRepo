#include "AgujeroNegro.h"
#include "funciones.h"

AgujeroNegro::AgujeroNegro()
{
    izquierda = true;
}

void AgujeroNegro::mover()
{
    color("blanco");
    borrar();
    
    if (x < 5&&izquierda==true) {
        izquierda = false;
        // x++;
    }
    else if (x > 74 && izquierda == false) {
        //borrar();
        izquierda = true;
    }
    if (izquierda) {
        x--;
    }
    else if (izquierda==false) {
        x++;
    }
    dibujar();
}

void AgujeroNegro::dibujar()

{
    //PlaySound(TEXT("sonidos/musica_agujeronegro.wav"), NULL, SND_ASYNC);
    color("blanco");

    gotoxy(x, y);     cout << "       " << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "       ";

    gotoxy(x, y + 1); cout << "     " << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "     ";

    gotoxy(x, y + 2); cout << (char)220 << (char)220 << (char)220 << (char)220 << (char)219 << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219 << (char)219 << (char)220 << (char)220 << (char)220 << (char)220;

    gotoxy(x, y + 3); cout << "     " << (char)219 << (char)219 << "      " << (char)219 << (char)219 << "     ";

    gotoxy(x, y + 4); cout << "       " << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "       ";
    gotoxy(x, y + 5); cout << "         "<< (char)254 <<"           ";
}

void AgujeroNegro::borrar()
{
     gotoxy(x, y);     cout <<  "                    ";

    gotoxy(x, y + 1); cout <<   "                    ";

    gotoxy(x, y + 2); cout << "                       ";

    gotoxy(x, y + 3); cout << "                    ";

    gotoxy(x, y + 4); cout << "                    ";
}

bool AgujeroNegro::ganar(Nave& nave)
{
    if (
        (
            (x >= nave.getX() && x <= nave.getX() + 7) &&
            (y >= nave.getY() && y <= nave.getY() + 5)
            ) ||
        (
            (x + 3 >= nave.getX() && x + 11 <= nave.getX() + 7) &&
            (y + 1 >= nave.getY() && y + 5 <= nave.getY() + 5)
            )
        ) {
        dibuja_win(30,20);
        return true;
    }
    return false;
}

void AgujeroNegro::setCoordenadas(int x, int y)
{
    setX(x);
    setY(y);
}

void AgujeroNegro::setX(int x)
{
    this->x = x;
}

void AgujeroNegro::setY(int y)
{
    this->y = y;
}

int AgujeroNegro::getY()
{
    return y;
}

int AgujeroNegro::getX()
{
    return x;
}

