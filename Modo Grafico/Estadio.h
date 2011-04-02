#include "Dimensoes.h"

class Estadio
{

	private:
		BITMAP *buffer;			

	public:
		Estadio(BITMAP *buffer);
		void desenhar();

};

Estadio::Estadio(BITMAP *buffer)
{
	this -> buffer = buffer;
}

void Estadio::desenhar()
{
	rectfill(buffer, 0, 0, MAX_X, MAX_Y, makecol(0,204,0));			
	//rectfill(estadio, 0, 0, MAX_X, 5, makecol(255, 255, 255)); //Desenhar lateral
	//rectfill(estadio, 0, 400, MAX_X, 405, makecol(255, 255, 255)); //Desenhar lateral
}
