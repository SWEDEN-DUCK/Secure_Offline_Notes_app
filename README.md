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

<img width="462" height="433" alt="e1f3aab9-5bc8-4f89-b16e-d1c1df253d2b" src="https://github.com/user-attachments/assets/32020eb2-7e8c-49e3-918b-10fb9d801fbf" />
<img width="662" height="491" alt="3f44e8bd-621a-49c7-bf40-8462b8e7" src="https://github.com/user-attachments/assets/3b9a9ff4-6746-4423-8c38-6c80cf597e0b" />
<img width="2561" height="976" alt="0b50e2d6-0998-4a56-acaa-47104a19c1bf(1)" src="https://github.com/user-attachments/assets/a7bae5d9-a140-405d-b7e3-9115986157c5" />
