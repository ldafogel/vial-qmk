# afMacro8 – 1×8 Macropad (Pro Micro, SK6812)

Hardware: Arduino Pro Micro (5V/16MHz), 8× MX switches to ground (direct pins), SK6812mini chain (8 LEDs) with 400Ω series resistor on DI and 0.1µF per LED, bulk cap near USB.

Pins (from your KiCad):

- S1..S8 → D1, D0, D4, C6, B5, B4, E6, D7

- RGB DI → B6

Build (from QMK root):

```
make afmacro8:vial
```

Flash to Pro Micro (Caterina):

```
make afmacro8:vial:flash
```
