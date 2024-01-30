
//NINTENDO DS DEPENDICIES
#include <stdio.h>
#include <time.h>
#include <nds.h>
#include <maxmod9.h>
#include <NEMain.h>
//fix compiler errors and shite
#include "comp_hax.h"

void Draw3DScene(void)
{

}

int main(){
	irqEnable(IRQ_HBLANK);
  irqSet(IRQ_VBLANK, NE_VBLFunc);
  irqSet(IRQ_HBLANK, NE_HBLFunc);

  NE_Init3D();
  NE_InitConsole();

  while (1)
  {
    NE_WaitForVBL(0);
    NE_Process(Draw3DScene);
    scanKeys();
  }

  return 0;
}
