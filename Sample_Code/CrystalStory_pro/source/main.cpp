/*
 * main.cpp
 *
 *  Created on: 2010. 12. 16.
 *      Author: 컴퓨터공학과
 *description : CrystalStory main
 */

#include "cs_api.h"
// Converted using PAGfx
#include "all_gfx.h"
#include "game.h"
#include "menu.h"

int main()
{
	// PAlib 초기화
	PA_Init();
	// PAlib VBL Reference 초기화
	PA_InitVBL();

	while(true)
	{
		// 메인 배경화면 출력
		PA_LoadBackground(UP_SCREEN, BG2, &bg_main_up);
		PA_LoadBackground(DOWN_SCREEN, BG2, &bg_main_down);

		int selnum=0;
		ret_next(); // 터치로 아무데나 누르면 다음 상태로의 전이
		PA_WaitForVBL();
		PA_LoadBackground(DOWN_SCREEN, BG2, &bg_menu); // 메뉴화면 출력

		selnum = sel_menu();

		if(selnum == 1){
			// 메뉴1 - 게임소개 (미구현)
		}
		else if(selnum == 2){
			// 메뉴2 - Single Player
			init_singleplay(); // 1player 초기화
			singleplay_start(); // 1player 게임시작
		}
		else if(selnum == 3){
			// 메뉴3 - Multi Player
		}
		else
			;
		PA_WaitForVBL();
	}
}
