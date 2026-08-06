# 34-Key Layout Across Boards — Design

**Date:** 2026-08-06
**Status:** QMK portion implemented and compile-verified; ZMK portion deferred

## Goal

Run one identical 34-key layout across every board, so muscle memory transfers
without a seam. Today that means the Corne (crkbd) and the Ferris Sweep. Later it
means a wireless Sweep LP Bling on nice!nano.

## Decisions

**34 keys everywhere.** The Corne drops from three thumbs per side to two; the
outer thumb on each side becomes `KC_NO`. The Sweep is natively 34 keys. Every
board therefore presents the same reachable key set.

This retires `OSM(MOD_MEH)` and `OSM(MOD_HYPR)`, which lived on the Corne's outer
thumbs. They are not relocated. If they turn out to be missed, the cheap options
are a combo or a slot on the `_MEDIA` layer.

**`rows.h` is the single source of truth.** It already defined every row five keys
wide and already defined `TWO_THUMBS_L1` / `TWO_THUMBS_R1` / `TWO_THUMBS_TRNS`.
Those macros were written but unused; this design puts them to work. No `keymap.c`
hardcodes a thumb row — each is a pure wrapper over the shared macros.

**Both boards run a Blok (RP2040).** `ferris/sweep` is `development_board:
promicro`, so it accepts the same `CONVERT_TO = blok` the Corne uses. Both targets
therefore build with the ARM toolchain and neither needs `avr-gcc`.

**Right hand uses right-side mods.** `BASE_R2` is `RGUI_T(KC_K)`, `RSFT_T(KC_L)`,
`RCTL_T(KC_SCLN)`. QMK's bare `CTL_T`/`SFT_T`/`GUI_T` are *left*-side mods, so the
original layout sent left mods from both hands; the ZMK build uses right-side mods
on the right hand, and QMK was flipped to match.

`combos.c` had to change with it. QMK matches combos on the literal keycode, so
`l_scln_combo` referencing `SFT_T(KC_L)` would have silently stopped firing once
the keymap held `RSFT_T(KC_L)`. Any future change to a home-row mod must be made
in both `rows.h` and `combos.c`.

**Animations are Corne-only.** `ocean_dream.c` and `bongo_cat.c` build only where
there is an OLED. The Sweep has none, and the planned wireless build has no
display. The files are skipped at build time, not deleted.

## Architecture

```
users/neekpizza/rows.h          alphas, layers, TWO_THUMBS_*
        |                    |
        v                    v
keyboards/crkbd/         keyboards/ferris/
  keymaps/neekpizza/       keymaps/neekpizza/
  LAYOUT_split_3x5_3       LAYOUT_split_3x5_2
  2 thumbs + KC_NO x2      2 thumbs
  OLED + animations        no OLED
  CONVERT_TO = blok        CONVERT_TO = blok
```

The Ferris keymap sits at `keyboards/ferris/keymaps/` rather than
`keyboards/ferris/sweep/keymaps/`, matching where `default` and `test` already
live. All Ferris variants declare `LAYOUT_split_3x5_2`, so one keymap serves
`sweep` and `0_1` alike. `qmk lint` resolves it as `ferris/sweep/neekpizza`.

## Components

**`users/neekpizza/rows.h`** — unchanged. `TWO_THUMBS_*` become the canonical
thumb definitions rather than dead code.

**`users/neekpizza/rules.mk`** — rewritten to fix a latent bug, see below.

**`keyboards/crkbd/keymaps/neekpizza/`** — `keymap.c` thumb rows become
`KC_NO, TWO_THUMBS_L1, TWO_THUMBS_R1, KC_NO` on `_BASE` and the `TRNS` equivalent
on `_NUM` / `_MEDIA`. `rules.mk` and `config.h` unchanged. This is the only target
building `oled.c`, `ocean_dream.c`, `bongo_cat.c`.

**`keyboards/ferris/keymaps/neekpizza/`** — new. `keymap.c` wraps
`LAYOUT_split_3x5_2` over the same macros. `rules.mk` sets `OLED_ENABLE = no`,
keeps `COMBO_ENABLE` and the size optimisations, and sets `CONVERT_TO = blok`.
`config.h` sets `MASTER_LEFT`.

## Bug found and fixed: `ifdef` vs `ifeq` in `users/neekpizza/rules.mk`

The original guard was:

```make
ifdef OLED_ENABLE
    SRC += oled.c
    SRC += ocean_dream.c
endif
```

Make's `ifdef` tests whether a variable is **defined**, not whether it is truthy.
`OLED_ENABLE = no` still satisfies it. This never surfaced while the Corne was the
only board, because the Corne sets `OLED_ENABLE = yes`. The moment a keymap
explicitly disabled the OLED, `oled.c` was still pulled in and failed to compile
against a board with no OLED driver:

```
users/neekpizza/oled.c:9:1: error: unknown type name 'oled_rotation_t'
```

The rewrite uses `ifeq ($(strip $(OLED_ENABLE)), yes)`, drops the dependency on
the deprecated `OLED_DRIVER_ENABLE`, and removes a duplicate `SRC +=
ocean_dream.c` that appeared in both blocks. Behaviour is preserved: both
animations default on when the OLED is on, and either can be opted out with `= no`.

## Verification

Both targets clean-built with `qmk clean` followed by `qmk compile`:

| Target | Objects from userspace | Result |
|---|---|---|
| `crkbd:neekpizza` | `neekpizza.o`, `oled.o`, `bongo_cat.o`, `ocean_dream.o` | linked, `.uf2` produced |
| `ferris/sweep:neekpizza` | `neekpizza.o` only | linked, `.uf2` produced |

Flashing and real-world testing remain the user's step.

### Toolchain notes

The local build environment was broken in three independent ways, all from
Homebrew upgrades, and all repaired or worked around:

- **`qmk` CLI** — its Homebrew Python was removed. Worked around with an isolated
  venv; `brew reinstall qmk` would fix the system copy.
- **GNU Make** — only macOS's 3.81 was present; QMK needs 4.x. Fixed with
  `brew install make`, which provides `gmake` and a gnubin `make`.
- **`avr-gcc@9`** — broken, linked against a `libisl.23.dylib` that no longer
  exists. Not repaired, and not needed: both boards use `CONVERT_TO = blok` and
  build with ARM. This will bite on any future AVR board.

## Deferred: ZMK for the wireless Bling

Not being built now. Decisions already made, recorded so they survive:

- **No display, no RGB.** The wireless build is a bare keymap. This removes any
  need for an LVGL widget, a custom ZMK module, or an animation rewrite — which
  would otherwise have been the largest single chunk of work.
- **Shield is `cradio`** (`cradio_left` / `cradio_right`) on `nice_nano_v2`.
- **Home-row mods need tuning, not translation.** ZMK's stock `&mt` misfires at
  speed. Expect a custom `hm` hold-tap: `flavor = "tap-preferred"`,
  `tapping-term-ms = 200`, `quick-tap-ms = 175`, `require-prior-idle-ms = 150`,
  then adjustment by feel. QMK gives this behavior for free; ZMK does not.
- **Combos port cleanly.** ZMK addresses combos by key position, and all three
  land on adjacent pairs in the 34-key numbering: Q+W = `0 1`, O+P = `8 9`,
  L+`;` = `18 19`.
- **QMK and ZMK cannot share source.** The two keymaps drift and must be synced
  by hand. Deliberately no generator — three layers and three combos is not
  enough surface to justify one.
- **Open point.** A `zmk-config` repo from the upstream template is the supported
  path; forking ZMK itself means owning merge conflicts against a fast-moving
  Zephyr tree for no keymap-level benefit. The user intends to fork; revisit once
  the repo is local.
