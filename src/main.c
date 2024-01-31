
//NINTENDO DS DEPENDICIES
#include <stdio.h>
#include <time.h>
#include <nds.h>
#include <maxmod9.h>
#include <NEMain.h>
//fix compiler errors and shite
#include "comp_hax.h"

NE_Camera *Camera;

void setupCamera(){
	Camera = NE_CameraCreate();

  NE_CameraSet(Camera,
  0, 0, 2,
  0, 0, 0,
  0, 1, 0);
}

void Draw3DScene(void)
{
  NE_CameraUse(Camera);
  NE_ViewRotate(90,0,0);
  NE_ViewMove(0,0,0);
  NE_PolyBegin(GL_QUAD);
      NE_PolyColor(NE_Red);    // Set next vertices color
      NE_PolyVertex(-1, 1, 0); // Send vertex
      NE_PolyColor(NE_Green);
      NE_PolyVertex(-1, -1, 0);
      NE_PolyColor(NE_Yellow);
      NE_PolyVertex(1, -1, 0);
      NE_PolyColor(NE_Blue);
      NE_PolyVertex(1, 1, 0);
  NE_PolyEnd();
}

int main(){
	irqEnable(IRQ_HBLANK);
  irqSet(IRQ_VBLANK, NE_VBLFunc);
  irqSet(IRQ_HBLANK, NE_HBLFunc);

  NE_Init3D();
  NE_TextureSystemReset(0, 0, NE_VRAM_AB); // makes C and D unused
  //Now we Setup 
  videoSetModeSub(MODE_5_2D);
  bgInitSub(2, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
  vramSetBankC(VRAM_C_SUB_BG_0x06200000);

  for(int i =0; i == 256*192; i++){
    VRAM_C[i] = RGB15(15,0,15);
  }

	setupCamera();

  while (1)
  {
    NE_WaitForVBL(0);
    NE_Process(Draw3DScene);
    scanKeys();
  }

  return 0;
}
