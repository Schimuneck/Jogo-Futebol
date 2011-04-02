#include <string>
#include <iostream>
#include "Dimensoes.h"

#define LARGURA 10
#define COMPRIMENTO 80

using namespace std;

class Jogador
{
	private:
		BITMAP *imagem;
		BITMAP *campo;
		string nome;
		int direita, esquerda, baixo, cima;	
		int x, y;		

	public:
		Jogador(BITMAP *campo, string nome, int x, int y, int direita, int esquerda, int baixo, int cima);
		~Jogador();
		void mover();
		void desenhar();

};

Jogador::Jogador(BITMAP *campo, string nome, int x, int y, int direita, int esquerda, int baixo, int cima)
{
	this -> x = x;
	this -> y = y;
	this -> imagem = create_bitmap(LARGURA, COMPRIMENTO);
	this -> campo = campo;

	this -> nome = nome;
	this -> direita = direita;
	this -> esquerda = esquerda;
	this -> baixo = baixo;
	this -> cima = cima;

	desenhar();
}

Jogador::~Jogador()
{
	cout << "Limpando da memória objetos que não serão mais utilizados..." << "\n";
	destroy_bitmap(imagem);
}

void Jogador::desenhar()
{
	rectfill(imagem, 0, 0, LARGURA, COMPRIMENTO, makecol(255, 255, 255));
	draw_sprite(campo, imagem, x, y);	
}

void Jogador::mover()
{
	if( key[direita] && x < LIMITE_DIREITA )		
		x++;
	
	if( key[esquerda] && x > LIMITE_ESQUERDA )
		x--;

	if( key[baixo] && y < LIMITE_INFERIOR )
		y++;
	
	if( key[cima] && y > LIMITE_SUPERIOR )
		y--;

	desenhar();
}
