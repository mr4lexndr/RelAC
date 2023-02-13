![ReleaseVersion](https://img.shields.io/github/v/release/mr4lexndr/RelAC)
[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].


[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
# RelAC
 HomeKit 2-channel Relay module with mains Switch Input based on [HomeSpan](https://github.com/HomeSpan/HomeSpan) library. It is maily intended to be used with mains voltage appliances controlled in parrallel with Home app and physical switch. It could be hidden i.e. behind wall ligth switch.

![HomeBoard](https://github.com/mr4lexndr/HomeBoard/blob/main/assets/RelAC-transparent.png)

## Main Features
- Mains Supply 100-240 Vac
- Status LED and Control push button for easy configuration
- 2 latching relays for low power consumption and thermal emmisions
- 2 live inputs
- Small form factor to be hidden behind wall light switch.
 - Can be configured as single channel device to save cost


## User Integration with HomeSpan
Status LED and Control Button are attached to deafault pins for most of the boards. S1 Button is also used as boot button during programming
- LED - GPIO2
- Button - GPIO0

## PINOUT
Four channels can be configured per requiremnts. Specific sections 1-3 has been marked on PCB. Only one group from each section should be soldered based on selected funtion. Available options:

| COMPONENT         | GPIO |
| ---               | :---:| 
| **RELAY 1** set   | 27   | 
| **RELAY 1** reset | 26   |
| **RELAY 2** set   | 33   | 
| **RELAY 2** reset | 32   |
| **SWITCH 1**      | 16   | 
| **SWITCH 2**      | 13   |



## TO DO

- finish 3D printed case
- reduce footprint with next revision
