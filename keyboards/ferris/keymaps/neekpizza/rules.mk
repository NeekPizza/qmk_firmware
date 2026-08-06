COMBO_ENABLE = yes

# No OLED on the Sweep -- this also makes users/neekpizza/rules.mk skip
# oled.c, ocean_dream.c and bongo_cat.c via its OLED_ENABLE guards.
OLED_ENABLE = no

# Size optimisations -- kept in line with the Corne build.
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESCAPE_ENABLE = no
MOUSEKEY_ENABLE = no
MAGIC_ENABLE = no
INTROSPECTION_KEYMAP_C = combos.c
LTO_ENABLE = yes
CONVERT_TO = blok
