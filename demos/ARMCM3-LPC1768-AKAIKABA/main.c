/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "board.h"
#include "LPC17xx.h"
#include "system_LPC17xx.h"

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker1");
  static unsigned int i = 0;
  while (TRUE) 
  {
	  if (i % 2)
	    LPC_GPIO0->FIOSET |= 1 << 8;
	  else
	    LPC_GPIO0->FIOCLR |= 1 << 8; // puts P1.29 into output mode.
	    chThdSleepMilliseconds(2000);
	    i++;
  }
}

/*
 * RGB LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread2, 128);
static msg_t Thread2(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker2");
  while (TRUE) 
  {
    chThdSleepMilliseconds(2500);
  }
}

/*
 * Application entry point.
 */
/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
//  SystemInit();
//  SysTick_Config((100000000/1000));
    LPC_GPIO0->FIODIR |= 1 << 9; // puts P1.29 into output mode.
    LPC_GPIO0->FIODIR |= 1 << 8; // puts P1.29 into output mode.
    LPC_GPIO0->FIODIR |= 1 << 7; // puts P1.29 into output mode.
//    LPC_GPIO0->FIOSET |= 1 << 9; // puts P1.29 into output mode.
//    LPC_GPIO0->FIOSET |= 1 << 8; // puts P1.29 into output mode.
//    LPC_GPIO0->FIOSET |= 1 << 7; // puts P1.29 into output mode.

  chSysInit();

  /*
   * Creates the LED threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (1) 
  {
    chThdSleepMilliseconds(2000);
  }
    return 0;
}
