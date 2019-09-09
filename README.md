# IDD-Fa18-Lab1: Blink!

**A lab report by Alana Crognale**

## Part A. Set Up a Breadboard

![Breadboard 1](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/breadboard%201.png)

![Breadboard 2](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/breadboard%202.png)


## Part B. Manually Blink a LED

**a. What color stripes are on a 220 Ohm resistor?**

red (2), red (2), black (0), black (*1), brown (+-1%)
 
**b. What do you have to do to light your LED?**

Push the button to complete the circuit

## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**

No changes needed - the preloaded 'Blink' program already had the proper set up to compile and upload.

**b. What line(s) of code do you need to change to change the rate of blinking?**

The two 'delay(1000)' lines - increasing the numerical parameter slows the rate of blinking, and decreasing the numerical parameters speeds up the rate of blinking.

**c. What circuit element would you want to add to protect the board and external LED?**

A resistor to limit the amount of power that can enter the board/LED, preventing a potential short.
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

~10 ms - at slightly higher rates, I cannot see explicit blinking but can still see flickering, whereas at 10 ms or lower I cannot perceive any LED changes whatsoever.

To prove to yourself that the LED is blinking, you could:
-take a slow motion camera video
-have the arduino program print a statement out (e.g. 'ON' and 'OFF') between every blink
-include a counter parameter such that after every say 50-100 unpercievable blinks, turn the led off, add a delay, and then turn the led back on, resetting the counter parameter and the 50-100 blink cycle

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

[Blink Your Way](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/Blink_your_way.ino)


![Blink_Your_Way](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/IMG_0423.MOV)

### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

![External LED Blink](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/IMG_0424.MOV)


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**

Yes - the 220 Ω resistor ensures that not too high a level of current will get sent to the LED to the point where the LED could spark/explode, regarldess of where the potentiometer is turned.

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

Change 'int led = 9' to 'int led = 11'.

**b. What is analogWrite()? How is that different than digitalWrite()?**

Analogwrite() takes in an integer value ranging from 0-255, allowing you to send variable voltage values.  DigitalWrite takes in only boolean 'HIGH' and 'LOW', sending to the specified pin only an on (typically 5V) or off signal.

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

44-Keys IR Remote Controller for Led Light Strips

![frankenlight 1](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/frankenlight%201.png)

![frankenlight 2](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/frankenlight%202.png)

![frankenlight 3](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/frankenlight%203.png)

![frankenlight 4](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/frankenlight%204.png)

![frankenlight 5](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/frankenlight%205.png)


**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

I believe the black dot in the upper portion of the device is a microprocessor/CPU which would be used to retain information related to programming the LED light strips, i.e. color, brightness, speed, mode, etc.

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

Yes - there is an IR sensor (transmitter) on one side that sends signals to the IR receiver which is attached to the actual LED light strips and powered via a wall plug.  The other side of the remote has haptic sensors for button feedback when pressed.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

The remote is battery powered, and there doesn't appear to be any transformation of power, since the power comes only from a single 3V battery i.e. no variable power source (power should be a binary on or off, either 3V or 0V), so there doesn't seem to be a need for something like a potentiometer to regulate current flow.  Things like brightness levels and different colors, for example, would affect the power level emitted from the actual LED light strips, but as far as the power on the remote/transmitter side, there should only be one mode for on and one for off.  The 'on/off' button would regulate the power level for this, though it's not clear exactly where this is located on the circuitboard, or if it's controlled on the software side via programming the microprocessor).  

**d. Is information stored in your device? Where? How?**

Yes - memory is stored somewhere in this whole device setup, since the most recent memory state (color choice, brightness level, mode choice, etc.) is retained even when powered off.  I am not sure whether this memory retention is actually stored on the remote or whether it is stored on the receiver side (I was unable to find specific details of how this system works online).  If the memory is stored on the remote, it is possible it is located on the two small gold colored squares on the board as seen from the above pictures, or it is possible it is just stored as part of the microprocessor programming and cannot be physically seen.

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

Initially, I wanted to see if I could 'hijack' the IR transmitter/LED that already exists on the board; however, I ran into a few issues with this:  Firstly, when I took my device apart, I realized that I had accidentally snapped some portions of the circuitboard, so it is very likely that some of the more vital components controlling the IR transmitter were damaged.  Next, I thought I would try just lighting up the LED on the board, ignoring any IR transmistter aspects.  When I first started to test this, connecting the two soldered points of contact on the LED to power, at first nothing happened and then after a few seconds I heard what sounded like a spark, and then I realized that I had no resistors to prevent unlimited power flow to the LED.  So, my suspcicion is that I accidentally had blown the fuse inside this LED.  Alternatively, I wondered whether it is also possible that this LED is designed to not to light up if the IR transmitter portion of it is also not in use.  Given these constraints, I set up a design so that the devices battery holding setup would be used to light up and power an external LED, adding a push button so that the LED only lights when the button is pressed.

### 3. Build your light!

**Make a video showing off your Frankenlight.**

![External LED Blink](https://github.com/AlanaCrognale/IDD-Fa18-Lab1/blob/master/IMG_0448.MOV)

