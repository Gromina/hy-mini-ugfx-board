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
 * Setup for the HY-Mini STM32V proto board.
 */

/*
 * Board identifier.
 */
#define BOARD_HY_MINI_STM32V
#define BOARD_NAME              "HY-Mini STM32V"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F10X_HD

/*
 * IO pins assignments.
 */
#define GPIOA_SPI1NSS           4

#define GPIOB_LED1		0
#define GPIOB_LED2		1
#define GPIOB_KEYA		2
#define GPIOB_BL_CNT		5

#define GPIOC_KEYB		13

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA2  - Alternate output  (USART2 TX).
 * PA3  - Normal input      (USART2 RX).
 * PA4  -  (TP CS)
 * PA5  -  (SPI SCK)
 * PA6  -  (SPI MISO)
 * PA7  -  (SPI MOSI)
 * PA9  - Alternate output  (USART1 TX).
 * PA10 - Normal input      (USART1 RX).
 * PA11 - Normal input      (USB DM).
 * PA12 - Normal input      (USB DP).
 * PA13 -  (JTMS)
 * PA14 -  (JTCK)
 * PA15 -  (JTDI)
 */
#define VAL_GPIOACRL            0xB4B34B88      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x888444B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB0  - Push Pull output  (LED).
 * PB1  - Push Pull output  (LED).
 * PB2  - Normal input      (BUTTON).
 * PB3  -  (JTDO)
 * PB4  -  (JTRST)
 * PB5  - Push Pull output (BL CNT)
 * PB6  -  (TP IRQ)
 * PB7  -  (USB EN)
 * PB13 - Alternate output  (MMC SPI2 SCK).
 * PB14 - Normal input      (MMC SPI2 MISO).
 * PB15 - Alternate output  (MMC SPI2 MOSI).
 */
#define VAL_GPIOBCRL            0x84388433      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0xB4B88888      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 * PC8  - Alternate PP 50M      (SD_D0).
 * PC9  - Alternate PP 50M      (SD_D1).
 * PC10 - Alternate PP 50M      (SD_D2).
 * PC11 - Alternate PP 50M      (SD_D3).
 * PC12 - Alternate PP 50M      (SD_CLK).
 * PC12 - Push Pull output      (LED).
 * PC13 - Normal input          (BUTTON).
 * PC14 - Normal input          (XTAL).
 * PC15 - Normal input          (XTAL).
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x444BBBBB      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Alternate PP 50M  (FSMC_D2)
 * PD1  - Alternate PP 50M  (FSMC_D3)
 * PD2  - Alternate PP 50M  (SDIO_CMD)
 * PD3  - Alternate PP 50M  (SD_CD)
 * PD4  - Alternate PP 50M  (LCD_RD)
 * PD5  - Alternate PP 50M  (LCD_WR)
 * PD7  - Alternate PP 50M  (LCD_CS)
 * PD8  - Alternate PP 50M  (FSMC_D13)
 * PD9  - Alternate PP 50M  (FSMC_D14)
 * PD10 - Alternate PP 50M  (FSMC_D15)
 * PD11 - Alternate PP 50M  (LCD_RS)
 * PD14 - Alternate PP 50M  (FSMC_D0)
 * PD15 - Alternate PP 50M  (FSMC_D1)
 */
#define VAL_GPIODCRL            0xBBBB8BBB      /*  PD7...PD0 */
#define VAL_GPIODCRH            0xBB883BBB      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 * PE7  - Alternate PP 50M  (FSMC_D4)
 * PE8  - Alternate PP 50M  (FSMC_D5)
 * PE9  - Alternate PP 50M  (FSMC_D6)
 * PE10 - Alternate PP 50M  (FSMC_D7)
 * PE11 - Alternate PP 50M  (FSMC_D8)
 * PE12 - Alternate PP 50M  (FSMC_D9)
 * PE13 - Alternate PP 50M  (FSMC_D10)
 * PE14 - Alternate PP 50M  (FSMC_D11)
 * PE15 - Alternate PP 50M  (FSMC_D12)
 */
#define VAL_GPIOECRL            0xB8888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0xBBBBBBBB      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * Port F setup.
 * Everything input with pull-up expect:
 */
#define VAL_GPIOFCRL            0x88888888      /*  PF7...PF0 */
#define VAL_GPIOFCRH            0x88888888      /* PF15...PF8 */
#define VAL_GPIOFODR            0xFFFFFFFF

/*
 * Port G setup.
 * Everything input with pull-up expect:
 */
#define VAL_GPIOGCRL            0x88888888      /*  PG7...PG0 */
#define VAL_GPIOGCRH            0x88888888      /* PG15...PG8 */
#define VAL_GPIOGODR            0xFFFFFFFF


/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp) palClearPad(GPIOC, GPIOC_USB_DISC)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp) palSetPad(GPIOC, GPIOC_USB_DISC)

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
