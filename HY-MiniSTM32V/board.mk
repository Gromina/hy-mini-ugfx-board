GFXINC	+= $(GFXLIB)/boards/base/HY-MiniSTM32V
GFXSRC	+=
GFXDEFS += -DGFX_USE_CHIBIOS=TRUE

include $(GFXLIB)/boards/base/HY-MiniSTM32V/chibios_board/board.mk
#include $(GFXLIB)/drivers/gdisp/ILI9320/gdisp_lld.mk
include $(GFXLIB)/drivers/gdisp/SSD1289/gdisp_lld.mk
#include $(GFXLIB)/drivers/gdisp/R61505U/gdisp_lld.mk
include $(GFXLIB)/drivers/ginput/touch/ADS7843/ginput_lld.mk

