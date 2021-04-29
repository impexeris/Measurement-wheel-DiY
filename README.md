# Measurement-wheel-DiY
This project is originally by Mirko Pavleski (https://create.arduino.cc/projecthub/mircemk/diy-simple-measuring-wheel-with-rotary-encoder-12073d?f=1)
I needed to measure how much perimeter wire I would need for the lawn mover robot. So I have repeated it and tweaked it to my liking:
Added a measuremets reset pushbutton switch which is by default open and connects D4 to ground. I have also tweaked the code to change measurements from cm to m. And added some interactivity in terms of messages during the process.
This repository is in case someone can benefit from what changes I have made.

One notice! if  the encoder you have is already on the small PCB (popular item on eBay etc.), then be sure to remove at leaset one of smd resistors - usually there are two of them, because otherwise the device will not function as intended... 

Here's the video how the user interface looks like. https://youtu.be/HWPHcW_SULs
By the way it is my D.i.Y. arduino uno analog, but the schematics and code is valid for the Atmega328P based boards like Arduino nano or Arduino UNO
