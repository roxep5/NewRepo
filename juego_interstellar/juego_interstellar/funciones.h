#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
//#include<funciones.h>
using namespace std;

//codifo de teclas para _getch
#define flecha_arriba 72
#define flecha_abajoi 80
#define flecha_izq 75
#define flecha_drha 77
#define SPACE_BAR 32
static void color(string color) {
    HANDLE Ventana;
    Ventana = GetStdHandle(STD_OUTPUT_HANDLE);
    int atributocolor=0;
    if (color == "marron") atributocolor = 6;
    else if (color == "gris")atributocolor = 8;
    else if (color == "azul")atributocolor = 9;
    else if (color == "verde")atributocolor = 10;
    else if (color == "cyan")atributocolor = 11;
    else if (color == "rojo")atributocolor = 12;
    else if (color == "amarillo")atributocolor = 14;
    else if (color == "blanco")atributocolor = 15;
    SetConsoleTextAttribute(Ventana, atributocolor);
}
static void gotoxy(int x, int y) {
    HANDLE ventana;
    ventana = GetStdHandle(STD_OUTPUT_HANDLE);//recupero ID(handle) de la ventana

    COORD cord;//estructura especial de coordenadas
    cord.X = x;
    cord.Y = y;
    //
    SetConsoleCursorPosition(ventana, cord);


}
static void ocultarCursor() {
    HANDLE ventana;
    ventana = GetStdHandle(STD_OUTPUT_HANDLE);//recupero ID(handle) de la ventana
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;//grosor del cursor de 1 a 100)
    cci.bVisible = false;
    SetConsoleCursorInfo(ventana, &cci);
}
static void listaASCII() {
    for (int i = 0; i < 255; i++) {
        cout << i << ": " << (char)i<<endl;
    }
}
static void dibujar_limites() {
    color("gris");
    //tamaño de la ventana: 100 columnas||40 filas
    //lineas horizontales
    for (int i = 3; i < 98; i++) {
        gotoxy(i, 3);
        cout << (char)205;
        gotoxy(i, 38);
        cout << (char)205;
    }
    //lineas verticales
    for (int i = 4; i < 38; i++) {
        gotoxy(2, i);
        cout << (char)186;
        gotoxy(98, i);
        cout << (char)186;
    }
    //esquinas
    gotoxy(2, 3);
    cout << (char)201;//arribas izquierda
    gotoxy(2, 38);//abajo a la izqueirda
    cout << (char)200;
    gotoxy(98, 3);
    cout << (char)187;//arriba derecha

    gotoxy(98, 38);
    cout << (char)188;//abajo derecha
}

static void dibuja_titulo(int x, int y) {
    color("azul");
    gotoxy(x, y);   cout << " __  __    _  ______  ______  ______  ______  _______  ______  ______  ___   _______  ______   ";
    gotoxy(x, y+1); cout << "|  ||  |  | ||      ||      ||    _ ||      ||       ||      ||      ||   | |   _   ||    _ |  ";
    gotoxy(x, y+2); cout << "|  ||   |_| ||_    _||   ___||   | |||   ___||  _____||_    _||   ___||   | |  | |  ||   | ||  ";
    gotoxy(x, y+3); cout << "|  ||       |  |  |  |  |___ |   |_|||  |___ | |_____   |  |  |  |___ |   | |  | |  ||   |_||_ ";
    gotoxy(x, y+4); cout << "|  ||  _    |  |  |  |   ___||    __  |  ___||_____  |  |  |  |   ___||   |_|_      ||    __  |";
    gotoxy(x, y+5); cout << "|  || | |   |  |  |  |  |___ |   |  | | |___  _____| |  |  |  |  |___ |       | _   ||   |  | |";
    gotoxy(x, y+6); cout << "|__||_|  |__|  |__|  |______||___|  |_|_____||_______|  |__|  |______||_______|| |__||___|  |_|";
}
static void dibuja_win(int x, int y) {
    gotoxy(x, y);   cout    << " __   __  _______  __   __    _     _  ___   __    _  __   __  ";
    gotoxy(x, y + 1); cout  << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  | |  | ";
    gotoxy(x, y + 2); cout  << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  | |  | ";
    gotoxy(x, y + 3); cout  << "|       ||  | |  ||  |_|  |  |       ||   | |       ||  | |  | ";
    gotoxy(x, y + 4); cout  << "|_     _||  |_|  ||       |  |       ||   | |  _    ||__| |__| ";
    gotoxy(x, y + 5); cout  << "  |   |  |       ||       |  |   _   ||   | | | |   | __   __  ";
    gotoxy(x, y + 6); cout  << "  |___|  |_______||_______|  |__| |__||___| |_|  |__||__| |__| ";
    PlaySound(TEXT("sonidos/you_win.wav"), NULL, SND_ASYNC);
}