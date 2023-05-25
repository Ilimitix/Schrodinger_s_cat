# Schrodinger s cat



## Concept

It's a small Arduino sketch based on the liquidcrystal library, to display on a 16x2 LCD screen a cat in three different states, dead, alive or dead & alive. 

Designed to be integrated into a box -of shrodinger-, whose cover will operate a push button. 

- When the box is closed (button pushed), the screen displays the cat in a superimposed dead & alive state... but the box is closed so we can't see it. Unless you cheat by pressing the button, which also explains the concept. 

- When the box is opened (button released), the cat is displayed randomly dead or alive.

## Typeface

The liquidcrystal library offers the possibility of creating 8 personalized typeface. 

The challenge was therefore to be able to display the caht in three distinct states: dead, alive or dead&alive with 8 characters. 6 typefaces are needed to display a cute cat. The variation could then only be played on a single typeface, and that of the eyes and the muzzle would be perfect. 

Each typeface is encoded byte by byte, with a very satisfying pixel art side.

These characters are encoded as follows :

byte hg[8] = {B00000, B00000, B00010, B00101, B00100, B00110, B00111, B00010}; //top left

byte hm[8] = {B00000, B00000, B00000, B00000, B11111, B00000, B00000, B00000}; //top middle

byte hd[8] = {B00000, B00000, B01000, B10100, B00100, B01100, B11100, B01000}; //top right

byte bg[8] = {B00110, B00100, B00111, B00010, B00001, B00000, B00001, B00010}; //bottom left

byte bm1[8] = {B10001, B10001, B00100, B00000, B00000, B11111, B00100, B00000}; //bottom middle (1, 2, 3)

byte bm2[8] = {B10001, B11011, B10001, B00100, B00000, B11111, B00100, B00000};

byte bm3[8] = {B10001, B11001, B10000, B00100, B00000, B11111, B00100, B00000};

byte bd[8] = {B01100, B00100, B11100, B01000, B10000, B00000, B10000, B01000}; //bottom right


## Achievement

The LCD screen is quite small. 

The use of a small programmable card will allow integration inside a box. 

The push button must be fixed so as to be actuated by the cover. 

I made the choice to use a wooden box to be able to drill it and leave the USB socket visible. Thus, the box works when it is connected to a power supply (PC, charger).

## Improvements

I'm not sure replacing the button with a "non-cheatable" actuator improves the concept. Indeed, being able to "cheat" makes understanding the concept of Shrödinger's cat easier. 

I would have liked to be able to display a vial... maybe by making a dynamic display?

## Dedication

I designed this object for my cousin.
