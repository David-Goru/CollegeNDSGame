#include <nds.h>
#include <stdio.h>
#include "portada_1.h"
#include "portada_2.h"
#include "gameOver.h"
#include "win.h"

// Tesela de la tierra (número 1)
u8 tierra[64] =
{
    1,1,1,1,1,2,1,1,
    1,2,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,2,1,1,2,
    1,1,1,1,1,1,1,1,
    2,1,1,1,1,1,1,1,
    1,1,1,1,1,2,1,1,
};

// Teselas de la acequia
// Acequia izquierda/derecha (número 2)
u8 acequia_id[64] =
{
	1,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,2,
    1,3,3,3,3,3,3,1,
    2,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,1,
};
// Acequia arriba/abajo (número 3)
u8 acequia_aa[64] =
{
    1,1,1,1,1,2,1,1,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    1,1,1,1,1,2,1,1,
};
// Acequia esquina superior izquierda (número 4)
u8 acequia_esi[64] =
{
    1,1,1,1,1,2,1,1,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    2,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,1,
};
// Acequia esquina superior derecha (número 5)
u8 acequia_esd[64] =
{
    1,1,1,1,1,2,1,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,2,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,1,
};
// Acequia esquina inferior izquierda (número 6)
u8 acequia_eii[64] =
{
    1,3,3,3,3,3,3,1,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    1,3,3,3,3,3,3,3,
    2,3,3,3,3,3,3,3,
    1,1,1,1,1,2,1,1,
};
// Acequia esquina inferior derecha (número 7)
u8 acequia_eid[64] =
{
    1,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,2,
    3,3,3,3,3,3,3,1,
    3,3,3,3,3,3,3,1,
    1,1,1,1,1,2,1,1,
};

// Objetos
// Piedra
// Izquierda (número 8)
u8 piedra_izq[64] =
{
	1,1,1,1,1,2,2,2,
	1,2,1,2,2,2,2,2,
	1,1,1,2,2,2,2,2,
	1,1,2,2,2,2,2,2,
	1,1,2,2,2,2,2,2,
	1,1,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};
// Derecha (número 9)
u8 piedra_der[64] =
{
	2,1,1,1,1,2,1,1,
	2,2,1,1,1,1,1,1,
	2,2,2,2,1,1,1,1,
	2,2,2,2,1,1,1,1,
	2,2,2,2,2,1,1,2,
	2,2,2,2,2,2,2,1,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

// Planta
// Izquierda (número 10)
u8 planta_izq[64] =
{
    1,1,1,1,1,5,1,1,
    1,2,1,1,1,10,1,1,
    1,1,5,1,1,10,1,1,
    5,1,10,1,1,10,1,5,
    10,1,10,1,2,10,1,10,
    10,10,10,10,5,10,10,10,
    10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,
};
// Derecha (número 11)
u8 planta_der[64] =
{
    1,1,1,1,1,2,1,1,
    1,2,1,5,1,1,1,1,
    1,5,1,10,1,1,1,1,
    1,10,1,10,1,1,5,1,
    10,10,1,10,5,1,10,2,
    10,10,10,10,10,10,10,1,
    10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,
};

// Personajes
// Timmy (12, 13, 14, 15)
u8 timmy_1[64] =
{
	1,1,1,1,1,2,5,5,
	1,2,1,1,1,5,4,4,
	1,1,1,1,5,4,7,4,
	1,1,1,1,4,4,4,4,
	1,1,1,1,2,4,4,6,
	1,1,1,1,1,1,1,4,
	2,1,1,1,1,1,2,4,
	1,1,1,1,1,4,2,2,
};
u8 timmy_2[64] =
{
	5,5,1,1,1,2,1,1,
	4,4,5,1,1,1,1,1,
	4,7,4,5,1,1,1,1,
	4,4,4,4,1,1,1,1,
	6,4,4,1,2,1,1,2,
	4,1,1,1,1,1,1,1,
	4,2,1,1,1,1,1,1,
	2,2,4,1,1,2,1,1,
};
u8 timmy_3[64] =
{
	1,1,1,1,4,2,2,2,
	1,2,1,1,4,2,2,2,
	1,1,1,1,1,2,2,2,
	1,1,1,1,1,2,2,2,
	1,1,1,1,2,3,3,3,
	1,1,1,1,1,3,3,1,
	2,1,1,1,2,2,2,1,
	1,1,1,2,2,2,2,1,
};
u8 timmy_4[64] =
{
	2,2,2,4,1,2,1,1,
	2,2,2,4,1,1,1,1,
	2,2,2,1,1,1,1,1,
	2,2,2,1,1,1,1,1,
	3,3,3,1,2,1,1,2,
	1,3,3,1,1,1,1,1,
	2,2,2,2,1,1,1,1,
	1,2,2,2,2,2,1,1,
};
// Annie (16, 17, 18, 19)
u8 annie_1[64] =
{
	1,1,1,1,6,6,6,7,
	1,2,1,1,6,8,4,4,
	1,1,1,1,6,4,6,4,
	1,1,1,1,4,4,7,4,
	1,1,1,1,7,4,4,4,
	1,1,1,1,7,7,7,4,
	2,1,1,1,7,7,8,8,
	1,1,1,1,1,4,8,8,
};
u8 annie_2[64] =
{
	7,6,6,6,1,2,1,1,
	4,4,8,6,1,1,1,1,
	4,6,4,6,1,1,1,1,
	4,7,4,4,1,1,1,1,
	4,4,4,7,2,1,1,2,
	4,7,7,7,1,1,1,1,
	8,8,7,7,1,1,1,1,
	8,8,4,1,1,2,1,1,
};
u8 annie_3[64] =
{
	1,1,1,1,4,8,8,8,
	1,2,1,1,4,8,8,8,
	1,1,1,1,8,8,8,8,
	1,1,1,8,8,8,8,8,
	1,1,8,8,8,8,8,8,
	1,1,1,1,1,4,4,1,
	2,1,1,1,7,7,7,1,
	1,1,1,7,7,7,7,1,
};
u8 annie_4[64] =
{
	8,8,8,4,1,2,1,1,
	8,8,8,4,1,1,1,1,
	8,8,8,8,1,1,1,1,
	8,8,8,8,8,1,1,1,
	8,8,8,8,8,8,1,2,
	1,4,4,1,1,1,1,1,
	2,7,7,7,1,1,1,1,
	1,7,7,7,7,2,1,1,
};
// Johnny (20, 21, 22, 23)
u8 johnny_1[64] =
{
	1,1,1,1,1,6,6,6,
	1,2,1,1,6,6,4,4,
	1,1,1,1,6,4,7,4,
	1,1,1,1,4,4,6,4,
	1,1,1,1,2,4,4,4,
	1,1,1,1,1,1,1,4,
	2,1,1,1,1,1,7,7,
	1,1,1,1,1,4,7,7,
};
u8 johnny_2[64] =
{
	6,6,6,1,1,2,1,1,
	4,4,6,6,1,1,1,1,
	4,7,4,6,1,1,1,1,
	4,6,4,4,1,1,1,1,
	4,4,4,1,2,1,1,2,
	4,1,1,1,1,1,1,1,
	7,7,1,1,1,1,1,1,
	7,7,4,1,1,2,1,1,
};
u8 johnny_3[64] =
{
	1,1,1,1,4,7,7,7,
	1,2,1,1,4,7,7,7,
	1,1,1,1,1,7,7,7,
	1,1,1,1,1,7,7,7,
	1,1,1,1,2,3,3,3,
	1,1,1,1,1,3,3,1,
	2,1,1,1,2,2,2,1,
	1,1,1,2,2,2,2,1,
};
u8 johnny_4[64] =
{
	7,7,7,4,1,2,1,1,
	7,7,7,4,1,1,1,1,
	7,7,7,1,1,1,1,1,
	7,7,7,1,1,1,1,1,
	3,3,3,1,2,1,1,2,
	1,3,3,1,1,1,1,1,
	2,2,2,2,1,1,1,1,
	1,2,2,2,2,2,1,1,
};
// Lisa (24, 25, 26, 27)
u8 lisa_1[64] =
{
	1,1,1,1,9,9,9,9,
	1,2,1,1,9,9,4,4,
	1,1,1,1,9,4,7,4,
	1,1,1,1,4,4,6,4,
	1,1,1,1,9,4,4,4,
	1,1,1,1,9,9,9,4,
	2,1,1,1,9,9,3,3,
	1,1,1,1,9,4,3,3,
};
u8 lisa_2[64] =
{
	9,9,9,9,1,2,1,1,
	4,4,9,9,1,1,1,1,
	4,7,4,9,1,1,1,1,
	4,6,4,4,1,1,1,1,
	4,4,4,9,2,1,1,2,
	4,9,9,9,1,1,1,1,
	3,3,9,9,1,1,1,1,
	3,3,8,9,1,2,1,1,
};
u8 lisa_3[64] =
{
	1,1,1,1,4,3,3,3,
	1,2,1,1,4,3,8,8,
	1,1,1,1,1,8,3,3,
	1,1,1,1,1,5,5,5,
	1,1,1,1,2,5,5,5,
	1,1,1,1,1,5,5,1,
	2,1,1,1,7,7,7,1,
	1,1,1,7,7,7,7,1,
};
u8 lisa_4[64] =
{
	8,8,3,4,1,2,1,1,
	3,3,3,4,1,1,1,1,
	3,3,3,1,1,1,1,1,
	5,5,5,1,1,1,1,1,
	5,5,5,1,2,1,1,2,
	1,5,5,1,1,1,1,1,
	2,7,7,7,1,1,1,1,
	1,7,7,7,7,2,1,1,
};
// Alex (28, 29, 30, 31)
u8 alex_1[64] =
{
	1,1,1,1,1,7,7,7,
	1,2,1,1,7,7,4,4,
	1,1,1,7,7,4,7,4,
	1,1,1,7,4,4,6,4,
	1,1,1,7,7,4,4,4,
	1,1,1,1,1,1,1,4,
	2,1,1,1,1,1,2,4,
	1,1,1,1,1,4,2,2,
};
u8 alex_2[64] =
{
	7,7,7,1,1,2,1,1,
	4,4,7,7,1,1,1,1,
	4,7,4,7,7,1,1,1,
	4,6,4,4,7,1,1,1,
	4,4,4,7,7,1,1,2,
	4,1,1,1,1,1,1,1,
	4,2,1,1,1,1,1,1,
	2,2,4,1,1,2,1,1,
};
u8 alex_3[64] =
{
	1,1,1,1,4,2,2,2,
	1,2,1,1,4,2,2,2,
	1,1,1,1,1,2,2,2,
	1,1,1,1,1,4,4,4,
	1,1,1,1,2,3,3,3,
	1,1,1,1,1,3,3,1,
	2,1,1,1,7,7,7,1,
	1,1,1,7,7,7,7,1,
};
u8 alex_4[64] =
{
	2,2,2,4,1,2,1,1,
	2,2,2,4,1,1,1,1,
	2,2,2,1,1,1,1,1,
	4,4,4,1,1,1,1,1,
	3,3,3,1,2,1,1,2,
	1,3,3,1,1,1,1,1,
	2,7,7,7,1,1,1,1,
	1,7,7,7,7,2,1,1,
};
// Jackie (32, 33, 34, 35)
u8 jackie_1[64] =
{
	1,1,1,1,1,1,1,1,
	1,2,1,1,1,1,4,4,
	1,1,1,1,1,4,7,4,
	1,1,1,1,4,4,6,4,
	1,1,1,1,2,4,4,4,
	1,1,1,1,1,1,1,4,
	2,1,1,1,1,1,1,4,
	1,1,1,1,1,4,1,1,
};
u8 jackie_2[64] =
{
	1,1,1,1,1,2,1,1,
	4,4,1,1,1,1,1,1,
	4,7,4,1,1,1,1,1,
	4,6,4,4,1,1,1,1,
	4,4,4,1,2,1,1,2,
	4,1,1,1,1,1,1,1,
	4,1,1,1,1,1,1,1,
	1,1,4,1,1,2,1,1,
};
u8 jackie_3[64] =
{
	1,1,1,1,4,1,1,1,
	1,2,1,1,4,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,2,1,1,1,
	1,1,1,1,1,4,4,1,
	2,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
};
u8 jackie_4[64] =
{
	1,1,1,4,1,2,1,1,
	1,1,1,4,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,2,1,1,2,
	1,4,4,1,1,1,1,1,
	2,1,1,1,1,1,1,1,
	1,1,1,1,1,2,1,1,
};

// Otros
// Oscuro (36)
u8 oscuro[64] =
{
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
	7,7,7,7,7,7,7,7,
};
// Claro (37)
u8 claro[64] =
{
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
};

// Mapa in-game
u16 mapDataMapa[768] =
{
	4,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,  3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,5,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,

	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,10,11,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,8,9,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,

	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,10,11,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,8,9, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,

	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,

	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,8,9,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,

	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,10,11,1,1, 1,1,1,1,1,1,1,2,
	2,1,10,11,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,2,
	6,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,  3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,7
};

// Declaración de métodos
void InicializarPartida();
void ConfigurarInterrupciones();
void DetectarBotones();
void BorrarPantallaSuperior();
void ConstruirMapaInferior();
void ModoFramebuffer();
void ModoTeselas();

// Declaración variables
static u8*  tileMemory;
static u16* mapMemory;
int estado_juego;
int imagenActual; // 0 = portada, 1 = win, 2 = gameOver

int main( void )
{
	imagenActual = 0;

	// Iniciamos el juego
	//ModoTeselas();
	ModoFramebuffer();

	REG_DISPCNT = MODE_FB0;

	// Colocamos el texto en la parte superior
	consoleDemoInit();
	iprintf("\x1b[12;5HPulsa A para empezar");

	// Establecemos variables básicas
	estado_juego = 0; // 0 para principio, 1 para jugando, 2 para derrota/victoria

	// Llamamos a ConfigurarInterrupciones
	ConfigurarInterrupciones();

	while(1)
	{
		if (imagenActual == 1)
		{
			iprintf("\x1b[12;5H¡Has ganado! Pulsa A para repetir");
			REG_DISPCNT = MODE_FB1 ;
			ModoFramebuffer();
		}
		else if (imagenActual == 2)
		{
			iprintf("\x1b[12;5H¡Has perdido :(! Pulsa A para repetir");
			REG_DISPCNT = MODE_FB2 ;
			ModoFramebuffer();
		}
		swiWaitForVBlank();
	}
}


void ModoFramebuffer()
{
	REG_POWERCNT = POWER_LCD | POWER_2D_A ;

	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD ;
	dmaCopy (portada_1Bitmap, VRAM_A , 256*192*2) ; // Portada 1 = FB0

	VRAM_B_CR = VRAM_ENABLE | VRAM_B_LCD ;
	dmaCopy (portada_2Bitmap, VRAM_B , 256*192*2) ; // Portada 2 = FB1

	VRAM_C_CR = VRAM_ENABLE | VRAM_C_LCD ;
	dmaCopy (winBitmap, VRAM_C , 256*192*2) ; // Win = FB2

	VRAM_D_CR = VRAM_ENABLE | VRAM_D_LCD ;
	dmaCopy (gameOverBitmap , VRAM_D , 256*192*2) ; // GameOver = FB3
}

void ModoTeselas()
{
	// Inicialización del motor de gráficos
	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT  = MODE_0_2D | DISPLAY_BG0_ACTIVE ;
	VRAM_A_CR    = VRAM_ENABLE | VRAM_A_MAIN_BG ;
	BGCTRL [0]   = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	tileMemory = (u8*)  BG_TILE_RAM(1);
	mapMemory  = (u16*) BG_MAP_RAM(0);

	// Inicializamos colores
	BG_PALETTE[1]=RGB15(8,5,0); // Marrón
	BG_PALETTE[2]=RGB15(17,18,18); // Gris
	BG_PALETTE[3]=RGB15(7,8,17); // Azul
	BG_PALETTE[4]=RGB15(25,19,13); // Carne
	BG_PALETTE[5]=RGB15(21,2,2); // Rojo
	BG_PALETTE[6]=RGB15(31,31,31); // Blanco
	BG_PALETTE[7]=RGB15(0,0,0); // Negro
	BG_PALETTE[8]=RGB15(25,9,20); // Rosa
	BG_PALETTE[9]=RGB15(31,25,1); // Amarillo
	BG_PALETTE[10]=RGB15(5,15,0); // Verde

	// Inicializamos teselas
	dmaCopy(tierra,tileMemory + 64,  sizeof(tierra));
	dmaCopy(acequia_id,tileMemory + 128,  sizeof(acequia_id));
	dmaCopy(acequia_aa,tileMemory + 192,  sizeof(acequia_aa));
	dmaCopy(acequia_esi,tileMemory + 256,  sizeof(acequia_esi));
	dmaCopy(acequia_esd,tileMemory + 320,  sizeof(acequia_esd));
	dmaCopy(acequia_eii,tileMemory + 384,  sizeof(acequia_eii));
	dmaCopy(acequia_eid,tileMemory + 448,  sizeof(acequia_eid));
	dmaCopy(piedra_izq,tileMemory + 512,  sizeof(piedra_izq));
	dmaCopy(piedra_der,tileMemory + 576,  sizeof(piedra_der));
	dmaCopy(planta_izq,tileMemory + 640,  sizeof(planta_izq));
	dmaCopy(planta_der,tileMemory + 704,  sizeof(planta_der));
	dmaCopy(timmy_1,tileMemory + 768,  sizeof(timmy_1));
	dmaCopy(timmy_2,tileMemory + 832,  sizeof(timmy_2));
	dmaCopy(timmy_3,tileMemory + 896,  sizeof(timmy_3));
	dmaCopy(timmy_4,tileMemory + 960,  sizeof(timmy_4));
	dmaCopy(annie_1,tileMemory + 1024,  sizeof(annie_1));
	dmaCopy(annie_2,tileMemory + 1088,  sizeof(annie_2));
	dmaCopy(annie_3,tileMemory + 1152,  sizeof(annie_3));
	dmaCopy(annie_4,tileMemory + 1216,  sizeof(annie_4));
	dmaCopy(johnny_1,tileMemory + 1280,  sizeof(johnny_1));
	dmaCopy(johnny_2,tileMemory + 1344,  sizeof(johnny_2));
	dmaCopy(johnny_3,tileMemory + 1408,  sizeof(johnny_3));
	dmaCopy(johnny_4,tileMemory + 1472,  sizeof(johnny_4));
	dmaCopy(lisa_1,tileMemory + 1536,  sizeof(lisa_1));
	dmaCopy(lisa_2,tileMemory + 1600,  sizeof(lisa_2));
	dmaCopy(lisa_3,tileMemory + 1664,  sizeof(lisa_3));
	dmaCopy(lisa_4,tileMemory + 1728,  sizeof(lisa_4));
	dmaCopy(alex_1,tileMemory + 1792,  sizeof(alex_1));
	dmaCopy(alex_2,tileMemory + 1856,  sizeof(alex_2));
	dmaCopy(alex_3,tileMemory + 1920,  sizeof(alex_3));
	dmaCopy(alex_4,tileMemory + 1984,  sizeof(alex_4));
	dmaCopy(jackie_1,tileMemory + 2048,  sizeof(jackie_1));
	dmaCopy(jackie_2,tileMemory + 2112,  sizeof(jackie_2));
	dmaCopy(jackie_3,tileMemory + 2176,  sizeof(jackie_3));
	dmaCopy(jackie_4,tileMemory + 2240,  sizeof(jackie_4));
	dmaCopy(oscuro,tileMemory + 2304,  sizeof(oscuro));
	dmaCopy(claro,tileMemory + 2368,  sizeof(claro));
}

void InicializarPartida()
{
	estado_juego = 1;
	BorrarPantallaSuperior();
	ModoTeselas();
	ConstruirMapaInferior();
	iprintf("\x1b[12;5HJugando");
}

void ConfigurarInterrupciones()
{
	irqSet(IRQ_KEYS, DetectarBotones);
	irqEnable(IRQ_KEYS);

	REG_KEYCNT    = 0x40F3;
}

void DetectarBotones()
{
	if (estado_juego == 0)
	{
		if (REG_KEYINPUT == 0x3FE) InicializarPartida();
	}
}

void BorrarPantallaSuperior()
{
	int i;
	for (i=0;i<24;i++)
		iprintf("\x1b[%d;1H                                ",i);
}

void ConstruirMapaInferior()
{
	int fila,columna,pos_mapMemory,pos_mapData;
	pos_mapData = 0;
	for(fila=0;fila<24;fila++)
	{
		for(columna=0;columna<32;columna++)
		{
			pos_mapMemory            = fila*32+columna;
			mapMemory[pos_mapMemory] = mapDataMapa[pos_mapData];
			pos_mapData ++;
		}
	}
}
