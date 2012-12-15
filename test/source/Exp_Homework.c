/*

 * Exp_Homework.c

 *

 *  Created on: 2011. 9. 22.

 *      Author: Minsuk Lee

 */

#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sevencore_io.h"
#include "Menu.h"
#include "mainup.h"
void Exp_3_Homework(void) {
	touchPosition touch;
	consoleDemoInit();
	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(mainupBitmap, BG_GFX, LZ77Vram);

	videoSetModeSub(MODE_5_2D);
	vramSetBankC(VRAM_C_SUB_BG);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(MenuBitmap, BG_GFX_SUB, LZ77Vram);

	while (1) {
		//touchRead(&touch);


	}

}
