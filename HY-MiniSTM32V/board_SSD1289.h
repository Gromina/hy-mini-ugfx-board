/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#define GDISP_REG              (*((volatile uint16_t *) 0x60000000)) /* RS = 0 */
#define GDISP_RAM              (*((volatile uint16_t *) 0x60020000)) /* RS = 1 */

static inline void init_board(GDisplay *g) {

  // As we are not using multiple displays we set g->board to NULL as we don't use it.
  g->board = 0;

  switch(g->controllerdisplay) {
  case 0:											// Set up for Display 0
    /* FSMC setup for F1 */
    rccEnableAHB(RCC_AHBENR_FSMCEN, 0);

    /* set pin modes */
    IOBus busD = {GPIOD, PAL_WHOLE_PORT, 0};
    IOBus busE = {GPIOE, PAL_WHOLE_PORT, 0};
    palSetBusMode(&busD, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetBusMode(&busE, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOB, GPIOB_BL_CNT, PAL_MODE_OUTPUT_PUSHPULL);

    /* FSMC timing */
    FSMC_Bank1->BTCR[0+1] = (6) | (10 << 8) | (10 << 16);

    /* Bank1 NOR/SRAM control register configuration
     * This is actually not needed as already set by default after reset */
    FSMC_Bank1->BTCR[0] = FSMC_BCR1_MWID_0 | FSMC_BCR1_WREN | FSMC_BCR1_MBKEN;
    break;
  }
}

static inline void post_init_board(GDisplay *g) {
  (void) g;
}

static inline void setpin_reset(GDisplay *g, bool_t state) {
  (void) g;
  (void) state;
}

static inline void set_backlight(GDisplay *g, uint8_t percent) {
  (void) g;
  (void) percent;
}

static inline void acquire_bus(GDisplay *g) {
  (void) g;
}

static inline void release_bus(GDisplay *g) {
  (void) g;
}

static inline void write_index(GDisplay *g, uint16_t index) {
  (void) g;

  GDISP_REG = index;
}

static inline void write_data(GDisplay *g, uint16_t data) {
  (void) g;

  GDISP_RAM = data;
}

static inline void setreadmode(GDisplay *g) {
  (void) g;
}

static inline void setwritemode(GDisplay *g) {
  (void) g;
}

static inline uint16_t read_data(GDisplay *g) {
  (void) g;

  return GDISP_RAM;
}

#if defined(GDISP_USE_DMA) || defined(__DOXYGEN__)
  //#error "GDISP - SSD1289: This interface does not support DMA"

  static inline void dma_with_noinc(GDisplay *g, color_t *buffer, int area) {
    (void) g;
    (void) buffer;
    (void) area;
  }

  static inline void dma_with_inc(GDisplay *g, color_t *buffer, int area) {
    (void) g;
    (void) buffer;
    (void) area;
  }
#endif

#endif /* _GDISP_LLD_BOARD_H */

