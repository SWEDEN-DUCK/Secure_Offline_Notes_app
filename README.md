# Secure Offline Notes App

A simple offline note web app using **ESP32** and an **SD card module**.  

I used an **ESP32-C3 MINI**, but you can use any ESP32 as long as you use the correct connections.  
All your notes will be saved on the SD card in a text file named `Notes.txt`, so you can access them later on a dedicated offline computer.  

If you like this project, please give it a star so more people can find it, and feel free to check out my other projects.  

If you find any bugs or glitches, please let me know. Even better: if you fix it, explain how you did it so I can update the code and make everything work correctly.  

---

## How to Set Up
Important: Be careful to connect everything correctly so you don’t accidentally break anything.  
If the parts get very hot or you smell burning, unplug the device immediately and check your wiring.  

### ESP32-C3 MINI Wiring

| Micro SD Card Module | ESP32-C3 MINI |
|----------------------|---------------|
| GND                  | GND           |
| VCC                  | 3.3V          |
| SO                   | 8             |
| SI                   | 10            |
| SCK                  | 6             |
| CS                   | 5             |

---

Warning: Do not leave the device powered on for long periods of time.
