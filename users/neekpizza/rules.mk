SRC += neekpizza.c

ifdef OLED_ENABLE
  	SRC += oled.c
	SRC += ocean_dream.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    #... your code here...
	ifdef BONGO_CAT_ENABLE
        ifeq ($(strip $(BONGO_CAT_ENABLE)), yes)
            SRC += bongo_cat.c
            OPT_DEFS += -DBONGO_CAT_ENABLE
        endif
    endif
    ifndef BONGO_CAT_ENABLE
        SRC += bongo_cat.c
        OPT_DEFS += -DBONGO_CAT_ENABLE
    endif
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
