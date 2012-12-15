#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

#include "card_spi.h"
#include "gdbStub.h"
#include "gdbStubAsm.h"

#define COLOR_RED       RGB(31,  0,  0) //빨간색 RGB
#define COLOR_GREEN	   RGB(0,  31,  0) //초록색 RGB
#define COLOR_BLUE	   RGB(0,   0, 31) //파란색 RGB
#define COLOR_BLACK     RGB(0,   0,  0) //검은색 RGB

#define BOX_WIDTH	16	  //박스의 가로크기
#define BOX_HEIGHT	16 //박스의 세로크기
#define MAX_X		(SCREEN_WIDTH / BOX_WIDTH)
#define MAX_Y		(SCREEN_HEIGHT / BOX_HEIGHT)

#define DIRECTION_UP_LEFT		1  //왼쪽 위 대각선 방향
#define DIRECTION_UP_RIGHT		2  //오른쪽 위 대각선 방향
#define DIRECTION_DOWN_LEFT		3  //왼쪽 아래 대각선 방향
#define DIRECTION_DOWN_RIGHT	4  //오른쪽 아래 대각선 방향

#define NUM_TASK	3  //타스크의 개수 이 실힘에서는 1개의 공만 만든다

struct parameters {
	char *taskname;		// Task Name
	int direction;		// Current Moving Direction
	int basePoint_X;		// X Starting Position
	int basePoint_Y;		// Y Starting Position
	u32 color;			// Ball Color
	int delay;			// Task Delay
};

struct parameters Param[NUM_TASK] = {
	{ "1", DIRECTION_DOWN_RIGHT, 0, 0,  COLOR_RED,   100 },
	{ "2", DIRECTION_UP_RIGHT, 0, MAX_Y/2, COLOR_GREEN, 130},
	{ "3", DIRECTION_UP_RIGHT, 0, MAX_Y-1,COLOR_BLUE, 160}
};

static portTASK_FUNCTION(Ball_Task, pvParameters);
void InitDebug(void);
void vStartExpTasks(void);
void draw_my_box(int pos_x, int pos_y, u16 color);

int
main(void)
{
	InitDebug();
	init_virtual_io(ENABLE_SW | ENABLE_MATRIX);	// Enable Virtual LED's on Top Screen
	//init_printf();							// Initialize Bottom Screen for printf()

	vStartExpTasks();
	vTaskStartScheduler();		// Never returns
	while(1)
		;
	return 0;
}

void
InitDebug(void)
{
#ifdef DEBUG
	irqInit();
	initSpi();
	initDebug();
	BreakPoint();
#endif
}

void
draw_my_box(int pos_x, int pos_y, u16 color)
{
	int i, j;
    u32 *basePoint, pixel;

    pixel = (color << 16) + color;
    for (i = 0; i < BOX_HEIGHT; i++) {
 	    basePoint = (u32 *)BG_GFX +
 	      ((((pos_y * BOX_HEIGHT) + i) * SCREEN_WIDTH) + pos_x * BOX_WIDTH) / 2;
    	for (j = 0; j < (BOX_WIDTH / 2); j++)
    		*basePoint++ = pixel;
	}
}
void
vStartExpTasks(void)
{
	struct parameters *p;
	int i;

	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	bgInit(3,BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	for (i = 0, p = Param; i < NUM_TASK; i++, p++)
		xTaskCreate(Ball_Task, (const signed char *)(p->taskname), 1024, (void *)p, tskIDLE_PRIORITY + 5, NULL);

}

static portTASK_FUNCTION(Ball_Task, pvParameters)
{
	struct parameters *p = (struct parameters *)pvParameters;
	int x, y, prevX, prevY;
	int count=0;
	x=prevX=p->basePoint_X;
	y=prevY=p->basePoint_Y;
	int key_pressed=0;

	while(1) {
		if(key_pressed==0 && (NDS_SWITCH() & KEY_START) ){ //START 키가 입력되면 방향을 반대로 전환
			key_pressed=1;
			if(p->direction==DIRECTION_DOWN_RIGHT){
				p->direction=DIRECTION_UP_LEFT;
			}
			else if(p->direction==DIRECTION_DOWN_LEFT){
				p->direction=DIRECTION_UP_RIGHT;
			}
			else if(p->direction==DIRECTION_UP_RIGHT){
				p->direction=DIRECTION_DOWN_LEFT;
			}
			else if(p->direction==DIRECTION_DOWN_LEFT){
				p->direction=DIRECTION_UP_RIGHT;
			}
		}
		if(count == 20){
			count = 0;
			draw_my_box(prevX, prevY, COLOR_BLACK);
			if(p->direction==DIRECTION_UP_LEFT){ // 만약 왼쪽 위 방향이라면
				if(x==0 && y==0){
					p->direction=DIRECTION_DOWN_RIGHT;
					x++; y++;
				}
				else if(x==0){
					p->direction=DIRECTION_UP_RIGHT;
					x++; y--;
				}
				else if(y==0){
					p->direction=DIRECTION_DOWN_LEFT;
					x--; y++;
				}
				else{
					x--; y--;
				}
			}
			else if(p->direction==DIRECTION_UP_RIGHT){ // 만약 오른쪽 위 방향이라면
				if(x==MAX_X-1 && y==0){
					p->direction=DIRECTION_DOWN_LEFT;
					x--; y++;
				}
				else if(x==MAX_X-1){
					p->direction=DIRECTION_UP_LEFT;
					x--; y--;
				}
				else if(y==0){
					p->direction=DIRECTION_DOWN_RIGHT;
					x++; y++;
				}
				else{
					x++; y--;
				}
			}
			else if(p->direction==DIRECTION_DOWN_RIGHT){ // 만약 오른쪽 아래 방향이라면
				if(x==MAX_X-1 && y==MAX_Y-1){
					p->direction=DIRECTION_UP_LEFT;
					x--; y--;
				}
				else if(x==MAX_X-1){
					p->direction=DIRECTION_DOWN_LEFT;
					x--; y++;
				}
				else if(y==MAX_Y-1){
					p->direction=DIRECTION_UP_RIGHT;
					x++; y--;
				}
				else{
					x++; y++;
				}
			}
			else if(p->direction==DIRECTION_DOWN_LEFT){ // 만약 왼쪽 아래 방향이라면
				if(x==0 && y==MAX_Y-1){
					p->direction=DIRECTION_UP_RIGHT;
					x++; y--;
				}
				else if(x==0){
					p->direction=DIRECTION_DOWN_RIGHT;
					x++; y++;
				}
				else if(y==MAX_Y-1){
					p->direction=DIRECTION_UP_LEFT;
					x--; y--;
				}
				else{
					x--; y++;
				}
			}
			draw_my_box(x, y, p->color);
		}
		if ((key_pressed == 1) && (!(NDS_SWITCH() & KEY_START))){
			key_pressed=0;
		}
		count++;
		vTaskDelay(MSEC2TICK(p->delay/20));		// Delay


		prevX = x; prevY = y;

	}
}
