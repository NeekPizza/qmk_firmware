SRC += neekpizza.c

ifdef OLED_ENABLE
  SRC += oled.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    #... your code here...
    ifdef OCEAN_DREAM_ENABLE
        ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
            SRC += ocean_dream.c
            OPT_DEFS += -DOCEAN_DREAM_ENABLE
        endif
    endif
    ifndef OCEAN_DREAM_ENABLE
        SRC += ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
endif
