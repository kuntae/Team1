// PALib Template Application

// Includes
#include <PA9.h>       // Include for PA_Lib
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "gfx/all_gfx.h"
#include "gfx/all_gfx.c"
#include "modfile.h"

#define UP_SCREEN 1
#define DOWN_SCREEN 0

#define BG0  0
#define BG1  1
#define BG2  2
#define BG3  3

#define TRUE 1
#define FALSE 0

typedef struct Dong{
	int x;
	int y;
}Dong;

void ret_next() // 아무데나 Touch를 눌러 다음화면으로 전환
{
	while (1) {
		if ( Stylus.Newpress )
			return;
		PA_WaitForVBL();
	}
}

int sel_menu() // Touch를 눌러 메뉴를 선택. 선택된 메뉴의 번호를 리턴
{
	int select=0;
	while(1)
	{
		if(Stylus.Newpress) {
			if(Stylus.X > 20 && Stylus.X < 230 && Stylus.Y > 20 && Stylus.Y < 90) {
				select = 1;
				break;
			}
			else if(Stylus.X > 20 && Stylus.X < 230 && Stylus.Y > 100 && Stylus.Y < 190) {
				select = 2;
				break;
			}
		}
		PA_WaitForVBL();
	}
	return select;
}

int main()
{
	int heroX=0;
	srand(time(NULL));
	Dong dong1={rand()%255,0};
	Dong dong2={rand()%255,0};
	Dong dong3={rand()%255,0};
	Dong dong4={rand()%255,0};
	Dong dong5={rand()%255,0};
	Dong dong6={rand()%255,0};
	Dong dong7={rand()%255,0};


	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL

	PA_InitSound();
	PA_PlayMod(modfile);



	// Infinite loop to keep the program running
	while (1)
	{
		int score=0;
		static int scoreRank1=0, scoreRank2=0, scoreRank3=0;
		PA_EasyBgLoad(UP_SCREEN, BG2, mainup);
		PA_EasyBgLoad(DOWN_SCREEN, BG2, Menu);

		int selnum=0;

		selnum = sel_menu();


		if(selnum == 1){
GAMESTART:
			//배경지정
			PA_EasyBgLoad(UP_SCREEN, BG2, backgroundUp);
			PA_EasyBgLoad(DOWN_SCREEN, BG2, backgroundDown);
			PA_WaitForVBL();
			//캐릭터 지정
			PA_LoadSpritePal(DOWN_SCREEN,0,(void*)frames_Pal);
			PA_CreateSprite(DOWN_SCREEN,0,(void*)frames_Sprite, OBJ_SIZE_16X32, 1, 0, 128-16, 192-32);

			PA_DualLoadSpritePal(2,(void*)dong_Pal);
			PA_DualLoadSpritePal(3,(void*)dong_Pal);
			PA_DualLoadSpritePal(4,(void*)dong_Pal);
			PA_DualLoadSpritePal(5,(void*)dong_Pal);
			PA_DualLoadSpritePal(6,(void*)dong_Pal);
			PA_DualLoadSpritePal(7,(void*)dong_Pal);
			PA_DualLoadSpritePal(8,(void*)dong_Pal);

			PA_DualCreateSprite(2,(void*)dong_Sprite, OBJ_SIZE_16X16,1,2,0,0);
			PA_DualCreateSprite(3,(void*)dong_Sprite, OBJ_SIZE_16X16,1,3,0,0);
			PA_DualCreateSprite(4,(void*)dong_Sprite, OBJ_SIZE_16X16,1,4,0,0);
			PA_DualCreateSprite(5,(void*)dong_Sprite, OBJ_SIZE_16X16,1,5,0,0);
			PA_DualCreateSprite(6,(void*)dong_Sprite, OBJ_SIZE_16X16,1,6,0,0);
			PA_DualCreateSprite(7,(void*)dong_Sprite, OBJ_SIZE_16X16,1,6,0,0);
			PA_DualCreateSprite(8,(void*)dong_Sprite, OBJ_SIZE_16X16,1,6,0,0);

			/* 텍스트 출력 부분 */
			PA_InitText(UP_SCREEN, BG0);
			PA_SetTextTileCol(UP_SCREEN, 9);

			PA_OutputText(DOWN_SCREEN, 1, 21, "강진석");

			//PA_DualSetSpriteAnim(2,2);
			//PA_DualSetSpriteAnim(3,3);

			while(true){
				if(Pad.Held.Right && heroX<256-16){
					PA_SetSpriteAnim(0,0,1);
					heroX+=10;
				}
				if(Pad.Held.Left && heroX>0){
					PA_SetSpriteAnim(0,0,3);
					heroX-=10;
				}
				PA_SetSpriteXY(DOWN_SCREEN,0,heroX,192-32);
				PA_WaitForVBL();
				//---------------------------------------------------------------
				dong1.y+=10;
				if(dong1.y>410){
					score+=100;
					dong1.y=0;
					dong1.x =rand()%255;

				}
				dong2.y+=11;
				if(dong2.y>410){
					score+=100;
					dong2.y=0;
					dong2.x =rand()%255;

				}
				dong3.y+=12;
				if(dong3.y>410){
					score+=100;
					dong3.y=0;
					dong3.x =rand()%255;

				}
				dong4.y+=13;
				if(dong4.y>410){
					score+=100;
					dong4.y=0;
					dong4.x =rand()%255;

				}
				dong5.y+=14;
				if(dong5.y>410){
					score+=100;
					dong5.y=0;
					dong5.x =rand()%255;

				}
				dong6.y+=15;
				if(dong6.y>410){
					score+=100;
					dong6.y=0;
					dong6.x =rand()%255;

				}
				dong7.y+=16;
				if(dong7.y>410){
					score+=100;
					dong7.y=0;
					dong7.x =rand()%255;

				}
				PA_OutputText(UP_SCREEN, 0, 0, "score = %d",score);


				PA_WaitForVBL();
				PA_DualSetSpriteXY(2,dong1.x,dong1.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(3,dong2.x,dong2.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(4,dong3.x,dong3.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(5,dong4.x,dong4.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(6,dong5.x,dong5.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(7,dong6.x,dong6.y);
				PA_WaitForVBL();
				PA_DualSetSpriteXY(8,dong7.x,dong7.y);

				if(dong1.y>390 && (heroX+16)>dong1.x && heroX<(dong1.x+16))
					break;
				if(dong2.y>390 && (heroX+16)>dong2.x && heroX<(dong2.x+16))
					break;
				if(dong3.y>390 && (heroX+16)>dong3.x && heroX<(dong3.x+16))
					break;
				if(dong4.y>390 && (heroX+16)>dong4.x && heroX<(dong4.x+16))
					break;
				if(dong5.y>390 && (heroX+16)>dong5.x && heroX<(dong5.x+16))
					break;
				if(dong6.y>390 && (heroX+16)>dong6.x && heroX<(dong6.x+16))
					break;
				if(dong7.y>390 && (heroX+16)>dong7.x && heroX<(dong7.x+16))
					break;



			}
			PA_WaitForVBL();
			PA_EasyBgLoad(UP_SCREEN, BG2, gameoverUp); //배경화면 gameover
			PA_EasyBgLoad(DOWN_SCREEN, BG2, gameoverDown); //배경화면 gameover
			PA_DeleteSprite(DOWN_SCREEN, 0); //사람 지우기
			PA_DualDeleteSprite(2);  //똥지우기
			PA_DualDeleteSprite(3);  //똥지우기
			PA_DualDeleteSprite(4);  //똥지우기
			PA_DualDeleteSprite(5);  //똥지우기
			PA_DualDeleteSprite(6);  //똥지우기
			PA_DualDeleteSprite(7);  //똥지우기
			PA_DualDeleteSprite(8);  //똥지우기
			PA_InitText(UP_SCREEN, BG0); //텍스트 초기화
			PA_SetTextTileCol(UP_SCREEN, 9); //텍스트 색 검은색 설정
			PA_OutputText(UP_SCREEN, 10, 13, "score = %d",score);
			ret_next(); //입력대기
			
			//--------초기화
			if(score>=scoreRank1){ //1위
				scoreRank3=scoreRank2;
				scoreRank2=scoreRank1;
				scoreRank1=score;
			}
			else if(score>=scoreRank2){//2위
				scoreRank3=scoreRank2;
				scoreRank2=score;
			}
			else if(score>=scoreRank3){//3위
				scoreRank3=score;
			}
			score=0;
			dong1.x=rand()%255; dong1.y=0;
			dong2.x=rand()%255; dong2.y=0;
			dong3.x=rand()%255; dong3.y=0;
			dong4.x=rand()%255; dong4.y=0;
			dong5.x=rand()%255; dong5.y=0;
			dong6.x=rand()%255; dong4.y=0;
			dong7.x=rand()%255; dong5.y=0;
			PA_InitText(UP_SCREEN, BG0); //텍스트 초기화
			PA_WaitForVBL();


		}
		else if(selnum == 2){ //렝크 화면
			PA_WaitForVBL();
			PA_EasyBgLoad(UP_SCREEN, BG2, rankingUp); //배경화면 rankingUp
			PA_EasyBgLoad(DOWN_SCREEN, BG2, rankingDown); //배경화면 rankingDown
			PA_InitText(UP_SCREEN, BG0); //텍스트 초기화
			PA_SetTextTileCol(UP_SCREEN, 9); //텍스트 색 검은색 설정
			PA_OutputText(UP_SCREEN, 10, 13, "Rank 1! = %d",scoreRank1);
			PA_OutputText(UP_SCREEN, 10, 15, "Rank 2! = %d",scoreRank2);
			PA_OutputText(UP_SCREEN, 10, 17, "Rank 3! = %d",scoreRank3);
			ret_next(); //입력대기
			PA_InitText(UP_SCREEN, BG0); //텍스트 초기화
			goto GAMESTART;


		}
		else
			;
		PA_WaitForVBL();
	}

	return 0;
}
