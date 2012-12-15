#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

#include "card_spi.h"
#include "gdbStub.h"
#include "gdbStubAsm.h"
#include "Menu.h"
static portTASK_FUNCTION(Exp_3_Task, pvParameters);
void InitDebug(void);

int main(void) {
	InitDebug();
	//init_virtual_io(ENABLE_LED);	// Enable Virtual LED's on Top Screen
	//init_printf();					// Initialize Bottom Screen for printf()

	xTaskCreate(Exp_3_Task, (const signed char * const)"Exp_3_Task", 2048,
			(void *)NULL, tskIDLE_PRIORITY + 1, NULL);

	vTaskStartScheduler();		// Never returns
	while (1)
		;
	return 0;
}

void InitDebug(void) {
#ifdef DEBUG
	irqInit();
	initSpi();
	initDebug();
	BreakPoint();
#endif
}

void Exp_3_Homework(void);

static
portTASK_FUNCTION(Exp_3_Task, pvParameters ) {
	while (1) {
		Exp_3_Homework();
	}
}
