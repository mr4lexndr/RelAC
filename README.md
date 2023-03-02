![ReleaseVersion](https://img.shields.io/github/v/release/mr4lexndr/RelAC)
[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].


[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
# RelAC
HomeKit 2-channel Relay module with mains Switch Input based on the HomeSpan library. It is mainly intended to be used with mains voltage appliances controlled in parallel with the Home app and physical switch. It could be hidden e.g. behind a wall light switch.

![RelAC](https://github.com/mr4lexndr/RelAC/blob/main/assets/RelAC-transparent.png)

## Main Features
- Mains Supply 100-240 Vac
- Status LED and Control push button for easy configuration
- 2 latching relays for low power consumption and thermal emmisions
- 2 live inputs
- Small form factor to be hidden behind the wall light switch.
- Can be configured as single channel device to save cost
  
### Switching Relays
- High quality, low wear Panasonic ADW1203HLW  
- Switching Capacity 16A @ 277V AC  
- Contact material AgSnO2 to minimise arcing  


## User Integration with HomeSpan
Status LED and Control Button are attached to deafault pins for most of the boards. S1 Button is also used as boot button during programming
- LED `GPIO2`
- Button `GPIO0`

## Pinout
Pin assignment for relays and switch inputs. For single channel version only `RELAY 1` and `SWITCH 2` are used.

- RELAY 1
  -  on `GPIO27`
  - off `GPIO26`
- RELAY 2 
  - on `GPIO33`
  - off `GPIO32`
- MAINS INPUT
  - switch 1 `GPIO16`
  - switch 2 `GPIO13`



## To Do

- [ ] finish 3D printed case
- [ ] reduce footprint with next revision
- [ ] change layout of programming pins and add RTS support
