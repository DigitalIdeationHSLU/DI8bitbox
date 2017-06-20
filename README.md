# DI 8bitbox

"DI 8bitbox" - Digital Ideation Musterplatine zum 140 jährigen Bestehen der HSLU

## What is inside this repository?

* PCB EagleCad Files + Gerber production Files
* Firmware (Arduino Code source)
* Shell script to zip Gerber Files
* CAM File for Itead Studio

## Assembly

### Bills of materials

You'll need following parts in order to finish your board:

* 2 x 220R 0805 SMD resistors
* 1 x SOT23-3 NPN Transistor
* 2 x 1206 LEDs (preferably white, change resistor according to your colour)
* 1 x Atttiny 84 SMD Version
* 1 x Pogopin Sparkfun Connector ([Link](https://www.sparkfun.com/products/11591))
* 1 x optionally a tiny loudspeaker

### Soldering

With little soldering skills, you should be able to finish the board. Please be careful when mounting the LEDs and the Attiny, since orientation is important. See mounting diagram:

![Mounting Plan](https://github.com/DigitalIdeationHSLU/DI8bitbox/blob/master/documentation/MountingPlan.png)

## Install

### Flashing Firmware

Attach the Pogo-pin programmer to an Arduino or another AVR ISP-capable programming device. For the wiring see this photo:

![Pogo Pin Wiring](https://github.com/DigitalIdeationHSLU/DI8bitbox/blob/master/documentation/PogoPinWiring.jpg)

More infos here.

Once in place, prepare your Arduino by adding the Attiny to the list of boards. Here's a [HOWTO](http://highlowtech.org/?p=1695)

Make sure the Arduino settings are correct

![Arduino Settings](https://github.com/DigitalIdeationHSLU/DI8bitbox/blob/master/documentation/Arduino_Settings.png)

Press the Pogo pins gently onto the pads on the bottom side of the board. Again, orientation is important:

![Pogo Pin Upload](https://github.com/DigitalIdeationHSLU/DI8bitbox/blob/master/documentation/PogoPinUpload.jpg)

Hit the programming button within your Arduino sketch.

### Final preparation

Attach 3-5 Volts DC to the input pins where you'll find the battery icon. Make sure polarity is correct according to +/- signs. Solder the tiny loudspeaker on the other side of the board. You should hear sound coming out immediately.

## Run

Download either this [Android app](https://play.google.com/store/apps/details?id=org.jfedor.morsecode) for capturing sound or the [Morse Talk](https://play.google.com/store/apps/details?id=com.blueta.morsetransmitter&hl=fr) and hold it above one of the LEDs. You should be able to decrypt the message.

## Credits

* Created by Gordan Savičić & Michael Schürmann, Luzern 2017
