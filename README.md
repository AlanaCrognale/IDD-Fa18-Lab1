# IDD-Fa18-Lab1: Blink!

**A lab report by Alana Crognale**

## Part A. Set Up a Breadboard

[insert a photo of your breadboard setup here]


## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**

-220/270 ohm resistor
-red red, black, black, brown
 
**b. What do you have to do to light your LED?**
-push button


## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**
-none (preloaded)

**b. What line(s) of code do you need to change to change the rate of blinking?**
the two delay(1000) lines

**c. What circuit element would you want to add to protect the board and external LED?**
-resistor
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**
~10 ms (less than that, can't see explicit blinking but can still see flickering)
could take a slow motion camera video or have the arduino program print a statement out between every blink, or have a counter and after say every 10 'loops' turn the led off 

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

[link to your video here; feel free to upload to youtube and just paste in a link here]


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
