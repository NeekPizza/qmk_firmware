SRC += neekpizza.c

# NOTE: use ifeq/ifneq, not ifdef. Make's ifdef tests whether a variable is
# *defined*, so `OLED_ENABLE = no` would still pass an ifdef check and drag
# oled.c into boards that have no OLED at all.
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled.c

    # Both animations default on when the OLED is on; set either to `no`
    # in a keymap's rules.mk to opt out.
    ifneq ($(strip $(BONGO_CAT_ENABLE)), no)
        SRC += bongo_cat.c
        OPT_DEFS += -DBONGO_CAT_ENABLE
    endif

    ifneq ($(strip $(OCEAN_DREAM_ENABLE)), no)
        SRC += ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
endif
