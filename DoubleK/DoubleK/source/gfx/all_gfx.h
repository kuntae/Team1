//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char dong_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : dong_Pal
extern const unsigned char frames_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : frames_Pal

// Background files : 
extern const int backgroundDown_Info[3]; // BgMode, Width, Height
extern const unsigned short backgroundDown_Map[768] __attribute__ ((aligned (4))) ;  // Pal : backgroundDown_Pal
extern const unsigned char backgroundDown_Tiles[36352] __attribute__ ((aligned (4))) ;  // Pal : backgroundDown_Pal
extern PAGfx_struct backgroundDown; // background pointer

extern const int backgroundUp_Info[3]; // BgMode, Width, Height
extern const unsigned short backgroundUp_Map[768] __attribute__ ((aligned (4))) ;  // Pal : backgroundUp_Pal
extern const unsigned char backgroundUp_Tiles[25792] __attribute__ ((aligned (4))) ;  // Pal : backgroundUp_Pal
extern PAGfx_struct backgroundUp; // background pointer

extern const int gameoverDown_Info[3]; // BgMode, Width, Height
extern const unsigned short gameoverDown_Map[768] __attribute__ ((aligned (4))) ;  // Pal : gameoverDown_Pal
extern const unsigned char gameoverDown_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : gameoverDown_Pal
extern PAGfx_struct gameoverDown; // background pointer

extern const int gameoverUp_Info[3]; // BgMode, Width, Height
extern const unsigned short gameoverUp_Map[768] __attribute__ ((aligned (4))) ;  // Pal : gameoverUp_Pal
extern const unsigned char gameoverUp_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : gameoverUp_Pal
extern PAGfx_struct gameoverUp; // background pointer

extern const int mainup_Info[3]; // BgMode, Width, Height
extern const unsigned short mainup_Map[768] __attribute__ ((aligned (4))) ;  // Pal : mainup_Pal
extern const unsigned char mainup_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : mainup_Pal
extern PAGfx_struct mainup; // background pointer

extern const int Menu_Info[3]; // BgMode, Width, Height
extern const unsigned short Menu_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Menu_Pal
extern const unsigned char Menu_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : Menu_Pal
extern PAGfx_struct Menu; // background pointer

extern const int rankingDown_Info[3]; // BgMode, Width, Height
extern const unsigned short rankingDown_Map[768] __attribute__ ((aligned (4))) ;  // Pal : rankingDown_Pal
extern const unsigned char rankingDown_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : rankingDown_Pal
extern PAGfx_struct rankingDown; // background pointer

extern const int rankingUp_Info[3]; // BgMode, Width, Height
extern const unsigned short rankingUp_Map[768] __attribute__ ((aligned (4))) ;  // Pal : rankingUp_Pal
extern const unsigned char rankingUp_Tiles[49152] __attribute__ ((aligned (4))) ;  // Pal : rankingUp_Pal
extern PAGfx_struct rankingUp; // background pointer


// Palette files : 
extern const unsigned short dong_Pal[22] __attribute__ ((aligned (4))) ;
extern const unsigned short frames_Pal[62] __attribute__ ((aligned (4))) ;
extern const unsigned short backgroundDown_Pal[61] __attribute__ ((aligned (4))) ;
extern const unsigned short backgroundUp_Pal[18] __attribute__ ((aligned (4))) ;
extern const unsigned short gameoverDown_Pal[118] __attribute__ ((aligned (4))) ;
extern const unsigned short gameoverUp_Pal[46] __attribute__ ((aligned (4))) ;
extern const unsigned short mainup_Pal[143] __attribute__ ((aligned (4))) ;
extern const unsigned short Menu_Pal[78] __attribute__ ((aligned (4))) ;
extern const unsigned short rankingDown_Pal[82] __attribute__ ((aligned (4))) ;
extern const unsigned short rankingUp_Pal[20] __attribute__ ((aligned (4))) ;


#endif

