# LC_neoPixel
**Extends Adafruit's NeoPixel library to allow use with the LC_baseTools colorObj class.**  

This allows passing colorObj to and from Adafruit NeoPixels. It also includes grouping of NeoPixles into independently code-able groups. Multiple groups can be run from a single output pin.

**Depends on**  
[Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
[LC_baseTools](https://github.com/leftCoast/LC_baseTools)


**What is it? What can it do for me?**  
This library allows setting and retereving NeoPixel colors using our colorObj class. Shifting a strings of pixels left or right and to rolling rings of pixels clockwise or counter clockwise. (Great for goggles.)

The included chainPixel class allows groups of pixels to be coded independantly from each other, while running off of a single processor pin.


