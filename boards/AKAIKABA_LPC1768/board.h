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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for the Olimex LPC-P1343 proto board.
 */

/*
 * Board identifiers.
 */
#define BOARD_AKAIKABA_LPC_1768
#define BOARD_NAME "Akaikaba LPC-1768"

/*
 * Board frequencies.
 */
#define SYSOSCCLK               100000000UL
#define F_TICK			1000

/*
 * GPIO 0 initial setup.
 */
#define VAL_GPIO0DIR            0x00000000
#define VAL_GPIO0DATA           0x00000000

/*
 * GPIO 1 initial setup.
 */
#define VAL_GPIO1DIR            PAL_PORT_BIT(GPIO1_SW2)

#define VAL_GPIO1DATA           PAL_PORT_BIT(GPIO1_SW2)

/*
 * GPIO 2 initial setup.
 */


/*
 * GPIO 3 initial setup.
 */


/*
 * Pin definitions.
 */

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
