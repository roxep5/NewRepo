#pragma once
class Disparo
{
private:
	int x;
	int y;
public:
	Disparo();
	Disparo(int, int);
	void mover();
	void setcoordenadas(int, int);
	void borrar();
	void dibujar();
	bool fuera();
	void eliminar();
	int getX();
	int getY();
};

