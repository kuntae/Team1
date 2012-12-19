//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "dong.c"
#include "frames.c"

// Background files : 
#include "backgroundDown.c"
#include "backgroundUp.c"
#include "gameoverDown.c"
#include "gameoverUp.c"
#include "mainup.c"
#include "Menu.c"
#include "rankingDown.c"
#include "rankingUp.c"

// Palette files : 
#include "dong.pal.c"
#include "frames.pal.c"
#include "backgroundDown.pal.c"
#include "backgroundUp.pal.c"
#include "gameoverDown.pal.c"
#include "gameoverUp.pal.c"
#include "mainup.pal.c"
#include "Menu.pal.c"
#include "rankingDown.pal.c"
#include "rankingUp.pal.c"

// Background Pointers :
PAGfx_struct p_backgroundDown = {(void*)backgroundDown_Map, 768, (void*)backgroundDown_Tiles, 36352, (void*)backgroundDown_Pal, (int*)backgroundDown_Info };
PAGfx_struct p_backgroundUp = {(void*)backgroundUp_Map, 768, (void*)backgroundUp_Tiles, 25792, (void*)backgroundUp_Pal, (int*)backgroundUp_Info };
PAGfx_struct p_gameoverDown = {(void*)gameoverDown_Map, 768, (void*)gameoverDown_Tiles, 49152, (void*)gameoverDown_Pal, (int*)gameoverDown_Info };
PAGfx_struct p_gameoverUp = {(void*)gameoverUp_Map, 768, (void*)gameoverUp_Tiles, 49152, (void*)gameoverUp_Pal, (int*)gameoverUp_Info };
PAGfx_struct p_mainup = {(void*)mainup_Map, 768, (void*)mainup_Tiles, 49152, (void*)mainup_Pal, (int*)mainup_Info };
PAGfx_struct p_Menu = {(void*)Menu_Map, 768, (void*)Menu_Tiles, 49152, (void*)Menu_Pal, (int*)Menu_Info };
PAGfx_struct p_rankingDown = {(void*)rankingDown_Map, 768, (void*)rankingDown_Tiles, 49152, (void*)rankingDown_Pal, (int*)rankingDown_Info };
PAGfx_struct p_rankingUp = {(void*)rankingUp_Map, 768, (void*)rankingUp_Tiles, 49152, (void*)rankingUp_Pal, (int*)rankingUp_Info };


#ifdef __cplusplus
}
#endif

