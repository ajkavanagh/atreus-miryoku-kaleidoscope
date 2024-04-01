# (Slightly) Modified Miryoku keymap for Atreus using Kaleidoscope

(Note the LICENSE is GPL3 as the files were copied from
https://github.com/keyboardio/Kaleidoscope).

Although Chrysalis is fun, it's probably more useful to just work out the
keymap and then build it using Kaleidoscope.  Took a while to get right.

* Colemak
* More layers
* Home Row mods

The layout is basically https://github.com/manna-harbour/miryoku but with some
minor mods for the Atreus, and ported to work on Kaleidoscope.

# Building/flashing

(borrowed from: https://community.keyboard.io/t/getting-started-with-atreus/5137/2)
```bash
$ git clone https://github.com/keyboardio/Kaleidoscope
$ cd ${HOME}/git/Kaleidoscope
$ make setup
$ export KALEIDOSCOPE_DIR=`pwd`
$ cd directory/of/your/Atreus
$ ### Edit the .ino files ###
$ make compile
$ make flash # Pressing the prog (Escape originally, bottom/left key)
```

# Keymap

Meaning of brackets:

 * `(thing)` == means hold for 'thing' layer.
 * `[thing]` == means double tap for that 'thing' to be done.

Specific meanings:

* `[Boot]` - enter bootloader mode.
* `[Tap]` - double tap to enter main layer with no mods. (Not even sure if this is possible).
* `[Extra]` - double tap to switch to Qwerty as a layer.
* `[Base]` - double tap to return to base (after locking a layer with LLock).
* `(Super)` - QuKey hold for super key.  - may want tap dance for that key?
* `(Alt)` - QuKey hold for Alt key.
* `(Ctrl)` - QuKey hold for Ctrl key.
* `(Shift)` - QuKey hold for Shift Key
* `(AltGr)` - QuKey hold for AltGr key.
* `[Opp LLock]` - double tap to lock the oposition Layer (see below) to that selected with a thumb key.
* `[Cur LLock]` - double tap to lock to the same thumb layer (see below).
* `(ToMedia)` - QuKey hold for Media layer.
* `(ToNova)` - QuKey hold for Navigation layer.
* `(ToMouse)` - QuKey hold for Mouse layer.
* `(ToSym)` - QuKey hold for sympbols layer.
* `(ToNum)` - QuKey hold for Numbers layer
* `(ToFun)` - QuKey hold for Function keys layer.


Opp and Cur LLock keys.

+-----------|---------|---------+
| Held key  | Cur     | Opp     |
+===========|=========|=========+
| Esc       | ToMedia | ToFun   |
+-----------|---------|---------+
| Space     | ToNav   | ToNum   |
+-----------|---------|---------+
| Tab       | ToMouse | ToSym   |
+-----------|---------|---------+
| Enter     | ToSym   | ToMouse |
+-----------|---------|---------+
| Backspace | ToNum   | ToNav   |
+-----------|---------|---------+
| Delete    | ToFun   | ToMedia |
+-----------|---------|---------+





## Main layer

```
+---------|---------|-------------|-------------|---------|-----------|---------|---------|-------------|-------------|---------|---------+
| c1      | c2      | c3          | c4          | c5      | c6        | c7      | c8      | c9          | c10         | c11     | c12     |
+=========|=========|=============|=============|=========|===========|=========|=========|=============|=============|=========|=========+
| Q       | W       | F           | P           | B       |           |         | J       | L           | U           | Y       | '       |
| [Boot]  | [Tap]   | [Extra]     | [Base]      |         |           |         |         | [Base]      | [Extra]     | [Tap]   | [Boot]  |
+---------|---------|-------------|-------------|---------|-----------|---------|---------|-------------|-------------|---------|---------+
| A       | R       | S           | T           | G       |           |         | M       | N           | E           | I       | O       |
| (Super) | (Alt)   | (Ctrl)      | (Shift)     |         |           |         |         | (Shift)     | (Ctrl)      | (Alt)   | (Super) |
+---------|---------|-------------|-------------|---------|-----------|---------|---------|-------------|-------------|---------|---------+
| Z       | X       | C           | D           | V       |           |         | K       | H           | ,           | .       | /       |
|         | (AltGr) | [Opp LLock] | [Cur LLock] |         |           |         |         | [Cur LLock] | [Opp LLock] | (AltGr) |         |
+---------|---------|-------------|-------------|---------|-----------|---------|---------|-------------|-------------|---------|---------+
|         |         |             | Esc         | Spc     | Tab       | Enter   | BkSp    | Del         |             |         |         |
|         |         |             | (ToMedia)   | (ToNav) | (ToMouse) | (ToSym) | (ToNum) | (ToFun)     |             |         |         |
+---------|---------|-------------|-------------|---------|-----------|---------|---------|-------------|-------------|---------|---------+
```



## Symbol layer - accessed by ToSym - Left hand only

```
+----|----|----|----|----|----|------|----|-------------|-------------|-------|--------+
| c1 | c2 | c3 | c4 | c5 | c6 | c7   | c8 | c9          | c10         | c11   | c12    |
+====|====|====|====|====|====|======|====|=============|=============|=======|========+
| {  | &  | *  | (  | }  |    |      |    | [Base]      | [Extra]     | [Tap] | [Boot] |
+----|----|----|----|----|----|------|----|-------------|-------------|-------|--------+
| :  | $  | %  | ^  | +  |    |      |    | Shift       | Ctrl        | Alt   | Super  |
+----|----|----|----|----|----|------|----|-------------|-------------|-------|--------+
| ~  | !  | "  | #  | \| |    |      |    | [Cur LLock] | [Opp LLock] |       |        |
+----|----|----|----|----|----|------|----|-------------|-------------|-------|--------+
|    |    |    | (  | )  | _  | HELD |    |             |             |       |        |
+----|----|----|----|----|----|------|----|-------------|-------------|-------|--------+
```

## Num keypad layer - accessed by ToNum - Left hand only

```
+----|----|----|----|----|----|----|------|-------------|-------------|-------|--------+
| c1 | c2 | c3 | c4 | c5 | c6 | c7 | c8   | c9          | c10         | c11   | c12    |
+====|====|====|====|====|====|====|======|=============|=============|=======|========+
| [  | 7  | 8  | 9  | ]  |    |    |      | [Base]      | [Extra]     | [Tap] | [Boot] |
+----|----|----|----|----|----|----|------|-------------|-------------|-------|--------+
| ;  | 4  | 5  | 6  | =  |    |    |      | Shift       | Ctrl        | Alt   | Super  |
+----|----|----|----|----|----|----|------|-------------|-------------|-------|--------+
| `  | 1  | 2  | 3  | \  |    |    |      | [Cur LLock] | [Opp LLock] |       |        |
+----|----|----|----|----|----|----|------|-------------|-------------|-------|--------+
|    |    |    | .  | 0  | -  |    | HELD |             |             |       |        |
+----|----|----|----|----|----|----|------|-------------|-------------|-------|--------+
```

## Fun layer - accessed by ToFun - left hand only

```
+-----|----|----|------|--------|-----|----|----|-------------|-------------|-------|--------+
| c1  | c2 | c3 | c4   | c5     | c6  | c7 | c8 | c9          | c10         | c11   | c12    |
+=====|====|====|======|========|=====|====|====|=============|=============|=======|========+
| F12 | F7 | F8 | F9   | PrtScr |     |    |    | [Base]      | [Extra]     | [Tap] | [Boot] |
+-----|----|----|------|--------|-----|----|----|-------------|-------------|-------|--------+
| F11 | F4 | F5 | F6   | Scroll |     |    |    |             |             |       |        |
|     |    |    |      | Lock   |     |    |    | Shift       | Ctrl        | Alt   | Super  |
+-----|----|----|------|--------|-----|----|----|-------------|-------------|-------|--------+
| F10 | F1 | F2 | F3   | Pause  |     |    |    | [Cur LLock] | [Opp LLock] |       |        |
|     |    |    |      | Break  |     |    |    |             |             |       |        |
+-----|----|----|------|--------|-----|----|----|-------------|-------------|-------|--------+
|     |    |    | Menu | Space  | Tab |    |    | HELD        |             |       |        |
+-----|----|----|------|--------|-----|----|----|-------------|-------------|-------|--------+
```

## Media layer - - accessed by ToMedia - right hand only

```
+-------|-----|-------------|-------------|----|----|-------|-------|-------|-----|-------|-------+
| c1    | c2  | c3          | c4          | c5 | c6 | c7    | c8    | c9    | c10 | c11   | c12   |
+=======|=====|=============|=============|====|====|=======|=======|=======|=====|=======|=======+
|       |     |             |             |    |    |       |       |       |     |       |       |
+-------|-----|-------------|-------------|----|----|-------|-------|-------|-----|-------|-------+
| Super | Alt | Ctrl        | Shift       |    |    |       |       | Vol   | Vol | Left  | Right |
|       |     |             |             |    |    |       |       | Down  | Up  | Media | Media |
+-------|-----|-------------|-------------|----|----|-------|-------|-------|-----|-------|-------+
|       |     | [Opp LLock] | [Cur LLock] |    |    |       |       |       |     |       |       |
+-------|-----|-------------|-------------|----|----|-------|-------|-------|-----|-------|-------+
|       |     |             | HELD        |    |    | Media | Play  | Media |     |       |       |
|       |     |             |             |    |    | Stop  | Pause | Mute  |     |       |       |
+-------|-----|-------------|-------------|----|----|-------|-------|-------|-----|-------|-------+
```

## Navigation layer - function keys and navigation - accessed by ToNav - right hand only

```
+-------|-----|-------------|-------------|------|----|-------|------|----------|--------|-------|--------+
| c1    | c2  | c3          | c4          | c5   | c6 | c7    | c8   | c9       | c10    | c11   | c12    |
+=======|=====|=============|=============|======|====|=======|======|==========|========|=======|========+
|       |     |             |             |      |    |       | Redo | Paste    | Copy   | Cut   | Undo   |
+-------|-----|-------------|-------------|------|----|-------|------|----------|--------|-------|--------+
| Super | Alt | Ctrl        | Shift       |      |    |       | Left | Down     | Up     | Right | Caps   |
|       |     |             |             |      |    |       |      |          |        |       | Lock   |
+-------|-----|-------------|-------------|------|----|-------|------|----------|--------|-------|--------+
|       |     | [Opp LLock] | [Cur LLock] |      |    |       | Home | PageDown | PageUp | End   | Insert |
+-------|-----|-------------|-------------|------|----|-------|------|----------|--------|-------|--------+
|       |     |             |             | HELD |    | Enter | Bksp | Del      |        |       |        |
+-------|-----|-------------|-------------|------|----|-------|------|----------|--------|-------|--------+
```


## Mouse layer - - accessed by ToMouse - right hand only

```
+-------|-----|-------------|-------------|----|------|-------|-------|--------|-------|-------|--------+
| c1    | c2  | c3          | c4          | c5 | c6   | c7    | c8    | c9     | c10   | c11   | c12    |
+=======|=====|=============|=============|====|======|=======|=======|========|=======|=======|========+
|       |     |             |             |    |      |       | Redo  | Paste  | Copy  | Cut   | Undo   |
+-------|-----|-------------|-------------|----|------|-------|-------|--------|-------|-------|--------+
| Super | Alt | Ctrl        | Shift       |    |      |       | Left  | Down   | Up    | Right | Scroll |
|       |     |             |             |    |      |       | Mouse | Mouse  | Mouse | Mouse | Up     |
+-------|-----|-------------|-------------|----|------|-------|-------|--------|-------|-------|--------+
|       |     | [Opp LLock] | [Cur LLock] |    |      |       | Left  | Down   | Up    | Right | Scroll |
|       |     |             |             |    |      |       | Mouse | Mouse  | Mouse | Mouse | Down   |
|       |     |             |             |    |      |       | Wheel | Wheel  | Wheel | Wheel |        |
+-------|-----|-------------|-------------|----|------|-------|-------|--------|-------|-------|--------+
|       |     |             |             |    | HELD | Right | Left  | Middle |       |       |        |
|       |     |             |             |    |      | Click | Click | Click  |       |       |        |
+-------|-----|-------------|-------------|----|------|-------|-------|--------|-------|-------|--------+
```
