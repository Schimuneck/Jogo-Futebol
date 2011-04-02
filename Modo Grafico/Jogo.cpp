#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <allegro.h>

#include "Jogador.h"
#include "Bola.h"
#include "Estadio.h"
#include "Dimensoes.h"

#define COLOR_BITS    32
#define VIDEO_CARD    GFX_AUTODETECT_WINDOWED

using namespace std;

int inicia(void);
void principal(void);
void finaliza(void);

int main (void)
{
      if (!inicia())
      {
            finaliza();
            exit(-1);
      }

      principal();

      finaliza();
      exit(0);
}

int inicia (void)
{
      allegro_init();

      install_keyboard();

      set_color_depth(COLOR_BITS);
      if (set_gfx_mode(VIDEO_CARD, MAX_X, MAX_Y, 0, 0) < 0)
      {
     		printf("Erro ao inicializar o modo grafico");
      	return (FALSE);
      }

      return (TRUE);
}

void principal (void)
{
	BITMAP *buffer = create_bitmap(640,480);	
	
	Estadio estadio(buffer);
	Bola bola;		

	Jogador jogador1(buffer, "Rafael", 0, 0, KEY_RIGHT, KEY_LEFT, KEY_DOWN, KEY_UP);
	Jogador jogador2(buffer, "Matias", 200, 200, KEY_D, KEY_A, KEY_S, KEY_W);	

      while (!key[KEY_ESC])
      {
		estadio.desenhar();

		jogador1.mover();
		jogador2.mover();
				
		blit(buffer, screen, 0,0,0,0,640,480);
		clear_bitmap(buffer);
	}

	destroy_bitmap(buffer);
} 

void finaliza (void)
{
      allegro_exit();
}
