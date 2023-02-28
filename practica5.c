
#include "fondo.h"

//#resource "Portada.chr"

#include <stdlib.h>
#include <string.h>
#include "neslib.h"
#include <nes.h>

//#link "chr_generic.s"

#include "bcd.h"
//#link "bcd.c"

#include "vrambuf.h"
//#link "vrambuf.c"

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x27,			// Color de la pantalla

  0x1B,0x2A,0x37,0x30,	// Paleta de fondo 0
  0x16,0x0F,0x30,0x00,	// Paleta de fondo 1
  0x05,0x30,0x36,0x00,	// Paleta de fondo 2
  0x0B,0x1B,0x2B,0x00,  // Paleta de fondo 3

  0x13,0x0F,0x39,0xFF,	// paleta de sprite 0
  0x2B,0x2A,0x0C,0x00,	// paleta de sprite 1
  0x16,0x16,0x16,0x00,	// paleta de sprite 2
  0x0D,0x27,0x0F	// paleta de sprite 3
};

void setup_graphics() {
  oam_clear();
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
  
  vram_adr(NAMETABLE_A); //se localiza en la dirección de la Name Table A
  vram_unrle(fondo); //Se carga el fondo o escena
  
  ppu_on_all();
  while(1) {
  }
}
