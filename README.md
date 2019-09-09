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

yes - the resistors ensure that not too much power gets sent to the point where the LED would blow

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**
-int led = 9 to int led = 11

**b. What is analogWrite()? How is that different than digitalWrite()?**
-analogwrite takes in 0-255, not just boolean

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

-no computation in the sense of having a microprocessor etc
-possibly 'computation' in the sense of needing to know which button is pressed corresponds to which 'color'/mode, though not sure if this processing occurs on the remote side or on the receiver side

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

-yes: IR sensor (transmitter) on one side that sends signals to IR receiver which is attached to the actual LED light strips, haptic sensors on other side for button feedback

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

-battery powered - doesn't appear to be any transformation.  The 'on/off' button would control power regulation for this, though it's not clear where this is located or how it's done from the circuitboard.  Since the power comes only from a single 3V battery, i.e. no variable power source, doesn't seem to be a need for something like a pentiometer to regulate current flow. Power should be a binary on or off, i.e. 0V or 3V. Things like brightness levels and different colors e.g. would affect the power level emitted from the actual light strips, but just from the remote side, this seems to be more boolean.

**d. Is information stored in your device? Where? How?**
-memory is stored somewhere in this whole setup, since the most recent memory state (color chose, brightness level, mode chose, power, etc.) is retained even when powered off.  I don't believe that this memory retention is actually stored on the remote - i have a suspicion it may be stored on the receiver side (i looked online and could not find any details about this).  If it is stored on the device, it may have to do with the two little golden squares on the board as can seen above?


### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**

### 3. Build your light!

**Make a video showing off your Frankenlight.**

**Include any schematics or photos in your lab write-up.**
