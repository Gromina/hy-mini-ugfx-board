*****************************************************************************
** ChibiOS/RT port for ARM-Cortex-M3 STM32F103.                            **
*****************************************************************************

** TARGET **

The demo runs on an HY-mini STM32V (model HY32D) board

** The Demo **

The demo flashes the board LED using a thread, by pressing the button located
on the board the test procedure is activated with output on the serial port
SD2 (USART2).

** Build Procedure **

Was tested on gcc arm embedded toolchain for linux
( gcc-arm-none-eabi-4_8-2014q1 )
ChibiOS 2.6.4
uGfx release_21_140619


** Notes **

Some files used by the demo are not part of ChibiOS/RT but are copyright of
ST Microelectronics and are licensed under a different license.
Also note that not all the files present in the ST library are distributed
with ChibiOS/RT, you can find the whole library on the ST web site:

                             http://www.st.com
