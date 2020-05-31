# LC_neoPixel
Extends Adafruit's NeoPixel library to allow use with our colorObj class.

This allows passing colorObj to and from Adafruit NeoPixels. It also includes grouping of NeoPixles into independently code-able groups. Multiple groups can be run from a single output pin.

**Depends on**  
[Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
[LC_baseTools](https://github.com/leftCoast/LC_baseTools)


**What is it? What can it do for me?**  
The founding idea behind this library is to allow setting NeoPixel colors from our colorObj(s). This also includes reading the NeoPixel colors back into our colorObj(s). This in itself opens up NeoPixles to a variety of color Operations supplied by the colorObj class.

On top of this is the ability to shift a line of pixels left or right. Also to roll rings of pixels clockwise or counter clockwise. (Great for goggles.)
